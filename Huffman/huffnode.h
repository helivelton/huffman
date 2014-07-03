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

    void setFrequency(int frequency);
    void setCharacter(unsigned char character);
    void setLeftChild(HuffNode * node);
    void setRightChild(HuffNode * node);
    void setIsLeaf(bool isLeaf);

    HuffNode* compare(HuffNode * a, HuffNode * b); //retorna o Huffnode com menor peso

private:
    int m_frequency;
    unsigned char m_character;
    HuffNode * m_leftChild;
    HuffNode * m_rightChild;
    bool m_isLeaf;
};
#endif // HUFFNODE_H
