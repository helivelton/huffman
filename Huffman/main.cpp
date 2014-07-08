#include <QDebug>
#include <fileprocessor.h>
#include <huffcompactor.h>
#include <hufftree.h>
#include <QByteArray>

QString representBitArray(QBitArray * array) {
    QString string;

    for (int i = 0; i < array->size(); i++) {
        string.append(array->at(i) ? '1' : '0');
    }

    return string;
}

int main(int argc, char *argv[])
{

    HuffCompactor * compactor = new HuffCompactor();

  //  QBitArray * compacted =  compactor->compact("/home/paulinha/Downloads/teste3.txt");

    QBitArray * test = compactor->intToBits(10, 2);
    QString string;


    qDebug() << "size-> " << test->size();
    for (int i = 0; i < test->size(); i++) {
        string.append(test->at(i) ? '1' : '0');
    }

    qDebug() << "result -> " << string;


    QBitArray * q = new QBitArray();
    q->resize(3);
    q->setBit(0,1);
    q->setBit(1,0);
    q->setBit(2,0);

    qDebug() << "result 2 -> " << compactor->bitsToInt(q);


}
