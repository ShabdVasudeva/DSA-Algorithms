#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

static int idx = -1;

Node* initializeBinaryTree(vector<int> preOrderSequence)
{
    idx++;
    if (idx >= preOrderSequence.size() || preOrderSequence[idx] == -1)
    {
        return NULL;
    }
    Node* root = new Node(preOrderSequence[idx]);
    root->left = initializeBinaryTree(preOrderSequence);
    root->right = initializeBinaryTree(preOrderSequence);
    return root;
}

void printOutput(Node* root)
{ // pre-order traversal
    if (root == NULL)
    {
        return;
    }
    cout << root-> data << " ";
    printOutput(root->left);
    printOutput(root->right);
}

int main() 
{
    vector<int> preOrderSequence = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node* root = initializeBinaryTree(preOrderSequence);
    printOutput(root);
    cout << "\n";
    return 0;
}