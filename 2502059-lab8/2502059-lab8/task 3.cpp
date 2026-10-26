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
    bool search(Node* node, int value, int& comparisons)
    {
        while (node != NULL)
        {
            comparisons++;
            if (node->id == value)
                return true;
            if (value < node->id)
                node = node->left;
            else
                node = node->right;
        }
        return false;
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
    void searchBook(int value)
    {
        int comparisons = 0;
        if (search(root, value, comparisons))
            cout << "Book Found" << endl;
        else
            cout << "Book Not Found" << endl;
        cout << "Number of comparisons: " << comparisons << endl;
    }
};
int main()
{
    BST library;
    library.insert(40);
    library.insert(20);
    library.insert(60);
    library.insert(10);
    library.insert(30);
    library.insert(50);
    library.insert(70);
    int bookID;
    cout << "Enter Book ID to search: ";
    cin >> bookID;
    library.searchBook(bookID);
    return 0;
}
