#ifndef HUFFTREE_H
#define HUFFTREE_H
#include <HuffNode.h>
#include <QDebug>
#include <QList>

class HuffTree
{
public:
    HuffTree();
    HuffTree(int * frequencyArray);
    HuffNode * buildTree();
    HuffNode* comparar(HuffNode * a, HuffNode * b); //retorna o Huffnode com menor peso
    QList<HuffNode*> ordenarLista(QList<HuffNode*> lista);
    void printTree();
    bool reachedDeep(QList<HuffNode*> lista);
private:
    HuffNode * m_root;
    int * m_frequencyArray;
};

#endif // HUFFTREE_H
