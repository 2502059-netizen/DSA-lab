
#include <iostream>
using namespace std;

class Node
{
public:
    string folder;
    Node* left;
    Node* right;

    Node(string f)
    {
        folder = f;
        left = NULL;
        right = NULL;
    }
};

void inorder(Node* root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->folder << " ";
    inorder(root->right);
}

void preorder(Node* root)
{
    if (root == NULL)
        return;

    cout << root->folder << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root)
{
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    cout << root->folder << " ";
}

int main()
{
    Node* root = new Node("C Drive");

    root->left = new Node("Program Files");
    root->right = new Node("Users");

    root->left->left = new Node("Games");
    root->left->right = new Node("Applications");

    root->right->left = new Node("Documents");
    root->right->right = new Node("Pictures");

    cout << "Inorder Traversal: ";
    inorder(root);

    cout << "\nPreorder Traversal: ";
    preorder(root);

    cout << "\nPostorder Traversal: ";
    postorder(root);

    return 0;
}

