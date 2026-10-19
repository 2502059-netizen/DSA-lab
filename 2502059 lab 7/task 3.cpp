#include <iostream>
using namespace std;
#define SIZE 5
struct Patient {
    string id;
    int priority;
};
class PriorityQueue {
private:
    Patient patients[SIZE];
    int count;
public:
    PriorityQueue() {
        count = 0;
    }
    void enqueue(string id, int priority) {
        if (count == SIZE) {
            cout << "Queue Overflow! Queue is full.\n";
            return;
        }
        patients[count].id = id;
        patients[count].priority = priority;
        count++;
        cout << "Patient " << id
             << " added successfully.\n";
    }
    void dequeue() {
        if (count == 0) {
            cout << "Queue Underflow! No patients waiting.\n";
            return;
        }
        int highest = 0;
        for (int i = 1; i < count; i++) {
            if (patients[i].priority <
                patients[highest].priority) {
                highest = i;
            }
        }
        cout << "Patient " << patients[highest].id
             << " treated (Priority: "
             << patients[highest].priority << ").\n";
        for (int i = highest; i < count - 1; i++) {
            patients[i] = patients[i + 1];
        }
        count--;
    }
    void display() {
        if (count == 0) {
            cout << "No patients waiting.\n";
            return;
        }
        cout << "\nWaiting Patients:\n";
        cout << "Patient ID\tPriority\n";
        for (int i = 0; i < count; i++) {
            cout << patients[i].id << "\t\t"
                 << patients[i].priority << endl;
        }
    }
};
int main() {
    PriorityQueue pq;
    int choice, priority;
    string id;
    do {
        cout << "\n--- Hospital Emergency Department ---\n";
        cout << "1. Add Patient\n";
        cout << "2. Treat Highest Priority Patient\n";
        cout << "3. Display Waiting Patients\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter patient ID: ";
            cin >> id;
            cout << "Enter priority (1 = highest): ";
            cin >> priority;
            if (priority < 1) {
                cout << "Invalid priority! Use 1 or greater.\n";
            } else {
                pq.enqueue(id, priority);
            }
            break;
        case 2:
            pq.dequeue();
            break;
        case 3:
            pq.display();
            break;
        case 4:
            cout << "Exiting Hospital System.\n";
            break;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 4);
    return 0;
}
