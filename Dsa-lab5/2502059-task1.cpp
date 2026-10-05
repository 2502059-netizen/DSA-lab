#include <iostream>
#include <string>
using namespace std;
class Node
{
public:
    string website;
    Node* prev;
    Node* next;
    Node(string site)
    {
        website = site;
        prev = NULL;
        next = NULL;
    }
};
class BrowserHistory
{
private:
    Node* head;
    Node* tail;

public:
    BrowserHistory()
    {
        head = NULL;
        tail = NULL;
    }
    void addWebsite(string site)
    {
        Node* newNode = new Node(site);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    void displayForward()
    {
        Node* current = head;
        cout << endl;
        cout << "Browser History (First -> Last):" << endl;
        while (current != NULL)
        {
            cout << current->website << endl;
            current = current->next;
        }
    }
    void displayReverse()
    {
        Node* current = tail;
        cout << endl;
        cout << "Browser History (Last -> First):" << endl;
        while (current != NULL)
        {
            cout << current->website << endl;
            current = current->prev;
        }
    }
};
int main()
{
    BrowserHistory history;
    string website;
    cout << "Enter 5 website names:" << endl;
    for (int i = 1; i <= 5; i++)
    {
        cout << "Enter website " << i << ": ";
        cin >> website;
        history.addWebsite(website);
    }
    history.displayForward();
    history.displayReverse();
    cout << endl;
    cout << "Press Enter to exit...";
    cin.ignore();
    cin.get();
    return 0;
}

