#include <QDebug>
#include <fileprocessor.h>
#include <huffcompressor.h>
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

    HuffCompressor * compressor = new HuffCompressor();

    compressor->compress("/home/anapaula/Downloads/manutencao.doc");

    compressor->uncompress("/home/anapaula/compactado.huff");
}
