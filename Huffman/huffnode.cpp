#include "huffnode.h"
#include <QDebug>

HuffNode::HuffNode()
{
    for (int i = 0; i < 256; i++) {
        this->m_childs[i] = false;
    }
}

HuffNode::HuffNode(int frequency, unsigned char character, HuffNode * leftChild, HuffNode * rightChild, bool isLeaf)
{
    m_frequency = frequency;
    m_character = character;
    m_leftChild = leftChild;
    m_rightChild = rightChild;
    m_isLeaf = isLeaf;

    for (int i = 0; i < 256; i++) {
        this->m_childs[i] = false;
    }
}

HuffNode::HuffNode(int frequency, unsigned char character, bool isLeaf)
{
    m_frequency = frequency;
    m_character = character;
    m_isLeaf = isLeaf;


    for (int i = 0; i < 256; i++) {
        this->m_childs[i] = false;
    }
}

unsigned char HuffNode::character()
{
    return m_character;
}

int HuffNode::frequency()
{
    return m_frequency;
}

bool HuffNode::isChild(unsigned char character)
{
    return m_childs[character] || (this->isLeaf() && this->character() == character);
}

void HuffNode::child(HuffNode * node) {

    for (int i = 0; i < 256; i++) {
        if (node->m_childs[i]) {
            this->m_childs[i] = true;
        }
    }

    if (node->isLeaf()) {
        m_childs[node->character()] = true;
    }
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

void HuffNode::setParent(HuffNode * node)
{
    m_parent = node;
}

HuffNode * HuffNode::getParent()
{
    return m_parent;
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
