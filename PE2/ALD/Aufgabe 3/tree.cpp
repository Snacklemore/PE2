//
// Created by nico on 26.04.17.
//
#include <iostream>
#include "tree.h"


Node::Node(int val){
    _value = val;
    right = nullptr;
    left  = nullptr;
    parent= nullptr;
}
searchTree::searchTree(){
    root = nullptr;
}
void searchTree::InsertInOrder( Node *&root,int val) {
    if (root == nullptr){
        root = new Node(val);
        return;
    }else if (val < root->_value){
        InsertInOrder(root->left,val);
    }else {
        InsertInOrder(root->right,val);
    }

}
bool searchTree::containsNode(Node *root,int val){
    if (root == nullptr){
        return false;
    }else if (val == root->_value)
            return true;
    else if (val < root->_value)
        return containsNode(root->left,val);
    else return containsNode(root->right,val);

}
void searchTree::printTreeHopefullyInorder(Node *root){

    if (root == nullptr){
        return;
    }
    printTreeHopefullyInorder(root->left);
    std::cout << root->_value << std::endl;
    printTreeHopefullyInorder(root->right);
}
void searchTree::remove(int data) {
    if (root == nullptr)
        std::cout << "Nothing to do here" << std::endl;
    Node *currentNode = root;
    Node *parent;
    //rootToLeaf
    while (currentNode) {
        if (currentNode->_value == data) {
            break;//3 Cases:LookDown
        } else {
            parent = currentNode;
            currentNode = data > currentNode->_value ? currentNode->right : currentNode->left;
        }
    }
    if (currentNode == nullptr) {
        std::cout << "key not found" << std::endl;
        return;
    }

    //3Cases:1. Leafnode
    //   2. Node with 1 Child
    //   3. Node with 2 Childs



    //leafNode
    if (currentNode->left == nullptr and currentNode->right == nullptr) {
        if (parent->left == currentNode)
            parent->left = nullptr;
        else
            parent->right = nullptr;
        delete currentNode;
        //decrease nodeSize
        return;
    }

    //1 Child
    if ((currentNode->left == nullptr and currentNode->right != nullptr)or(currentNode->left != nullptr and currentNode->right == nullptr)){
        if (currentNode->left == nullptr and currentNode->right != nullptr){
            if (parent->left == currentNode){
                parent->left = currentNode->right;
            }else {
                parent->right= currentNode->right;
            }
        }else {//left child
            if (parent->left == currentNode){
                parent->left == currentNode->left;
            }else {
                parent->right==currentNode->left;
            }
        }
        delete currentNode;
        //decrease nodeSize
        return;
    }
    //2 Children mit kleinstem Wert aus rechtem Subtree
    if (currentNode->left != nullptr and currentNode->right != nullptr){
        Node *curr_right = currentNode->right;
        if (curr_right->left == nullptr and curr_right->right == nullptr){
            currentNode->_value = curr_right->_value;
            delete curr_right;
            currentNode->right = nullptr;
        }else {//r.child with children
                //verschieben bis zum kleinsten value
            if ((currentNode->right)->left != nullptr){
                Node *lecurr;
                Node *lecurr_parent;
                lecurr_parent = currentNode->right;
                lecurr = (currentNode->right)->left;
                while (lecurr->left != nullptr){
                    lecurr_parent = lecurr;
                    lecurr = lecurr->left;
                }
                currentNode->_value = lecurr->_value;
                delete lecurr;
                lecurr_parent->left = nullptr;
            }else {
                Node *tmp = currentNode->right;
                currentNode->_value = tmp->_value;
                currentNode->right = tmp->right;
                delete tmp;
            }//(currentNode->right)->right !=nulptr
        }
        //decrease nodeSize
    }
}




