
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
class Patient {
public:
    string name;
    int patientID, priority;
    Patient *left, *right;
    Patient(string n, int id, int p) {
        name = n;
        patientID = id;
        priority = p;
        left = right = NULL;
    }
};
class PatientHeap {
private:
    Patient* heap[100];
    int size;
public:
    PatientHeap() {
        size = 0;
    }
    void heapifyUp(int i) {
        while (i > 0) {
            int parent = (i - 1) / 2;
            if (heap[i]->priority > heap[parent]->priority) {
                swap(heap[i], heap[parent]);
                i = parent;
            }
            else
                break;
        }
    }
    void insertPatient(string n, int id, int p) {
        heap[size] = new Patient(n, id, p);
        heapifyUp(size);
        size++;
    }
    void heapifyDown(int i) {
        while (true) {
            int largest = i;
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            if (left < size &&
                heap[left]->priority > heap[largest]->priority)
                largest = left;
            if (right < size &&
                heap[right]->priority > heap[largest]->priority)
                largest = right;
            if (largest != i) {
                swap(heap[i], heap[largest]);
                i = largest;
            }
            else
                break;
        }
    }
    void display() {
        cout << "\nPatient Heap:\n";
        for (int i = 0; i < size; i++) {
            cout << heap[i]->name
                 << " | ID: " << heap[i]->patientID
                 << " | Priority: " << heap[i]->priority << endl;
        }
    }
    void showHighestPriority() {
        if (size == 0) {
            cout << "No patients available!";
            return;
        }
        cout << "\nHighest Priority Patient: "
             << heap[0]->name
             << " | Priority: " << heap[0]->priority << endl;
    }
    void treatPatient() {
        if (size == 0) {
            cout << "No patients to treat!";
            return;
        }
        cout << "\nPatient Treated: "
             << heap[0]->name << endl;
        delete heap[0];
        heap[0] = heap[size - 1];
        size--;
        if (size > 0)
            heapifyDown(0);
    }
    ~PatientHeap() {
        for (int i = 0; i < size; i++)
            delete heap[i];
    }
};
int main() {
    PatientHeap p;
    p.insertPatient("Ali", 201, 5);
    p.insertPatient("Ahmed", 202, 9);
    p.insertPatient("Sara", 203, 3);
    p.insertPatient("Ayesha", 204, 10);
    p.insertPatient("Usman", 205, 7);
    p.insertPatient("Hina", 206, 4);
    cout << "All Patients:";
    p.display();
    p.showHighestPriority();
    p.treatPatient();
    cout << "\nUpdated Patient Heap:";
    p.display();
    p.showHighestPriority();
    return 0;
}
