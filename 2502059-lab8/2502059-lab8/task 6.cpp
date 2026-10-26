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
        else
            cout << "Duplicate product ID! Not inserted." << endl;
        return node;
    }
    bool search(Node* node, int value)
    {
        if (node == NULL)
            return false;
        if (node->id == value)
            return true;
        if (value < node->id)
            return search(node->left, value);
        return search(node->right, value);
    }
    Node* findMin(Node* node)
    {
        while (node != NULL && node->left != NULL)
            node = node->left;
        return node;
    }
    Node* deleteNode(Node* node, int value, bool& found)
    {
        if (node == NULL)
            return NULL;
        if (value < node->id)
            node->left = deleteNode(node->left, value, found);
        else if (value > node->id)
            node->right = deleteNode(node->right, value, found);
        else
        {
            found = true;
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
            else
            {
                Node* temp = findMin(node->right);
                node->id = temp->id;
                bool dummy = false;
                node->right = deleteNode(node->right, temp->id, dummy);
            }
        }
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
    void destroyTree(Node* node)
    {
        if (node != NULL)
        {
            destroyTree(node->left);
            destroyTree(node->right);
            delete node;
        }
    }
public:
    BST()
    {
        root = NULL;
    }
    ~BST()
    {
        destroyTree(root);
    }
    void insertProduct(int value)
    {
        root = insert(root, value);
    }
    void searchProduct(int value)
    {
        if (search(root, value))
            cout << "Product Found!" << endl;
        else
            cout << "Product Not Found!" << endl;
    }
    void deleteProduct(int value)
    {
        bool found = false;
        root = deleteNode(root, value, found);
        if (found)
            cout << "Product deleted successfully." << endl;
        else
            cout << "Product Not Found! Cannot delete." << endl;
    }
    void displayInOrder()
    {
        if (root == NULL)
            cout << "Inventory is empty." << endl;
        else
        {
            cout << "In-order: ";
            inOrder(root);
            cout << endl;
        }
    }
    void displayPreOrder()
    {
        if (root == NULL)
            cout << "Inventory is empty." << endl;
        else
        {
            cout << "Pre-order: ";
            preOrder(root);
            cout << endl;
        }
    }
    void displayPostOrder()
    {
        if (root == NULL)
            cout << "Inventory is empty." << endl;
        else
        {
            cout << "Post-order: ";
            postOrder(root);
            cout << endl;
        }
    }
};
int main()
{
    BST inventory;
    int choice, id;
    do
    {
        cout << "\n===== ONLINE STORE INVENTORY =====" << endl;
        cout << "1. Insert a product ID" << endl;
        cout << "2. Search for a product ID" << endl;
        cout << "3. Delete a product ID" << endl;
        cout << "4. Display in-order traversal" << endl;
        cout << "5. Display pre-order traversal" << endl;
        cout << "6. Display post-order traversal" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter product ID: ";
            cin >> id;
            inventory.insertProduct(id);
            break;
        case 2:
            cout << "Enter product ID to search: ";
            cin >> id;
            inventory.searchProduct(id);
            break;
        case 3:
            cout << "Enter product ID to delete: ";
            cin >> id;
            inventory.deleteProduct(id);
            break;
        case 4:
            inventory.displayInOrder();
            break;
        case 5:
            inventory.displayPreOrder();
            break;
        case 6:
            inventory.displayPostOrder();
            break;
        case 7:
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 7);
    return 0;
}

