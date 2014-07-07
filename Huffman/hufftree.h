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
    HuffNode * buildTree();
    HuffNode* compare(HuffNode * a, HuffNode * b); //retorna o Huffnode com menor peso
    QBitArray* codification(unsigned char character);
    QByteArray* representation();
    QList<HuffNode*> sortList(QList<HuffNode*> list);
    void printTree();
    bool reachedDeep(QList<HuffNode*> list);

private:
    HuffNode * m_root;
    int * m_frequencyArray;
    void representationRecursive(HuffNode *node, QByteArray * array);
};

#endif // HUFFTREE_H
