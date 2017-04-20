#ifndef SKIPLIST_H
#define SKIPLIST_H

#include <vector>
#include <stdlib.h>
#include <limits>
#include <iostream>
#include <cstdlib> //to rand
#include "node.h"

class SkipList
{
public:
    SkipList(float probability = 0.5, int maxLevel = 32);

    void insert(int key);
    void erase(int key);

    Node* find(int key);
    void print();
private:

    Node* head_; //first node
    Node* NIL_; //last node

    float probability_;
    int maxLevel_;

    int ramdomLevel();
    int nodeLevel(const std::vector<Node*>& v);

};

#endif // SKIPLIST_H
