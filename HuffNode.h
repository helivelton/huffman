#ifndef HUFFNODE_H
#define HUFFNODE_H
template <typename E> class HuffNode {
public:
virtual int weight() = 0; // Return frequency
virtual bool isLeaf() = 0; // Determine type
};
#endif // HUFFNODE_H
