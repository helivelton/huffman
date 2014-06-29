#include "hufftree.h"
#include "huffnode.h"
#include <QList>
#include <QListIterator>

HuffTree::HuffTree()
{
}

HuffTree::HuffTree(int *frequencyArray)
{
    m_frequencyArray = frequencyArray;
}


HuffNode * HuffTree::buildTree()
{


    QList<HuffNode*> lista = QList<HuffNode*>();


    for(int i=0; i<256;i++)
    {
        if(m_frequencyArray[i]>0)
        {
            HuffNode * node = new HuffNode();

            node->setCaractere(i);
            node->setFreq(m_frequencyArray[i]);
            node->setIsLeaf(true);
            node->setLeftChild(NULL);
            node->setRightChild(NULL);


            qDebug() << node->getFreq() << "-" << node->isLeaf();

            lista.append(node);

        }
    }

    qDebug() << lista.length();


    foreach (HuffNode* no, lista) {
        char carac = no->getCaractere();
        qDebug() << carac << " " << no->getFreq();
    }

    lista = ordenarLista(lista);

    while(lista.size()>1)
    {


        HuffNode * rightChild = lista.first();
        lista.removeAt(lista.indexOf(rightChild));
        HuffNode * leftChild = lista.first();
        lista.removeAt(lista.indexOf(leftChild));

        HuffNode * parent = new HuffNode();
        parent->setFreq(leftChild->getFreq()+rightChild->getFreq());
        parent->setIsLeaf(false);
        parent->setLeftChild(leftChild);
        parent->setRightChild(rightChild);
        parent->setCaractere(NULL);

        lista.append(parent);

        lista = ordenarLista(lista);

        qDebug() << lista.length();
    }

    m_root = lista.first();

    return m_root;

}

HuffNode * HuffTree::comparar(HuffNode *a, HuffNode *b)
{
    if(a->getFreq()<b->getFreq())
    {
        return a;
    }else
    {
        if(b->getFreq()<a->getFreq())
        {
            return b;
        }else
        {
            if(a->getCaractere()<b->getCaractere())
            {
                return a;
            }else
            {
                return b;
            }
        }

    }
}

QList<HuffNode*> HuffTree::ordenarLista(QList<HuffNode*> lista)
{
    QList<HuffNode*> listaordenada = QList<HuffNode*>();

    while(!lista.empty())
    {
        HuffNode * menor = lista.first();
        int removeIndex;
        foreach (HuffNode* no, lista) {
            menor = comparar(menor,no);
            removeIndex=lista.indexOf(menor);

        }
        listaordenada.append(menor);
        lista.removeAt(removeIndex);

    }

    return listaordenada;

}

void HuffTree::printTree()
{
    qDebug() << m_root->getFreq();

    QList<HuffNode*> lista = QList<HuffNode*>();

    lista.append(m_root);

    bool fundo = false;
    QString linha = QString();
    while(!fundo)
    {
        QList<HuffNode*> novaLista = QList<HuffNode*>();


        foreach (HuffNode * node, lista) {

            if(!node->isLeaf())
            {

                printf("%d %d ",node->getLeft()->getFreq(),node->getRight()->getFreq());



                //                qDebug() << node->getLeft()->getFreq() << " " << node->getRight()->getFreq();
                novaLista.append(node->getLeft());
                novaLista.append(node->getRight());

            }
        }

        printf("\n");

        lista=novaLista;
        fundo = reachedDeep(lista);
    }
}

bool HuffTree::reachedDeep(QList<HuffNode *> lista)
{
    foreach (HuffNode * node, lista) {

        if(!node->isLeaf()) return false;
    }

    return true;
}
