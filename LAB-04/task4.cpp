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

class CourseEnrollment {
private:
    Node* head;
public:
    CourseEnrollment() {
        head = NULL;
    }
    void insertAtBeginning(int roll) {
        Node* newNode = new Node(roll);
        newNode->next = head;
        head = newNode;
    }
    void insertAtEnd(int roll) {
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
    void display() const {
        if (head == NULL) {
            cout << "No students enrolled." << endl;
            return;
        }
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
    ~CourseEnrollment() {
        Node* current = head;
        while (current != NULL) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
};

int main() {
    CourseEnrollment course;
    int count, roll, frontRoll, searchRoll;
    cout << "Enter initial number of students: ";
    cin >> count;
    for (int i = 0; i < count; i++) {
        cout << "Enter Roll Number " << (i + 1) << ": ";
        cin >> roll;
        course.insertAtEnd(roll);
    }
    cout << "\nInitially:\n";
    course.display();
    cout << "\nEnter Roll Number to insert at beginning: ";
    cin >> frontRoll;
    course.insertAtBeginning(frontRoll);
    cout << "\nAfter insertion:\n";
    course.display();
    cout << "\nEnter Roll Number to Search: ";
    cin >> searchRoll;
    if (course.searchStudent(searchRoll)) {
        cout << "Student Found" << endl;
    } else {
        cout << "Student Not Found" << endl;
    }
    return 0;
}