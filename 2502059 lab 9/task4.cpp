#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
class Medicine {
public:
    string name;
    int medicineID, expiryDate;
    Medicine *left, *right;
    Medicine(string n, int id, int date) {
        name = n;
        medicineID = id;
        expiryDate = date;
        left = right = NULL;
    }
};
class MedicineHeap {
private:
    Medicine* heap[100];
    int size;
public:
    MedicineHeap() {
        size = 0;
    }
    void heapifyUp(int i) {
        while (i > 0) {
            int parent = (i - 1) / 2;
            if (heap[i]->expiryDate < heap[parent]->expiryDate) {
                swap(heap[i], heap[parent]);
                i = parent;
            }
            else
                break;
        }
    }
    void insertMedicine(string n, int id, int date) {
        heap[size] = new Medicine(n, id, date);
        heapifyUp(size);
        size++;
    }
    void heapifyDown(int i) {
        while (true) {
            int smallest = i;
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            if (left < size &&
                heap[left]->expiryDate < heap[smallest]->expiryDate)
                smallest = left;
            if (right < size &&
                heap[right]->expiryDate < heap[smallest]->expiryDate)
                smallest = right;
            if (smallest != i) {
                swap(heap[i], heap[smallest]);
                i = smallest;
            }
            else
                break;
        }
    }
    void display() {
        cout << "\nMedicine Heap:\n";
        for (int i = 0; i < size; i++) {
            cout << heap[i]->name
                 << " | ID: " << heap[i]->medicineID
                 << " | Expiry: " << heap[i]->expiryDate << endl;
        }
    }
    void deleteNearestExpiry() {
        if (size == 0) {
            cout << "No medicines available!";
            return;
        }
        cout << "\nMedicine with Nearest Expiry:\n";
        cout << heap[0]->name
             << " | ID: " << heap[0]->medicineID
             << " | Expiry: " << heap[0]->expiryDate << endl;

        delete heap[0];
        heap[0] = heap[size - 1];
        size--;
        if (size > 0)
            heapifyDown(0);
    }
    ~MedicineHeap() {
        for (int i = 0; i < size; i++)
            delete heap[i];
    }
};
int main() {
    MedicineHeap m;
    m.insertMedicine("Panadol", 401, 20271215);
    m.insertMedicine("Brufen", 402, 20261130);
    m.insertMedicine("Augmentin", 403, 20280320);
    m.insertMedicine("Calpol", 404, 20261210);
    m.insertMedicine("Disprin", 405, 20270515);
    m.insertMedicine("VitaminC", 406, 20270125);
    cout << "Before Deletion:";
    m.display();
    m.deleteNearestExpiry();
    cout << "\nAfter Deletion:";
    m.display();
    return 0;
}
