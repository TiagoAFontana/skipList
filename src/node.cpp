#include "node.h"

Node::Node(int k, int level)
    : key_(k)
{
    forwards_.reserve(level);
    for(int i = 0; i < level; i++){
        forwards_.push_back(NULL);
    }
}

int Node::key() const
{
    return key_;
}

int Node::level() const
{
    return forwards_.size();
}

