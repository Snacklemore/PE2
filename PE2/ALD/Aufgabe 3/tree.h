//
// Created by nico on 26.04.17.
//

#include <stddef.h>

#ifndef ALDSEARCHTREE_TREE_H
#define ALDSEARCHTREE_TREE_H

#endif //ALDSEARCHTREE_TREE_H
class Node {
public:
    Node(int val);
    //searchTree *insertNode(int val);
    int _value;
    Node *right;
    Node *left;
    Node *parent;
};
class searchTree{
public:
    Node *root;
    searchTree();
    void InsertInOrder(Node *&root,int val);
    void printTreeHopefullyInorder(Node *root);
    void remove(int data);
    bool containsNode(Node *root,int val);
};