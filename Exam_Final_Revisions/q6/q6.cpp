// Using the binary_tree_node from Section 10.3, ( bintree.h , bintree.template ) write a function to meet the following specification. You do not need to check the precondition.
// template <class Item>                
// int tree_depth(binary_tree_node<Item> * root_ptr)
// Precondition: root_ptr is the root pointer of a binary tree.
// Postcondition: The return value is the depth of the binary tree. // NOTES: The empty tree has a depth of -1 and a tree with just a root // has a depth of 0.         
#include <iostream>
#include <cstdlib> 
#include "bintree.h"
using namespace std;
using namespace main_savitch_10;


template <class Item>                
int tree_depth(binary_tree_node<Item> *root_ptr){
    int depth = -1;
    dept_rec(root_ptr, depth);
    return depth;
}

template <class Item>                
void depth_rec(binary_tree_node<Item> *root_ptr,int depth){
    if (root_ptr == NULL){ return; }
    if (root_ptr != NULL){ ++depth; }
    depth_rec(root_ptr->left(), depth);
    depth_rec(root_ptr->right(), depth);
}


int main(){
    binary_tree_node<int> c(2);
    binary_tree_node<int> d(3);
    binary_tree_node<int> b(3,NULL,d);
    binary_tree_node<int> a(3,b,c);
    
    binary_tree_node<int> *p = a;
    cout<<tree_depth(p);
}

