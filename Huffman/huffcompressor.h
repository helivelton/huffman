#ifndef HUFFCOMPRESSOR_H
#define HUFFCOMPRESSOR_H

#include <QBitArray>
#include <QByteArray>
#include <QString>

class HuffCompressor
{
public:
    HuffCompressor();
    //compacta um arquivo
    void compress(QString filePath);
    //descompacta um arquivo
    void uncompress(QString filePath);


    //metodos auxilixares
    QBitArray * mergeQBitArray(QBitArray * bitArray1, QBitArray * bitArray2);
    QBitArray * intToBits(int integer, int numBits);
    int bitsToInt(QBitArray * bits);
    QBitArray * reverse(QBitArray * bitArray);
    QByteArray * bitArrayToByteArray(QBitArray * bitarray);
    QByteArray * QbitArrayToQByteArray(QBitArray * bits);
    QBitArray * QbyteArrayToQBitArray(QByteArray * bytes);
    QBitArray * QbyteArrayToQBitArray(QByteArray bytes);
};

#endif // HUFFCOMPRESSOR_H
