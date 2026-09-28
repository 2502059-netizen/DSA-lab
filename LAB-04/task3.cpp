#include <iostream>
#include <string>
using namespace std;

struct Node {
    string productID;
    Node* next;

    Node(string id) {
        productID = id;
        next = NULL;
    }
};

class ShoppingCart {
private:
    Node* head;

public:
    ShoppingCart() {
        head = NULL;
    }

    // 1. Add product to the shopping cart
    void addProduct(string id) {
        Node* newNode = new Node(id);
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }

    // 2. Remove product using Product ID
    bool removeProduct(string id) {
        if (head == NULL) {
            return false;
        }

        // If the product to remove is at the head
        if (head->productID == id) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return true;
        }

        // Search for the product in the rest of the list
        Node* current = head;
        Node* prev = NULL;
        while (current != NULL && current->productID != id) {
            prev = current;
            current = current->next;
        }

        // Product not found
        if (current == NULL) {
            return false;
        }

        // Unlink node and delete
        prev->next = current->next;
        delete current;
        return true;
    }

    // 3. Display all products in the cart
    void displayCart() const {
        if (head == NULL) {
            cout << "Cart is empty." << endl;
            return;
        }
        Node* current = head;
        while (current != NULL) {
            cout << current->productID;
            if (current->next != NULL) {
                cout << " -> ";
            }
            current = current->next;
        }
        cout << endl;
    }

    // Destructor to free memory
    ~ShoppingCart() {
        Node* current = head;
        while (current != NULL) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
};

int main() {
    ShoppingCart cart;
    int count;
    string id, removeID;

    cout << "Enter total number of products to add: ";
    cin >> count;

    for (int i = 0; i < count; i++) {
        cout << "Enter Product ID " << (i + 1) << ": ";
        cin >> id;
        cart.addProduct(id);
    }

    cout << "\nShopping Cart:" << endl;
    cart.displayCart();

    cout << "\nEnter Product ID to Remove: ";
    cin >> removeID;

    if (cart.removeProduct(removeID)) {
        cout << "Product " << removeID << " removed successfully." << endl;
    } else {
        cout << "Product " << removeID << " not found in cart." << endl;
    }

    cout << "\nUpdated Cart:" << endl;
    cart.displayCart();

    return 0;
}