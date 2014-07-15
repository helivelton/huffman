#include "huffcompressor.h"
#include "fileprocessor.h"
#include "hufftree.h"
#include <QMap>
#include <QBitArray>
#include <QString>
#include <math.h>
#include <QFileInfo>

HuffCompressor::HuffCompressor()
{
}

//Converte de QByteArray para QBitArray
QBitArray * HuffCompressor::QbyteArrayToQBitArray(QByteArray * bytes) {

    QBitArray * bits = new QBitArray();
    bits->resize(bytes->count()*8);

    for(int i=0; i<bytes->count(); ++i)
        for(int b=0; b<8; ++b)
        {
            bits->setBit(i*8+b, bytes->at(i)&(1<<b));
        }

    return bits;
}

//Converte de QBitArray para QbyteArray
QByteArray * HuffCompressor::QbitArrayToQByteArray(QBitArray * bits) {
    QByteArray * bytes = new QByteArray();

    if((bits->size() % 8) == 0)
    {
        bytes->resize(bits->size()/8);
    }else
    {
        bytes->resize(bits->size()/8 + 1);
    }

    bytes->fill(0);

    for(int b = 0; b < bits->count(); ++b)
    {
        bytes->operator [](b/8) = ( bytes->at(b/8) | ((bits->operator [](b)? 1:0)<<(7-(b%8))));
    }

    return bytes;

}

QBitArray * HuffCompressor::QbyteArrayToQBitArray(QByteArray bytes) {

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


QBitArray * HuffCompressor::mergeQBitArray(QBitArray * bitArray1, QBitArray * bitArray2)
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

QBitArray * HuffCompressor::intToBits(int integer, int numBits){
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

int HuffCompressor::bitsToInt(QBitArray *bits)
{
    QBitArray * reversed = reverse(bits);
    int integer = 0;

    for(int i = reversed->size()-1; i >= 0; i--){

        integer+= ((int)reversed->at(i)) * pow(2,i);
    }
    return integer;
}

//inverte o array
QBitArray * HuffCompressor::reverse(QBitArray *bitArray){
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

//comprime o arquivo
void HuffCompressor::compress(QString from, QString to)
{
    FileProcessor fp(from);
    int * arr = fp.calculateFrequency();
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

    QByteArray * repr =  arvore->representation();
    QBitArray * code = new QBitArray();

    int index1 = 0;
    for(int i = 0; i < fileArray.size(); i++)
    {
        unsigned char ch = fileArray.at(i);
        QBitArray * bitArr = bitArray[ch];

        code->resize(code->size() + bitArr->size());
        for (int j = 0; j < bitArr->size(); ++j)
        {
            code->setBit(index1++, bitArr->at(j));
        }
    }

    int garbSize = 8 - code->size() % 8;

    QBitArray * garbageSize = intToBits(garbSize,3);
    QBitArray * treeSize = intToBits(repr->size(),13);
    QBitArray * fileNameSizeBits = intToBits(fp.fileName().size(),8);

    QBitArray * fileInBits = mergeQBitArray(garbageSize,treeSize);
    fileInBits = mergeQBitArray(fileInBits,fileNameSizeBits);

    QByteArray * fileInBytes = QbitArrayToQByteArray(fileInBits);

    QByteArray * codeInBytes = QbitArrayToQByteArray(code);

    //QChar::fromAscii
    QFile file(to);

    file.open(QIODevice::WriteOnly);


    for(int i =0;i<fileInBytes->size();i++)
    {
        file.putChar(fileInBytes->at(i));

    }

    QByteArray fileName;

    fileName.append(fp.fileName());

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

    file.close();

    qDebug() << "Compactado :D";
}

void HuffCompressor::uncompress(QString from, QString to)

{

    QFile file(from);


    file.open(QIODevice::ReadOnly);


    QByteArray byteArray = file.readAll();


    QBitArray * bitArray = QbyteArrayToQBitArray(byteArray);


    QBitArray * garbSize = new QBitArray();

    QBitArray * treeSize = new QBitArray();

    QBitArray * nameSize = new QBitArray();


    garbSize->resize(3);

    treeSize->resize(13);

    nameSize->resize(8);

    int startIndex = 0;

    for(int i = 0; i < 3; i++)

    {
        garbSize->setBit(i, bitArray->at(startIndex++));
    }


    for (int i = 0; i < 13; i++) {

        treeSize->setBit(i, bitArray->at(startIndex++));
    }


    for (int i = 0; i < 8; i++) {

        nameSize->setBit(i, bitArray->at(startIndex++));
    }

    int garbageSize = this->bitsToInt(garbSize);

    int treeSizeInt = this->bitsToInt(treeSize);

    int nameSizeInt = this->bitsToInt(nameSize);


    QByteArray * nameArray = new QByteArray();

    for (int i = 0; i < nameSizeInt; i++) {

        QBitArray * temp = new QBitArray();

        temp->resize(8);


        for (int i = 0; i < 8; i++) {

            temp->setBit(i, bitArray->at(startIndex++));

        }

        nameArray->append((char) this->bitsToInt(temp));

        delete temp;

    }


    QByteArray * treeArray = new QByteArray();

    for (int i = 0; i < treeSizeInt; i++) {

        QBitArray * temp = new QBitArray();

        temp->resize(8);


        for (int i = 0; i < 8; i++) {

            temp->setBit(i, bitArray->at(startIndex++));

        }

        treeArray->append((char) this->bitsToInt(temp));

        delete temp;

    }


    QBitArray * codification = new QBitArray(bitArray->size() - startIndex - garbageSize);

    int j = 0;

    for (int i = startIndex; i < bitArray->size() - garbageSize; i++) {

        codification->setBit(j++, bitArray->at(i));

    }

    QByteArray * representation = new QByteArray();
    representation->resize(treeArray->size());

    for(int i=0; i<treeArray->size(); i++)
    {
        representation->operator [](i) = treeArray->at(i);
    }

    HuffNode * root = new HuffNode();
    HuffNode * current = root;

    if(representation->size()==1)
    {
        root->setCharacter(representation->at(0));
        root->setIsLeaf(true);
    }else for (int i = 0; i < representation->size(); i++) {
        if(representation->at(i) == '(') {
            HuffNode * internalNode = new HuffNode();
            internalNode->setCharacter(representation->at(i));
            internalNode->setIsLeaf(false);
            internalNode->setParent(current);

            if(!current->hasLeft) {
                current->setLeftChild(internalNode);
                current->hasLeft = true;
            } else {
                current->setRightChild(internalNode);
                current->hasRight = true;
            }

            current = internalNode;
        } else if(representation->at(i) != ')') {

            if (representation->at(i) == 0) {
                i = i + 1;
            }

            HuffNode * leaf = new HuffNode();
            leaf->setCharacter(representation->at(i));
            leaf->setIsLeaf(true);
            leaf->setParent(current);

            if(!current->hasLeft) {
                current->setLeftChild(leaf);
                current->hasLeft = true;
            }else {
                    current->setRightChild(leaf);
                    current->hasRight = true;
                }

        } else while(current->hasLeft & current->hasRight)
            {
                if (!current->getParent()) break;
                current = current->getParent();
            }
        }

    HuffTree * tree = new HuffTree();
    tree->setRoot(root);
    tree->linkTree();


    QBitArray *repr[256];

    for (int i = 0; i < 256; i++) {
        repr[i] = NULL;

        if (tree->getRoot()->isChild((char)i)) {
            repr[i] = tree->codification(i);
        }
    }

    QByteArray toSave;

    int counter = 0;

    int bytes = 0;
    while (codification->size() > counter) {
        for (int i = 0; i < 256; i++) {

            if (repr[i]) {
                QBitArray * tmp = repr[i];

                bool match = true;

                if ((counter + tmp->size()) > codification->size()) {
                    continue;
                }

                for (int k = 0; k < tmp->size(); k++) {
                    if(codification->at(counter + k) != tmp->at(k)) {
                        match = false;
                        break;
                    }
                }

                if (match) {
                    bytes++;
                    counter += tmp->size();
                    toSave.append((char) i);

                    if (bytes % (100 * 1024) == 0) {
                        qDebug() << "descompactando ... "<< bytes / 1024 << "KB";
                    }
                }

            }

        }

    }

    QFile out(to);

    out.open(QIODevice::WriteOnly);

    for (int i =0; i < toSave.size(); i++) {
        out.putChar(toSave.at(i));
    }

    out.close();

    qDebug() << "Descompactado :D";
}
