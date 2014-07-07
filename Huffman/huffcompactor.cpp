#include "huffcompactor.h"
#include "fileprocessor.h"
#include "hufftree.h"
#include <QMap>
#include <QBitArray>
#include <QString>

HuffCompactor::HuffCompactor()
{
}

QBitArray * HuffCompactor::compact(QString filePath)
{
    FileProcessor fp(filePath);
    int * arr = fp.getFrequency();
    QByteArray  fileArray = fp.byteArray();
    QBitArray * bitArray[256];

    HuffTree * arvore = new HuffTree(arr);
    arvore->buildTree();

    for (int i = 0; i < 256; i++)
    {
        bitArray[i] = NULL;

        if (arr[i] > 0)
        {
            bitArray[(unsigned char)i] = arvore->codification(i);
        }
    }

    for (int i = 0; i < 256; i++) {
        QString string("");
        if (bitArray[i] != NULL) {
            QBitArray * array = bitArray[i];
            for (int j = 0; j < array->size(); j++) {
                string.append(array->at(j) ? '1' : '0');
            }

            qDebug() << (char) i << ". " << string;
        }

    }

    QByteArray * repr =  arvore->representation();
    for (int i = 0; i < repr->size(); i++) {
        printf("%c", repr->at(i));
    }
    printf("\n");

    QBitArray * code = new QBitArray();

    for(int i = 0; i < fileArray.size(); i++)
    {
        unsigned char ch = fileArray.at(i);
        QBitArray * bitArr = bitArray[ch];

        int j = code->size();
        code->resize(code->size() + bitArr->size());
        for (int k = j; k < code->size(); ++k)
        {
            code->setBit(j, bitArr->at(k - j));
        }
    }


    int garbSize = 8 - code->size() % 8;

    //ver tudo q precisa ser salvo no arquivo compactado, falta isso aqui abaixo
    int initialSize = garbSize + 13 + 8 + fp.fileName().size() + repr->size() + code->size() + (code->size() % 8);



    qDebug() << "file size --> " << fileArray.size();
    qDebug() << "code size --> " << code->size()/8;
    qDebug() << "file coded size -->" << initialSize/8;

    return NULL;

}
