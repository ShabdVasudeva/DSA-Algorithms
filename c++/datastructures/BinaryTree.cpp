
#include "BinaryTree.hpp"
#include <queue>

using namespace std;

Node::Node(int data)
{
    this->data = data;
    this->left = this->right = nullptr;
}

Node::Node(int data, Node* left, Node* right)
{
    this->data = data;
    this->left = left;
    this->right = right;
}

static int idx = -1;

Node* buildTree(const vector<int>& preorder)
{
    idx++;
    if(preorder[idx] == -1) return nullptr;
    Node* root = new Node(preorder[idx]);
    root->left = buildTree(preorder);
    root->right = buildTree(preorder);
    return root;
}

void preorder_traversal(Node* root)
{
    if(root == nullptr) return;
    cout << root->data << " ";
    preorder_traversal(root->left);
    preorder_traversal(root->right);
}

void postorder_traversal(Node* root)
{
    if(root == nullptr) return;
    postorder_traversal(root->left);
    postorder_traversal(root->right);
    cout << root->data << " ";
}

void inorder_traversal(Node* root)
{
    if(root == nullptr) return;
    inorder_traversal(root->left);
    cout << root->data << " ";
    inorder_traversal(root->right);
}

void levelorder_traversal(Node* root)
{
    queue<Node*> q;
    q.push(root);
    while(q.size() > 0)
    {
        Node* current = q.front();
        q.pop();
        cout << current->data << " ";
        if (current->left != nullptr)
        {
            q.push(current->left);
        }
        if (current->right != nullptr)
        {
            q.push(current->right);
        }
    }
}

void print_tree(Node *root, Mode mode)
{
    switch (mode)
    {
        case PREORDER: preorder_traversal(root); cout << "\n"; break;
        case POSTORDER: postorder_traversal(root); cout << "\n"; break;
        case INORDER: inorder_traversal(root); cout << "\n"; break;
        case LEVELORDER: levelorder_traversal(root); cout << "\n"; break;
    }
}
