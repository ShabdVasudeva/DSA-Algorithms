#ifndef BINARY_TREE_HPP
#define BINARY_TREE_HPP

#include <vector>
#include <iostream>

enum Mode {
    PREORDER,
    INORDER,
    POSTORDER,
    LEVELORDER
};

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data);
    Node(int data, Node* left, Node* right);
};

Node* buildTree(const std::vector<int>& preorder);
void preorder_traversal(Node* root);
void inorder_traversal(Node* root);
void postorder_traversal(Node* root);
void levelorder_traversal(Node* root);

void print_tree(Node* root, Mode mode);

#endif // BINARY_TREE_HPP