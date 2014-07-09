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

    QBitArray * compacted =  compactor->compact("C:/Users/Helivelton/UFAL/ESTRUTURA/teste4.txt");


}
