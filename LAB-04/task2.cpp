#include <iostream>
#include <string>
using namespace std;

struct Node {
    string patientID;
    Node* next;

    Node(string id) {
        patientID = id;
        next = NULL;
    }
};

class PatientQueue {
private:
    Node* head;

public:
    PatientQueue() {
        head = NULL;
    }

    // 1. Add a new patient at the end of the list
    void addPatient(string id) {
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

    // 2. Remove the first patient (Doctor attends the patient)
    void servePatient() {
        if (head == NULL) {
            cout << "No patients in queue." << endl;
            return;
        }
        Node* temp = head;
        cout << "Patient " << temp->patientID << " is being served." << endl;
        head = head->next;
        delete temp;
    }

    // 3. Display all patients waiting
    void displayQueue() const {
        if (head == NULL) {
            cout << "Queue is empty." << endl;
            return;
        }
        Node* current = head;
        while (current != NULL) {
            cout << current->patientID;
            if (current->next != NULL) {
                cout << " -> ";
            }
            current = current->next;
        }
        cout << endl;
    }

    // Destructor to prevent memory leaks
    ~PatientQueue() {
        Node* current = head;
        while (current != NULL) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
};

int main() {
    PatientQueue queue;

    // Adding patients to the queue
    queue.addPatient("P101");
    queue.addPatient("P102");
    queue.addPatient("P103");
    queue.addPatient("P104");

    cout << "Waiting Patients:" << endl;
    queue.displayQueue();

    cout << endl;
    
    // Doctor serves the first patient
    queue.servePatient();

    cout << "\nUpdated Queue:" << endl;
    queue.displayQueue();

    return 0;
}