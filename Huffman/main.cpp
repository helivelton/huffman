#include <QDebug>
#include <fileprocessor.h>
#include <huffcompressor.h>
#include <hufftree.h>
#include <QByteArray>
#include <QString>
#include <QStringList>

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

int main(int argc, char *argv[])
{



    if(argc >= 2 && argc <= 5){

        QString fileName, directory, compressed = "";

        if(argc == 5)
        {
            if (argv[1][0] == '-' && argv[1][1] == 'c' && argv[3][0] == '-' && argv && argv[3][1] == 'o'){
                fileName = argv[2];
                compressed = argv[4];
                HuffCompressor * compressor = new HuffCompressor(fileName, compressed, directory);
                compressor->compress();
            } else
            {
                man();
            }

        }else if(argc == 4)
        {
            if (argv[2][0] == '-' && argv[2][1] == 'd'){
                fileName = argv[1];
                directory = argv[3];
                HuffCompressor * compressor = new HuffCompressor(fileName, compressed, directory);
                compressor->uncompress();
            }else
            {
                man();
            }

        }else if(argc == 3)
        {
            if (argv[1][0] == '-' && argv[1][1] == 'c')
            {
                fileName == argv[2];
                QStringList list = fileName.split(".");
                compressed.append(list.at(0));
                compressed.append(".huff");
                HuffCompressor * compressor = new HuffCompressor(fileName, compressed, directory);
                compressor->compress();
            }else
            {
                man();
            }
        }else if(argc == 2)
        {
            fileName = argv[1];
            HuffCompressor * compressor = new HuffCompressor(fileName, compressed, directory);
            compressor->uncompress();
        }else {
            man();
        }
    }


    //HuffCompressor * compressor = new HuffCompressor();

    // compressor->compress("/home/paulinha/Downloads/tela-preta.png");

    //compressor->uncompress("/home/paulinha/compactado.huff");

}
