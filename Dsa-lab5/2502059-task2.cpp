
#include <iostream>
using namespace std;

class Node
{
public:
    string name;
    Node* next;

    Node(string n)
    {
        name = n;
        next = NULL;
    }
};

int main()
{
    Node* first = new Node("Ali");
    Node* second = new Node("Ahmed");
    Node* third = new Node("Hassan");
    Node* fourth = new Node("Usman");
    Node* fifth = new Node("Bilal");
    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = first;
    Node* current = first;
    cout << "Player Turns:" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << current->name << "'s turn" << endl;
        current = current->next;
    }
    cout << endl;
    cout << "After the last player:" << endl;
    cout << current->name << "'s turn again" << endl;
    return 0;
}

