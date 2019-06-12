//
//  bst.hpp
//  aug_bst
//  Created by Julian Rincon on 2018-11-18.
//

#ifndef bst_hpp
#define bst_hpp

#include <iostream>

template <typename keyType>
class bst {
public:
    bst();
    ~bst();

    void remove(keyType);
    void insert(keyType);
    bool find(keyType) const;

    void clear(void);
    void display(std::ostream & = std::cout) const;

    int size() const;
    int height() const;

private:
    struct bstNode {
        keyType key;
        bstNode *left;
        bstNode *right;
    };

    size_t count;
    bstNode *tree;

    bstNode * min(bstNode *) const;
    void remove(bstNode * &, keyType);
    void insert(bstNode * &, keyType);
    bstNode * find(bstNode *, keyType) const;

    void clear(bstNode * &);
    void display(bstNode *, std::ostream &) const;
    int size(bstNode *tmp) const;
    int height(bstNode *tmp, int max) const;
};

#include "p1.cpp"

#endif /* bst_hpp */
