#ifndef HUFFTREE_H
#define HUFFTREE_H
#include <huffnode.h>
#include <QDebug>
#include <QList>

class HuffTree
{
public:
    HuffTree();
    HuffTree(int * frequencyArray);
    HuffNode * buildTree();
    HuffNode* compare(HuffNode * a, HuffNode * b); //retorna o Huffnode com menor peso
    QList<HuffNode*> sortList(QList<HuffNode*> list);
    void printTree();
    bool reachedDeep(QList<HuffNode*> list);

private:
    HuffNode * m_root;
    int * m_frequencyArray;
};

#endif // HUFFTREE_H
