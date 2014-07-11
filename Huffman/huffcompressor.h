#ifndef HUFFCOMPRESSOR_H
#define HUFFCOMPRESSOR_H

#include <QBitArray>
#include <QByteArray>
#include <QString>

class HuffCompressor
{
public:
    HuffCompressor();
    HuffCompressor(QString filePath, QString pathOutFile, QString directory);
    //compacta um arquivo
    void compress();
    //descompacta um arquivo
    void uncompress();


    //metodos auxilixares
    QBitArray * mergeQBitArray(QBitArray * bitArray1, QBitArray * bitArray2);
    QBitArray * intToBits(int integer, int numBits);
    int bitsToInt(QBitArray * bits);
    QBitArray * reverse(QBitArray * bitArray);
    QByteArray * bitArrayToByteArray(QBitArray * bitarray);
    QByteArray * QbitArrayToQByteArray(QBitArray * bits);
    QBitArray * QbyteArrayToQBitArray(QByteArray * bytes);
    QBitArray * QbyteArrayToQBitArray(QByteArray bytes);

private:
    QString m_filePath;
    QString m_pathOutFile;
    QString m_directory;
};

#endif // HUFFCOMPRESSOR_H
