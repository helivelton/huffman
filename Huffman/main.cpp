#include <QDebug>
#include <fileprocessor.h>
#include <hufftree.h>
#include <QByteArray>

int main(int argc, char *argv[])
{


    //FileProcessor fp("C:/Users/Helivelton/UFAL/ESTRUTURA/teste3.txt");

    FileProcessor fp("/home/paulinha/Downloads/teste3.txt");
    int * arr = fp.getFrequency();


    HuffTree *arvore = new HuffTree(arr);
    arvore->buildTree();

    qDebug() << "testando";

    for(int i = 0; i < 256; i++){
        char ch = i;
        if (arr[i] > 0) {
            qDebug() << "'"<< ch << "'" << " <---> " << arr[i] << " cod --> " << arvore->codification(ch)->data();
        }
    }


    //arvore->printTree();

}
