#include <iostream>
#include "tree.h"
#define MAX 5
int main() {
    searchTree t;
    srand(time(NULL));
    /*for (int i = 0;i<MAX;i++){
        t.InsertInOrder(t.root, rand() % 10);

    }*/
    t.InsertInOrder(t.root,2);
    t.InsertInOrder(t.root,8);
    t.InsertInOrder(t.root,12);
    t.InsertInOrder(t.root,1);
    t.InsertInOrder(t.root,5);
    t.printTreeHopefullyInorder(t.root);
    std::cout << "Removing 1 " << std::endl;
    t.remove(1);
    std::cout << std::boolalpha <<"Is a 12(twelve)Node in the tree?" << t.containsNode(t.root,12) << std::endl;
    t.printTreeHopefullyInorder(t.root);
    std::cout << "Removing 12" << std::endl;
    t.remove(12);
    t.printTreeHopefullyInorder(t.root);
    std::cout << "Removing 5" << std::endl;
    t.remove(5);
    std::cout << std::boolalpha <<"Is a 1(One)Node in the tree?" << t.containsNode(t.root,1) << std::endl;
    t.printTreeHopefullyInorder(t.root);
    std::cout << "Removing 8" << std::endl;
    t.remove(8);
    t.printTreeHopefullyInorder(t.root);
    return 0;
}