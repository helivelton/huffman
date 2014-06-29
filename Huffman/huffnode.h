#ifndef HUFFNODE_H
#define HUFFNODE_H

class HuffNode {
private:
    int m_freq;
    int m_caractere;
    HuffNode* m_leftChild;
    HuffNode* m_rightChild;
    bool m_isLeaf;

public:
    HuffNode();
    HuffNode(int freq,int caractere,bool isLeaf);
    HuffNode(int freq,int caractere,HuffNode*  leftChild,HuffNode*  rightChild,bool isLeaf);

    int getFreq();
    bool isLeaf();
    int getCaractere();
    HuffNode* getLeft();
    HuffNode* getRight();

    void setFreq(int freq);
    void setCaractere(int caractere);
    void setLeftChild(HuffNode * node);
    void setRightChild(HuffNode * node);
    void setIsLeaf(bool isLeaf);

    HuffNode* comparar(HuffNode * a, HuffNode * b); //retorna o Huffnode com menor peso

};
#endif // HUFFNODE_H
