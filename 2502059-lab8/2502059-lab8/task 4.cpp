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
    Node* findMin(Node* node)
    {
        while (node != NULL && node->left != NULL)
            node = node->left;
        return node;
    }
    Node* deleteNode(Node* node, int value)
    {
        if (node == NULL)
            return NULL;
        if (value < node->id)
            node->left = deleteNode(node->left, value);
        else if (value > node->id)
            node->right = deleteNode(node->right, value);
        else
        {
            if (node->left == NULL && node->right == NULL)
            {
                delete node;
                return NULL;
            }
            else if (node->left == NULL)
            {
                Node* temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == NULL)
            {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            Node* temp = findMin(node->right);
            node->id = temp->id;
            node->right = deleteNode(node->right, temp->id);
        }
        return node;
    }
    void displayInOrder(Node* node)
    {
        if (node != NULL)
        {
            displayInOrder(node->left);
            cout << node->id << " ";
            displayInOrder(node->right);
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
    void deleteEmployee(int value)
    {
        root = deleteNode(root, value);
    }
    void display()
    {
        displayInOrder(root);
        cout << endl;
    }
};
int main()
{
    BST employees;
    employees.insert(50);
    employees.insert(30);
    employees.insert(70);
    employees.insert(20);
    employees.insert(40);
    employees.insert(60);
    employees.insert(80);
    int id;
    cout << "Employee IDs before deletion: ";
    employees.display();
    cout << "Enter Employee ID to delete: ";
    cin >> id;
    employees.deleteEmployee(id);
    cout << "Employee IDs after deletion: ";
    employees.display();
    return 0;
}

