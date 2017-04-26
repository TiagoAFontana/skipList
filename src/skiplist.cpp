#include "skiplist.h"

SkipList::SkipList(float probability, int maxLevel)
    :probability_(probability), maxLevel_(maxLevel)
{
    // Initialize the head of the skip list with smallest possible key
    head_ = new Node(std::numeric_limits<int>::min(), maxLevel_);

    // Initialize the last element of the list with largest possible key
    NIL_ = new Node(std::numeric_limits<int>::max(), maxLevel_);

    // Connect start to end
    // connect all the levels/forward pointers of the header to NIL
    for (size_t i = 0; i < head_->forwards_.size(); i++) {
        head_->forwards_[i] = NIL_;
    }
}

void SkipList::insert(int key)
{
    // vector of pointers that needs to be updated to account for the new node
    std::vector<Node*> update(head_->forwards_);
    unsigned int currentMaximum = nodeLevel(head_->forwards_);
    Node* x = head_;

    // search the list
    for (unsigned int i = currentMaximum; i-- > 0;) {

        while (x->forwards_[i] != NULL && x->forwards_[i]->key() < key) {
            x = x->forwards_[i];
        }
        update[i] = x;
    }
    x = x->forwards_[0];

    // create new node
    int newNodeLevel = 1;
    if (x->key() != key) {

        newNodeLevel = this->ramdomLevel();
        int currentLevel = nodeLevel(update);

        if (newNodeLevel > currentLevel) {

            for (int i = currentLevel + 1; i < newNodeLevel; ++i) {
                update[i] = head_;
            }
        }
        x = new Node(key, newNodeLevel);
    }

    // connect pointers of predecessors and new node to successors
    for (int i = 0; i < newNodeLevel; ++i) {
        x->forwards_[i] = update[i]->forwards_[i];
        update[i]->forwards_[i] = x;
    }
}

int SkipList::erase(int key)
{
    // vector of pointers that needs to be updated to account for the deleted node
    std::vector<Node*> update(head_->forwards_);
    Node* x = head_;
    unsigned int currentMaximum = nodeLevel(head_->forwards_);

    // search and update pointers
    for (unsigned int i = currentMaximum; i-- > 0;) {

        while (x->forwards_[i] != NULL && x->forwards_[i]->key() < key) {

            x = x->forwards_[i];
        }
        update[i] = x;
    }
    x = x->forwards_[0];

    // update pointers and delete node
    if (x->key() == key) {
        for (size_t i = 0; i < update.size(); ++i) {

            if (update[i]->forwards_[i] != x) {

                break;
            }
            update[i]->forwards_[i] = x->forwards_[i];
        }
        delete x;
    }else{
        return -1;
    }

}

void SkipList::remove_first()
{
    Node* x = head_->forwards_[0];
    erase(x->key());
}

Node* SkipList::find(int key)
{
    Node* x = head_;
    unsigned int currentMaximum = nodeLevel(head_->forwards_);

    for (unsigned int i = currentMaximum; i-- > 0;) {
        while (x->forwards_[i] != NULL && x->forwards_[i]->key() < key) {
            x = x->forwards_[i];
        }
    }
    x = x->forwards_[0];

    if (x->key() == key) {
        return x;
    } else {
        return NULL;
    }
}

void SkipList::print()
{
    Node* list = head_;
    int lineLenght = 1;

    std::cout <<"{";

    while (list->forwards_[0] != NULL) {
        std::cout <<", key: "<< list->forwards_[0]->key()
                  <<", level: "<< nodeLevel(list->forwards_) //<< "\n";
                  <<", levelSet: "<< list->forwards_[0]->level() << "\n";
        list = list->forwards_[0];
    }
    std::cout <<"}\n";
}

int SkipList::size()
{
    Node* list = head_;
    int size = 0;
    while (list->forwards_[0] != NULL) {
        size ++;
        list = list->forwards_[0];
    }
    return size;
}

int SkipList::ramdomLevel()
{
    //It generates node levels in the range [1, maxLevel)
    int v = 1;

    //rand() generated numbers are within [0,1)
    //RAND_MAX is the largest number rand will return
    while ((((double)std::rand() / RAND_MAX)) < probability_ && std::abs(v) < maxLevel_) {
        v ++;
    }
    return abs(v);
}

int SkipList::nodeLevel(const std::vector<Node *> &v)
{
    int currentLevel = 1;
    // last element's key is the largest
    int nilKey = std::numeric_limits<int>::max();

    if (v[0]->key() == nilKey) {
        return currentLevel;
    }

    for (size_t i = 0; i < v.size(); ++i) {

        if (v[i] != NULL && v[i]->key() != nilKey) {
            ++currentLevel;
        } else {
            break;
        }
    }
    return currentLevel;
}

