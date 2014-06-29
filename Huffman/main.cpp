#include <QDebug>
#include <fileprocessor.h>
#include <hufftree.h>

int main(int argc, char *argv[])
{


    FileProcessor fp("C:/Users/Helivelton/UFAL/ESTRUTURA/teste3.txt");
    int * arr = fp.getFrequency();

    for(int i = 0; i < 256; i++){
        char ch = i;
        qDebug() << "'"<< ch << "'" << " <---> " << arr[i];
    }

    HuffTree *arvore = new HuffTree(arr);

    HuffNode * root = arvore->buildTree();

    arvore->printTree();

}
