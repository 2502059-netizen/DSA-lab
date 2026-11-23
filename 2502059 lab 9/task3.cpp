#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
class Order {
public:
    int orderID, amount;
    string customerName;
    Order *left, *right;
    Order(int id, string name, int a) {
        orderID = id;
        customerName = name;
        amount = a;
        left = right = NULL;
    }
};
class OrderHeap {
private:
    Order* heap[100];
    int size;
public:
    OrderHeap() {
        size = 0;
    }
    void heapifyUp(int i) {
        while (i > 0) {
            int parent = (i - 1) / 2;
            if (heap[i]->amount > heap[parent]->amount) {
                swap(heap[i], heap[parent]);
                i = parent;
            }
            else
                break;
        }
    }
    void insertOrder(int id, string name, int amount) {
        heap[size] = new Order(id, name, amount);
        heapifyUp(size);
        size++;
    }
    void heapifyDown(int i) {
        while (true) {
            int largest = i;
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            if (left < size &&
                heap[left]->amount > heap[largest]->amount)
                largest = left;
            if (right < size &&
                heap[right]->amount > heap[largest]->amount)
                largest = right;
            if (largest != i) {
                swap(heap[i], heap[largest]);
                i = largest;
            }
            else
                break;
        }
    }
    void heapSort() {
        int sorted[100];
        int originalSize = size;
        cout << "\nDeleting Orders:\n";
        for (int i = originalSize - 1; i >= 0; i--) {
            sorted[i] = heap[0]->amount;
            cout << "Deleted Order: "
                 << heap[0]->orderID
                 << " | Amount: " << heap[0]->amount << endl;
            delete heap[0];
            heap[0] = heap[size - 1];
            size--;
            if (size > 0)
                heapifyDown(0);
        }
        cout << "\nAscending Order Amounts:\n";
        for (int i = 0; i < originalSize; i++) {
            cout << sorted[i] << " ";
        }
        cout << endl;
    }
    ~OrderHeap() {
        for (int i = 0; i < size; i++)
            delete heap[i];
    }
};
int main() {
    OrderHeap o;
    o.insertOrder(301, "Ali", 5000);
    o.insertOrder(302, "Ahmed", 2500);
    o.insertOrder(303, "Sara", 8000);
    o.insertOrder(304, "Ayesha", 1500);
    o.insertOrder(305, "Usman", 6000);
    o.insertOrder(306, "Hina", 3500);
    o.heapSort();
    return 0;
}
