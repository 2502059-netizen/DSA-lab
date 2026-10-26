#include <iostream>
using namespace std;
class Node
{
public:
    int id;
    Node* left;
    Node* right;
    Node(int value)
    {
        id = value;
        left = NULL;
        right = NULL;
    }
};
class BST
{
private:
    Node* root;
    Node* insert(Node* node, int value)
    {
        if (node == NULL)
            return new Node(value);
        if (value < node->id)
            node->left = insert(node->left, value);
        else if (value > node->id)
            node->right = insert(node->right, value);
        return node;
    }
    void inOrder(Node* node)
    {
        if (node != NULL)
        {
            inOrder(node->left);
            cout << node->id << " ";
            inOrder(node->right);
        }
    }
    void preOrder(Node* node)
    {
        if (node != NULL)
        {
            cout << node->id << " ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }
    void postOrder(Node* node)
    {
        if (node != NULL)
        {
            postOrder(node->left);
            postOrder(node->right);
            cout << node->id << " ";
        }
    }
public:
    BST()
    {
        root = NULL;
    }
    void insert(int value)
    {
        root = insert(root, value);
    }
    void displayInOrder()
    {
        cout << "In-order Traversal: ";
        inOrder(root);
        cout << endl;
    }
    void displayPreOrder()
    {
        cout << "Pre-order Traversal: ";
        preOrder(root);
        cout << endl;
    }
    void displayPostOrder()
    {
        cout << "Post-order Traversal: ";
        postOrder(root);
        cout << endl;
    }
};
int main()
{
    BST hospital;
    hospital.insert(40);
    hospital.insert(20);
    hospital.insert(60);
    hospital.insert(10);
    hospital.insert(30);
    hospital.insert(50);
    hospital.insert(70);
    hospital.displayInOrder();
    hospital.displayPreOrder();
    hospital.displayPostOrder();
    cout << "Ascending Order: In-order Traversal" << endl;
    return 0;
}

