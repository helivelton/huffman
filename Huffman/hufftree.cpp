#include "hufftree.h"
#include "huffnode.h"
#include <QList>
#include <QListIterator>
#include <QByteArray>

HuffTree::HuffTree()
{
}

HuffTree::HuffTree(int * frequencyArray)
{
    m_frequencyArray = frequencyArray;
}


HuffNode * HuffTree::buildTree()
{
    QList<HuffNode*> list = QList<HuffNode*>();


    for(int i=0; i<256;i++)
    {
        if(m_frequencyArray[i] > 0)
        {
            HuffNode * node = new HuffNode();

            node->setCharacter(i);
            node->setFrequency(m_frequencyArray[i]);
            node->setIsLeaf(true);
            node->setLeftChild(NULL);
            node->setRightChild(NULL);


            qDebug() << node->frequency() << "-" << node->isLeaf();

            list.append(node);

        }
    }

    qDebug() << list.length();


    foreach (HuffNode* node, list) {
        char ch = node->character();
        qDebug() << ch << " " << node->frequency();
    }

    list = sortList(list);

    while(list.size() > 1)
    {

        HuffNode * leftChild = list.first();
        list.removeAt(list.indexOf(leftChild));

        HuffNode * rightChild = list.first();
        list.removeAt(list.indexOf(rightChild));


        HuffNode * parent = new HuffNode();
        parent->setFrequency(leftChild->frequency() + rightChild->frequency());
        parent->setIsLeaf(false);
        parent->setLeftChild(leftChild);
        parent->setRightChild(rightChild);
        parent->setCharacter(NULL);

        parent->child(leftChild);
        parent->child(rightChild);


        list.append(parent);

        list = sortList(list);

        qDebug() << list.length();
    }

    m_root = list.first();

    return m_root;

}

HuffNode * HuffTree::compare(HuffNode *a, HuffNode *b)
{
    if(a->frequency() < b->frequency())
    {
        return a;
    }else
    {
        if(b->frequency() < a->frequency())
        {
            return b;
        }else
        {
            if(a->character() < b->character())
            {
                return a;
            }else
            {
                return b;
            }
        }

    }
}

QList<HuffNode*> HuffTree::sortList(QList<HuffNode*> list)
{
    QList<HuffNode*> sortedList = QList<HuffNode*>();

    while(!list.empty())
    {
        HuffNode * lowest = list.first();
        int removeIndex;
        foreach (HuffNode* node, list) {
            lowest = compare(lowest,node);
            removeIndex=list.indexOf(lowest);

        }
        sortedList.append(lowest);
        list.removeAt(removeIndex);
    }

    return sortedList;
}

void HuffTree::printTree()
{
    qDebug() << m_root->frequency();

    QList<HuffNode*> list = QList<HuffNode*>();

    list.append(m_root);

    bool deep = false;

    while(!deep)
    {
        QList<HuffNode*> newList = QList<HuffNode*>();


        foreach (HuffNode * node, list) {

            if(!node->isLeaf())
            {

                printf("%d %d ",node->leftChild()->frequency(), node->rightChild()->frequency());

                //qDebug() << node->getLeft()->getFreq() << " " << node->getRight()->getFreq();
                newList.append(node->leftChild());
                newList.append(node->rightChild());

            }
        }

        printf("\n");

        list = newList;
        deep = reachedDeep(list);
    }
}

QByteArray * HuffTree::codification(char character)
{
    QByteArray * array = new QByteArray();

    HuffNode * node = m_root;

    if (!node->isChild(character)) {
        return NULL;
    }

    while (true) {

        if (node->isLeaf() && node->character() == character) {
            return array;
        }

        if (node->leftChild()->isChild((int)character)) {
            node = node->leftChild();
            array->append('0');
        } else if (node->rightChild()->isChild((int)character)) {
            node = node->rightChild();
            array->append('1');
        } else {
            return NULL;
        }

    }

}

bool HuffTree::reachedDeep(QList<HuffNode *> list)
{
    foreach (HuffNode * node, list) {

        if(!node->isLeaf()) return false;
    }

    return true;
}
