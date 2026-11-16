
#include <iostream>
#include <algorithm>
using namespace std;

class Node
{
public:
    int token;
    int height;
    Node* left;
    Node* right;

    Node(int value)
    {
        token = value;
        height = 1;
        left = NULL;
        right = NULL;
    }
};

class AVL
{
private:
    Node* root;

    int getHeight(Node* node)
    {
        if (node == NULL)
            return 0;

        return node->height;
    }

    int getBalance(Node* node)
    {
        if (node == NULL)
            return 0;

        return getHeight(node->left) -
               getHeight(node->right);
    }

    Node* rightRotate(Node* y)
    {
        Node* x = y->left;
        Node* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = 1 + max(getHeight(y->left),
                            getHeight(y->right));

        x->height = 1 + max(getHeight(x->left),
                            getHeight(x->right));

        return x;
    }

    Node* leftRotate(Node* x)
    {
        Node* y = x->right;
        Node* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = 1 + max(getHeight(x->left),
                            getHeight(x->right));

        y->height = 1 + max(getHeight(y->left),
                            getHeight(y->right));

        return y;
    }

    Node* insert(Node* node, int value)
    {
        if (node == NULL)
            return new Node(value);

        if (value < node->token)
            node->left = insert(node->left, value);

        else if (value > node->token)
            node->right = insert(node->right, value);

        else
            return node;

        node->height = 1 + max(getHeight(node->left),
                               getHeight(node->right));

        int balance = getBalance(node);

        // LL Case
        if (balance > 1 && value < node->left->token)
            return rightRotate(node);

        // RR Case
        if (balance < -1 && value > node->right->token)
            return leftRotate(node);

        // LR Case
        if (balance > 1 && value > node->left->token)
        {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // RL Case
        if (balance < -1 && value < node->right->token)
        {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    void inorder(Node* node)
    {
        if (node == NULL)
            return;

        inorder(node->left);
        cout << node->token << " ";
        inorder(node->right);
    }

    void display(Node* node, int space)
    {
        if (node == NULL)
            return;

        space += 5;

        display(node->right, space);

        cout << endl;

        for (int i = 5; i < space; i++)
            cout << " ";

        cout << node->token
             << " (H:" << node->height
             << ", BF:" << getBalance(node) << ")";

        display(node->left, space);
    }

public:
    AVL()
    {
        root = NULL;
    }

    void insert(int value)
    {
        root = insert(root, value);
    }

    void showInorder()
    {
        inorder(root);
        cout << endl;
    }

    void showTree()
    {
        display(root, 0);
        cout << endl;
    }
};

int main()
{
    AVL tree;

    int tokens[] = {15, 25, 35, 45, 55, 65, 75};

    cout << "Inserting Appointment Tokens:\n";

    for (int i = 0; i < 7; i++)
    {
        tree.insert(tokens[i]);
        cout << tokens[i] << " inserted\n";
    }

    cout << "\nInorder Traversal:\n";
    tree.showInorder();

    cout << "\nFinal Balanced AVL Tree:\n";
    tree.showTree();

    return 0;
}

