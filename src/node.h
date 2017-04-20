#ifndef NODE_H
#define NODE_H
#include <vector>
#include <stdlib.h>

class Node
{
public:
    Node(int k, int level);

    int key() const;
    int level() const;

    std::vector<Node*> forwards_;
private:
    int key_;
};

#endif // NODE_H
