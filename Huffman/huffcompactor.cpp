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



QBitArray * HuffCompactor::QbyteArrayToQBitArray(QByteArray * bytes) {

    QBitArray * bits = new QBitArray();
    bits->resize(bytes->count()*8);
    // Convert from QByteArray to QBitArray
    for(int i=0; i<bytes->count(); ++i)
        for(int b=0; b<8; ++b)
        {
            bits->setBit(i*8+b, bytes->at(i)&(1<<b));
        }

    return bits;
}

QBitArray * HuffCompactor::QbyteArrayToQBitArray(QByteArray bytes) {

    QBitArray * bits = new QBitArray();
    bits->resize(bytes.count()*8);
    // Convert from QByteArray to QBitArray
    for(int i=0; i<bytes.count(); ++i)
        for(int b=0; b<8; ++b)
        {
            int desloc = b;

            while(desloc>7)
            {
                desloc-=8;
            }

            bits->setBit(i*8+b, bytes.at(i)&(1<<7-desloc));
        }

    return bits;
}

QByteArray * HuffCompactor::QbitArrayToQByteArray(QBitArray * bits) {
    QByteArray * bytes = new QByteArray();

    if((bits->size()%8)==0)
    {
        bytes->resize(bits->size()/8);

    }else
    {
        bytes->resize(bits->size()/8 + 1);
    }


    // Convert from QBitArray to QByteArray

    bytes->fill(0);

    for(int b = 0; b < bits->count(); ++b)
    {

//        int desloc = b;


//        double percent = (100.0*b)/bits->count();
//        qDebug() << percent <<'%';
//        qDebug() << b ;
//        while(desloc>7)
//        {
//            desloc-=8;
//        }
        bytes->operator [](b/8) = ( bytes->at(b/8) | ((bits->operator [](b)? 1:0)<<(7-(b%8))));
    }

    return bytes;

}


QBitArray * HuffCompactor::mergeQBitArray(QBitArray * bitArray1, QBitArray * bitArray2)
{
    QBitArray * merged = new QBitArray();
    int size = bitArray1->size();
    merged->resize(size+bitArray2->size());


    for(int i=0; i<bitArray1->size();i++)
    {
        merged->setBit(i,bitArray1->at(i));
    }

    for(int i=0; i< bitArray2->size(); i++)
    {
        merged->setBit(size+i,bitArray2->at(i));
    }

    return merged;
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

    bitArray = reverse(bitArray);

    return bitArray;
}

int HuffCompactor::bitsToInt(QBitArray *bits)
{
    QBitArray * reversed = reverse(bits);
    int integer = 0;

    for(int i = reversed->size()-1; i >= 0; i--){

        integer+= ((int)reversed->at(i)) * pow(2,i);
    }
    return integer;
}

//QBitArray * HuffCompactor::reverse(QBitArray *bitArray){
//    bool aux;
//    for(int i = 0; i < bitArray->size()/2; i++){
//        aux = bitArray->at(bitArray->size()-1-i);
//        bitArray->setBit(bitArray->size()-1-i, bitArray->at(i));
//        bitArray->setBit(i, aux);
//    }
//    return bitArray;
//}


QBitArray * HuffCompactor::reverse(QBitArray *bitArray){
    bool aux;
    QBitArray * reversed = new QBitArray();
    reversed->resize(bitArray->size());
    *reversed = *bitArray;

    for(int i = 0; i < reversed->size()/2; i++){
        aux = reversed->at(reversed->size()-1-i);
        reversed->setBit(reversed->size()-1-i, reversed->at(i));
        reversed->setBit(i, aux);
    }
    return reversed;
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
    int initialSize = 3 + fp.fileName().size() + repr->size() + (code->size()/8) + (code->size() % 8);





    QBitArray * garbageSize = intToBits(garbSize,3);
    QBitArray * treeSize = intToBits(repr->size(),13);
    QBitArray * fileNameSizeBits = intToBits(fp.fileName().size(),8);

    QBitArray * fileInBits = mergeQBitArray(garbageSize,treeSize);
    fileInBits = mergeQBitArray(fileInBits,fileNameSizeBits);

    QByteArray * fileInBytes = QbitArrayToQByteArray(fileInBits);



        char test = fileInBytes->operator [](0);
        QChar qcharT(test);

        qDebug()<< fileInBytes->operator [](0);
        qDebug()<< qcharT.unicode();

        qDebug() <<garbSize;
        qDebug() <<repr->size();

    for(int i=0; i<fileInBits->size();i++)
    {
        qDebug() << fileInBits->operator [](i);
    }

    QByteArray * codeInBytes = QbitArrayToQByteArray(code);

//        QChar::fromAscii
    QFile file("C:/Users/Helivelton/UFAL/ESTRUTURA/teste3.huff");
    file.open(QIODevice::WriteOnly | QIODevice::Text);


    for(int i =0;i<fileInBytes->size();i++)
    {
        file.putChar(fileInBytes->at(i));

    }

    QByteArray fileName;
    fileName.append(fp.fileName());


    for(int i=0; i < fileName.size(); i++)
    {
        qDebug() << fileName.at(i);
    }

    //    QTextStream fout(&file);
    //    fout << fp.fileName();


    for(int i =0;i<fileName.size();i++)
    {
        file.putChar(fileName.at(i));
    }

    for(int i=0; i < repr->size(); i++)
    {
        file.putChar(repr->at(i));

    }



    for(int i=0; i < codeInBytes->size(); i++)
    {
        file.putChar(codeInBytes->at(i));
    }

    //file.close();



    return NULL;

}
