#ifndef HUFFTREE_H
#define HUFFTREE_H
#include <huffnode.h>
#include <QDebug>
#include <QList>
#include <QByteArray>
#include <QBitArray>

class HuffTree
{
public:
    HuffTree();
    HuffTree(int * frequencyArray);
    //monta a arvore
    HuffNode * buildTree();
    HuffNode* compare(HuffNode * a, HuffNode * b); //retorna o Huffnode com menor peso
    //gera a codificação de um caractere
    QBitArray* codification(unsigned char character);
    //gera a representação da arvore
    //utiliza o metido representationRecursive
    QByteArray* representation();
    //ordena a lista
    QList<HuffNode*> sortList(QList<HuffNode*> list);
    //imprime a arvore(para fim de testes)
    void printTree();
    //verifica se chegou no final da arvore
    bool reachedDeep(QList<HuffNode*> list);
    void setRoot(HuffNode * node);
    HuffNode * getRoot();

private:
    //raiz
    HuffNode * m_root;
    //array contendo as frequencias
    int * m_frequencyArray;
    //gera a representacao da arvore de forma recursiva
    void representationRecursive(HuffNode *node, QByteArray * array);
};

#endif // HUFFTREE_H
