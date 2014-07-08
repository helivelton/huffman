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

    QBitArray * intToBits(int integer, int numBits);
    int bitsToInt(QBitArray * bits);
    QBitArray * reverse(QBitArray * bitArray);
};

#endif // HUFFCOMPACTOR_H
