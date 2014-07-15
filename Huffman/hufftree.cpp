#include "hufftree.h"
#include "huffnode.h"
#include <QList>
#include <QListIterator>
#include <QByteArray>
#include <QBitArray>

HuffTree::HuffTree()
{
}

HuffTree::HuffTree(int * frequencyArray)
{
    m_frequencyArray = frequencyArray;
}

//constroi a arvore
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

            list.append(node);

        }
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


        list.append(parent);

        list = sortList(list);

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


//associa os nós
void HuffTree::link(HuffNode * node) {
    if (node->hasLeft) {
        link(node->leftChild());
    }

    if (node->hasRight) {
        link(node->rightChild());
    }

    if (node->getParent()) {
        node->getParent()->child(node);
    }
}


void HuffTree::linkTree() {
    link(m_root);
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

                newList.append(node->leftChild());
                newList.append(node->rightChild());

            }
        }

        printf("\n");

        list = newList;
        deep = reachedDeep(list);
    }
}

QByteArray * HuffTree::representation()
{
    QByteArray * array = new QByteArray();
    this->representationRecursive(m_root, array);
    return array;
}

QBitArray * HuffTree::codification(unsigned char character)
{
    QBitArray * array = new QBitArray();

    HuffNode * node = m_root;

    if (!node->isChild(character)) {
        return NULL;
    }

    int i = 0;
    while (true) {

        if (node->isLeaf() && node->character() == character) {
            return array;
        }

        if (node->leftChild()->isChild(character)) {
            node = node->leftChild();
            array->resize(++i);
            array->setBit(i - 1, false);
        } else if (node->rightChild()->isChild(character)) {
            node = node->rightChild();

            array->resize(++i);
            array->setBit(i - 1, true);
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


void HuffTree::representationRecursive(HuffNode *node, QByteArray * array) {

    if (node->isLeaf()) {
        if (node->character() == 0 || node->character() == '(' || node->character() == ')') {
            array->append((char)0);
        }
        array->append(node->character());
    } else {
        bool noLeaf = !node->leftChild()->isLeaf();
        if (noLeaf) array->append('(');
        representationRecursive(node->leftChild(), array);
        if (noLeaf) array->append(')');

        noLeaf = !node->rightChild()->isLeaf();
        if (noLeaf) array->append('(');
        representationRecursive(node->rightChild(), array);
        if (noLeaf) array->append(')');
    }

}

void HuffTree::setRoot(HuffNode *node)
{
    m_root = node;
}

HuffNode * HuffTree::getRoot()
{
    return m_root;
}
