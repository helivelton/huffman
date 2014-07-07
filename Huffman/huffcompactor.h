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
};

#endif // HUFFCOMPACTOR_H
