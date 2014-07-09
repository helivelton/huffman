#ifndef HUFFCOMPACTOR_H
#define HUFFCOMPACTOR_H

#include <QBitArray>
#include <QByteArray>
#include <QString>

class HuffCompactor
{
public:
    HuffCompactor();
    QBitArray * compact(QString filePath);

    QBitArray * mergeQBitArray(QBitArray * bitArray1, QBitArray * bitArray2);
    QBitArray * intToBits(int integer, int numBits);
    int bitsToInt(QBitArray * bits);
    QBitArray * reverse(QBitArray * bitArray);
    QByteArray * bitArrayToByteArray(QBitArray * bitarray);
    QByteArray * QbitArrayToQByteArray(QBitArray * bits);
    QBitArray * QbyteArrayToQBitArray(QByteArray * bytes);
    QBitArray * QbyteArrayToQBitArray(QByteArray bytes);
};

#endif // HUFFCOMPACTOR_H
