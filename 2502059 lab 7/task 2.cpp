#include <iostream>
using namespace std;
#define SIZE 5
class CircularQueue {
private:
    int packets[SIZE];
    int front, rear;
public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }
    void enqueue(int packetID) {
        if ((rear + 1) % SIZE == front) {
            cout << "Queue Overflow! Buffer is full.\n";
            return;
        }
        if (front == -1) {
            front = 0;
            rear = 0;
        } else {
            rear = (rear + 1) % SIZE;
        }
        packets[rear] = packetID;
         cout << "Packet " << packetID
             << " added to the buffer.\n";
    }
    void dequeue() {
        if (front == -1) {
            cout << "Queue Underflow! No packets to transmit.\n";
            return;
        }
        cout << "Packet " << packets[front]
             << " transmitted successfully.\n";
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % SIZE;
        }
    }
    void display() {
        if (front == -1) {
            cout << "No packets waiting for transmission.\n";
            return;
        }
        cout << "Packets waiting for transmission: ";
        int i = front;
        while (true) {
            cout << packets[i] << " ";
            if (i == rear) {
                break;
            }
            i = (i + 1) % SIZE;
        }
        cout << endl;
    }
};
int main() {
    CircularQueue q;
    int choice, packetID;
    do {
        cout << "\n--- Network Packet Management ---\n";
        cout << "1. Insert Packet\n";
        cout << "2. Transmit Packet\n";
        cout << "3. Display Waiting Packets\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter packet ID: ";
            cin >> packetID;
            q.enqueue(packetID);
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            q.display();
            break;
        case 4:
            cout << "Exiting Network Packet Management.\n";
            break;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 4);
    return 0;
}
