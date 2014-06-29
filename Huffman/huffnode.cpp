#include "huffnode.h"

HuffNode::HuffNode()
{
}

HuffNode::HuffNode(int freq, int caractere, HuffNode* leftChild, HuffNode* rightChild, bool isLeaf)
{
    m_freq = freq;
    m_caractere = caractere;
    m_leftChild = leftChild;
    m_rightChild = rightChild;
    m_isLeaf = isLeaf;
}

HuffNode::HuffNode(int freq, int caractere, bool isLeaf)
{
    m_freq = freq;
    m_caractere = caractere;
    m_isLeaf = isLeaf;
}

int HuffNode::getCaractere()
{
    return m_caractere;
}

int HuffNode::getFreq()
{
    return m_freq;
}

HuffNode * HuffNode::getLeft()
{
    return m_leftChild;
}

HuffNode * HuffNode::getRight()
{
    return m_rightChild;
}

bool HuffNode::isLeaf()
{
   return m_isLeaf;
}

void HuffNode::setCaractere(int caractere)
{
    m_caractere = caractere;
}

void HuffNode::setFreq(int freq)
{
    m_freq = freq;
}

void HuffNode::setIsLeaf(bool isLeaf)
{
    m_isLeaf = isLeaf;
}

void HuffNode::setLeftChild(HuffNode *node)
{
    m_leftChild = node;
}

void HuffNode::setRightChild(HuffNode *node)
{
    m_rightChild = node;
}


HuffNode * HuffNode::comparar(HuffNode *a, HuffNode *b)
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
