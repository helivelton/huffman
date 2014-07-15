#include <QDebug>
#include <fileprocessor.h>
#include <huffcompressor.h>
#include <hufftree.h>
#include <QByteArray>
#include <QString>
#include <QStringList>
#include <QApplication>
#include <userinterface.h>

void man()
{
    qDebug()<< "---- COMPRESSOR DE HUFFMAN ----" << endl << endl;
    qDebug()<<"-> Comprime o arquivo para um arquivo .huff com o nome especificado: ";
    qDebug()<< "    huffman -c arquivo_origem.x -o arquivo_de_saida.huff" << endl;
    qDebug()<<"-> Comprime o arquivo para o arquivo arquivo_origem.huff: ";
    qDebug()<<"    huffman -c arquivo_origem.x" << endl;
    qDebug()<<"-> Descomprime um arquivo .huff na pasta local com o nome original: ";
    qDebug()<<"    huffman arquivo.huff" << endl;
    qDebug()<<"-> Descomprime um arquivo .huff na no diretorio especificado mantendo o nome original do arquivo: ";
    qDebug()<<"    huffman arquivoCompactado.huff -d diretorio" << endl << endl;
    qDebug()<< "-------------------------------";
}

int gui(int argc, char *argv[])
{
    QApplication app(argc,argv);
    UserInterface userInterface;
    userInterface.show();

    return app.exec();
}

int main(int argc, char *argv[])
{
    gui(argc,argv);
    HuffCompressor * compressor = new HuffCompressor();
    //compressor->compress("/home/paulinha/Downloads/tela.png", "/home/paulinha/Desktop/tela.huff");
    compressor->uncompress("/home/paulinha/Desktop/tela.huff", "/home/paulinha/Desktop/tela.png");
}
