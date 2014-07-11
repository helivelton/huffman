#ifndef HUFFNODE_H
#define HUFFNODE_H

class HuffNode {

public:
    HuffNode();
    HuffNode(int frequency, unsigned char character, bool isLeaf);
    HuffNode(int frequency, unsigned char character, HuffNode * leftChild, HuffNode * rightChild, bool isLeaf);

    int frequency();
    bool isLeaf();
    unsigned char character();
    HuffNode * leftChild();
    HuffNode * rightChild();
    HuffNode * getParent();
    bool hasLeft = false;
    bool hasRight = false;
    bool isChild(unsigned char character);

    void setFrequency(int frequency);
    void setCharacter(unsigned char character);
    void setLeftChild(HuffNode * node);
    void setRightChild(HuffNode * node);
    void setIsLeaf(bool isLeaf);
    void setParent(HuffNode * node);

    void child(HuffNode * node);
    HuffNode* compare(HuffNode * a, HuffNode * b); //retorna o Huffnode com menor peso

private:
    HuffNode * m_parent;
    int m_frequency;
    unsigned char m_character;
    HuffNode * m_leftChild;
    HuffNode * m_rightChild;
    bool m_childs[256];
    bool m_isLeaf;
};
#endif // HUFFNODE_H
