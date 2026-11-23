#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
class Student {
public:
    string name;
    int rollNo, marks;
    Student *left, *right;
    Student(string n, int r, int m) {
        name = n;
        rollNo = r;
        marks = m;
        left = right = NULL;
    }
};
class StudentHeap {
private:
    Student* heap[100];
    int size;
public:
    StudentHeap() {
        size = 0;
    }
    void heapifyUp(int i) {
        while (i > 0) {
            int parent = (i - 1) / 2;
            if (heap[i]->marks > heap[parent]->marks) {
                swap(heap[i], heap[parent]);
                i = parent;
            }
            else
                break;
        }
    }
    void insertStudent(string n, int r, int m) {
        heap[size] = new Student(n, r, m);
        heapifyUp(size);
        size++;
    }
    void heapifyDown(int i) {
        while (true) {
            int largest = i;
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            if (left < size &&
                heap[left]->marks > heap[largest]->marks)
                largest = left;
            if (right < size &&
                heap[right]->marks > heap[largest]->marks)
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
        cout << "\nStudent Heap:\n";
        for (int i = 0; i < size; i++) {
            cout << heap[i]->name
                 << " | Roll: " << heap[i]->rollNo
                 << " | Marks: " << heap[i]->marks << endl;
        }
    }
    void deleteHighest() {
        if (size == 0) {
            cout << "Heap is empty!";
            return;
        }
        cout << "\nDeleted Student: "
             << heap[0]->name
             << " | Marks: " << heap[0]->marks << endl;
        delete heap[0];
        heap[0] = heap[size - 1];
        size--;
        if (size > 0)
            heapifyDown(0);
    }
    ~StudentHeap() {
        for (int i = 0; i < size; i++)
            delete heap[i];
    }
};
int main() {
    StudentHeap s;
    s.insertStudent("Ali", 101, 85);
    s.insertStudent("Ahmed", 102, 92);
    s.insertStudent("Sara", 103, 78);
    s.insertStudent("Ayesha", 104, 96);
    s.insertStudent("Usman", 105, 88);
    s.insertStudent("Hina", 106, 75);
     cout << "Before Deletion:";
    s.display();
    s.deleteHighest();
    cout << "\nAfter Deletion:";
    s.display();
    return 0;
}
