#include "trees.h"

int main()
{
    binarysearchtree bst;
    bst.insert_tree_element(3,bst.getroot());
    bst.insert_tree_element(1,bst.getroot());
    bst.insert_tree_element(5,bst.getroot());
    // bst.insert_tree_element(8,bst.getroot());
    // bst.insert_tree_element(3,bst.getroot());
    // bst.insert_tree_element(9,bst.getroot());
    // bst.insert_tree_element(4,bst.getroot());
    // bst.insert_tree_element(7,bst.getroot());
    // bst.insert_tree_element(9,bst.getroot());
    // bst.insert_tree_element(5,bst.getroot());
    // bst.insert_tree_element(8,bst.getroot());
    // bst.insert_tree_element(3,bst.getroot());
    // bst.insert_tree_element(6,bst.getroot());

    bst.visualize_tree(bst.getroot());
    std::cout<<std::endl;
    std::cout<<std::endl;
    // bst.ascending_display(bst.getroot());
    // bst.descending_display(bst.getroot());

    bst.delete_tree_element(3,bst.getroot());
    // bst.delete_tree_element(8,bst.getroot());
    // bst.delete_tree_element(9,bst.getroot());
    bst.visualize_tree(bst.getroot());

    // std::cout<<std::endl;
    // bst.display_element(bst.findmax(bst.getroot()));

    return 0;
}
