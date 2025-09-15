#include <iostream>
#include <vector>
#include "datastructures/BinaryTree.hpp"

using namespace std;

int depth(Node* root)  // Time Complexity: O(n), Space Complexity: O(h)
{
    if(root == nullptr) return 0;
    int left_depth = depth(root->left);
    int right_depth = depth(root->right);
    return max(left_depth, right_depth) + 1;
}

int count_nodes(Node* root)  // Time Complexity: O(n), Space Complexity: O(h)
{
    if(root == nullptr) return 0;
    int left_count = count_nodes(root->left);
    int right_count = count_nodes(root->right);
    return left_count + right_count + 1;
}

int sum_nodes(Node* root)  // Time Complexity: O(n), Space Complexity: O(h)
{
    if(root == nullptr) return 0;
    int left_sum = sum_nodes(root->left);
    int right_sum = sum_nodes(root->right);
    return left_sum + right_sum + root->data;
}

int main()
{
    vector<int> preorder = {1,2,3,-1,-1,4,-1,-1,5,-1,-1};
    Node* root = buildTree(preorder);
    cout << "Preorder Traversal: " << "\n";
    print_tree(root, PREORDER);
    cout << "Depth of the tree: " << depth(root) << "\n";
    cout << "Number of nodes in the tree: " << count_nodes(root) << "\n";
    cout << "Sum of all nodes in the tree: " << sum_nodes(root) << "\n";
    return 0;
}