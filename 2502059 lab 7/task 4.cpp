#include <iostream>
using namespace std;
#define SIZE 5
class Deque {
private:
    int requests[SIZE];
    int front, rear, count;
public:
    Deque() {
        front = -1;
        rear = -1;
        count = 0;
    }

    void insertFront(int id) {
        if (count == SIZE) {
            cout << "Deque Overflow! Queue is full.\n";
            return;
        }
        if (count == 0) {
            front = rear = 0;
        } else {
            front = (front - 1 + SIZE) % SIZE;
        }
        requests[front] = id;
        count++;
        cout << "Request " << id
             << " inserted at the front.\n";
    }

    void insertRear(int id) {
        if (count == SIZE) {
            cout << "Deque Overflow! Queue is full.\n";
            return;
        }
        if (count == 0) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % SIZE;
        }
        requests[rear] = id;
        count++;
        cout << "Request " << id
             << " inserted at the rear.\n";
    }
    void deleteFront() {
        if (count == 0) {
            cout << "Deque Underflow! No requests available.\n";
            return;
        }
        cout << "Request " << requests[front]
             << " removed from the front.\n";
        if (count == 1) {
            front = rear = -1;
        } else {
            front = (front + 1) % SIZE;
        }

        count--;
    }
    void deleteRear() {
        if (count == 0) {
            cout << "Deque Underflow! No requests available.\n";
            return;
        }
        cout << "Request " << requests[rear]
             << " removed from the rear.\n";
        if (count == 1) {
            front = rear = -1;
        } else {
            rear = (rear - 1 + SIZE) % SIZE;
        }
        count--;
    }
    void display() {
        if (count == 0) {
            cout << "Deque is empty.\n";
            return;
        }
        cout << "Requests: Front -> ";
        int i = front;
        for (int j = 0; j < count; j++) {
            cout << requests[i] << " ";
            i = (i + 1) % SIZE;
        }
        cout << "<- Rear\n";
    }
};
int main() {
    Deque dq;
    int choice, id;
    do {
        cout << "\n--- Train Station Passenger Management ---\n";
        cout << "1. Insert at Front\n";
        cout << "2. Insert at Rear\n";
        cout << "3. Remove from Front\n";
        cout << "4. Remove from Rear\n";
        cout << "5. Display Requests\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter passenger request ID: ";
            cin >> id;
            dq.insertFront(id);
            break;
        case 2:
            cout << "Enter passenger request ID: ";
            cin >> id;
            dq.insertRear(id);
            break;
        case 3:
            dq.deleteFront();
            break;
        case 4:
            dq.deleteRear();
            break;
        case 5 :
            dq.display();
            break;
        case 6:
            cout << "Exiting Train Station System.\n";
            break;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 6);
    return 0;
}
