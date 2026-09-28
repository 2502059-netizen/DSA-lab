#include <iostream>
using namespace std;

struct Node {
    int rollNumber;
    Node* next;
    Node(int roll) {
        rollNumber = roll;
        next = NULL;
    }
};

class StudentList {
private:
    Node* head;
public:
    StudentList() {
        head = NULL;
    }
    void addStudent(int roll) {
        Node* newNode = new Node(roll);
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
    void displayStudents() const {
        if (head == NULL) {
            cout << "No students registered yet.\n";
            return;
        }
        cout << "Registered Students:\n";
        Node* current = head;
        while (current != NULL) {
            cout << current->rollNumber;
            if (current->next != NULL) {
                cout << " -> ";
            }
            current = current->next;
        }
        cout << endl;
    }
    bool searchStudent(int roll) const {
        Node* current = head;
        while (current != NULL) {
            if (current->rollNumber == roll) {
                return true;
            }
            current = current->next;
        }
        return false;
    }
    ~StudentList() {
        Node* current = head;
        while (current != NULL) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
};

int main() {
    StudentList list;
    int count, roll, searchRoll;
    cout << "Enter total number of students to register: ";
    cin >> count;
    for (int i = 0; i < count; i++) {
        cout << "Enter Roll Number " << (i + 1) << ": ";
        cin >> roll;
        list.addStudent(roll);
    }
    cout << endl;
    list.displayStudents();
    cout << "\nEnter Roll Number to Search: ";
    cin >> searchRoll;
    if (list.searchStudent(searchRoll)) {
        cout << "Student Found" << endl;
    } else {
        cout << "Student Not Found" << endl;
    }
    return 0;
}