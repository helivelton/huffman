#ifndef HUFFTREE_H
#define HUFFTREE_H
#include <huffnode.h>
#include <QDebug>
#include <QList>
#include <QByteArray>

class HuffTree
{
public:
    HuffTree();
    HuffTree(int * frequencyArray);
    HuffNode * buildTree();
    HuffNode* compare(HuffNode * a, HuffNode * b); //retorna o Huffnode com menor peso
    QByteArray* codification(char character);
    QList<HuffNode*> sortList(QList<HuffNode*> list);
    void printTree();
    bool reachedDeep(QList<HuffNode*> list);

private:
    HuffNode * m_root;
    int * m_frequencyArray;
};

#endif // HUFFTREE_H
