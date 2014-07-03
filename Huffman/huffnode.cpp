#include "huffnode.h"

HuffNode::HuffNode()
{
}

HuffNode::HuffNode(int frequency, unsigned char character, HuffNode * leftChild, HuffNode * rightChild, bool isLeaf)
{
    m_frequency = frequency;
    m_character = character;
    m_leftChild = leftChild;
    m_rightChild = rightChild;
    m_isLeaf = isLeaf;
}

HuffNode::HuffNode(int frequency, unsigned char character, bool isLeaf)
{
    m_frequency = frequency;
    m_character = character;
    m_isLeaf = isLeaf;
}

unsigned char HuffNode::character()
{
    return m_character;
}

int HuffNode::frequency()
{
    return m_frequency;
}

HuffNode * HuffNode::leftChild()
{
    return m_leftChild;
}

HuffNode * HuffNode::rightChild()
{
    return m_rightChild;
}

bool HuffNode::isLeaf()
{
    return m_isLeaf;
}

void HuffNode::setCharacter(unsigned char character)
{
    m_character = character;
}

void HuffNode::setFrequency(int frequency)
{
    m_frequency = frequency;
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


HuffNode * HuffNode::compare(HuffNode *a, HuffNode *b)
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
