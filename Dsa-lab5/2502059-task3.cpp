
#include <iostream>
using namespace std;

class Node
{
public:
    string imageName;
    Node* next;
    Node* prev;

    Node(string name)
    {
        imageName = name;
        next = NULL;
        prev = NULL;
    }
};

int main()
{
    Node* first = new Node("Image1.jpg");
    Node* second = new Node("Image2.jpg");
    Node* third = new Node("Image3.jpg");
    Node* fourth = new Node("Image4.jpg");
    Node* fifth = new Node("Image5.jpg");

    first->next = second;

    second->prev = first;
    second->next = third;

    third->prev = second;
    third->next = fourth;

    fourth->prev = third;
    fourth->next = fifth;

    fifth->prev = fourth;

    cout << "Images from First to Last:" << endl;

    Node* current = first;

    while (current != NULL)
    {
        cout << current->imageName << endl;
        current = current->next;
    }

    cout << endl;

    cout << "Images from Last to First:" << endl;

    current = fifth;

    while (current != NULL)
    {
        cout << current->imageName << endl;
        current = current->prev;
    }

    return 0;
}

