#include "huffcompactor.h"
#include "fileprocessor.h"
#include "hufftree.h"
#include <QMap>
#include <QBitArray>
#include <QString>
#include <math.h>

HuffCompactor::HuffCompactor()
{
}

QBitArray * HuffCompactor::intToBits(int integer, int numBits){
    QBitArray * bitArray = new QBitArray();
    int count = 0;

    do {
        count++;

        int mod = integer % 2;
        integer = integer / 2;

        bitArray->resize(count);
        bitArray->setBit(count - 1, mod == 0 ? false : true);

    } while(integer > 0);

    if(bitArray->size() != numBits){
        int size = bitArray->size();
        bitArray->resize(numBits);
        for(int i = size; i < numBits; i++){
            bitArray->setBit(i, 0);
        }
    }

    reverse(bitArray);

    return bitArray;
}

int HuffCompactor::bitsToInt(QBitArray *bits)
{
    reverse(bits);
    int integer = 0;
    qDebug() << "tetse q " << bits->size();
    for(int i = bits->size()-1; i >= 0; i--){
        qDebug() << "kdjs -- " << bits->at(i);
        integer+= ((int)bits->at(i)) * pow(2,i);
    }
    return integer;
}

QBitArray * HuffCompactor::reverse(QBitArray *bitArray){
    bool aux;
    for(int i = 0; i < bitArray->size()/2; i++){
        aux = bitArray->at(bitArray->size()-1-i);
        bitArray->setBit(bitArray->size()-1-i, bitArray->at(i));
        bitArray->setBit(i, aux);
    }
    return bitArray;
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
