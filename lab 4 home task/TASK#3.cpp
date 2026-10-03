#include <iostream>
using namespace std;
class Node
{
public:
    int id;
    string name;
    string food;
    Node* next;
};
int main()
{
    Node* head=NULL;
    Node* current;
    int choice,id;
    string name,food;
    while(true){
        cout<<endl;
        cout<<"1. Add Order"<<endl;
        cout<<"2. Display Orders"<<endl;
        cout<<"3. Search Order"<<endl;
        cout<<"4. Remove Order"<<endl;
        cout<<"5. Add Urgent Order"<<endl;
        cout<<"6. Exit"<<endl;
        cout<<"Enter choice: ";
        cin>>choice;
        if(choice==1){
            Node* newNode=new Node();
            cout<<"Enter Order ID: ";
            cin>>newNode->id;
            cout<<"Enter Customer Name: ";
            cin>>newNode->name;
            cout<<"Enter Food Item: ";
            cin>>newNode->food;
            newNode->next=NULL;
            if(head==NULL){
                head=newNode;
            }
            else{
                current=head;
                while(current->next!=NULL){
                    current=current->next;
                }
                current->next=newNode;
            }
            cout<<"Order added."<<endl;
        }
        else if(choice==2){
            cout<<"Pending Orders:"<<endl;
            current=head;
            if(current==NULL){
                cout<<"No pending orders."<<endl;
            }
            while(current!=NULL){
                cout<<"O"<<current->id<<" "<<current->name<<" "<<current->food<<endl;
                current=current->next;
            }
        }
        else if(choice==3){
            cout<<"Enter Order ID: ";
            cin>>id;
            current=head;
            while(current!=NULL){
                if(current->id==id)
                    break;
                current=current->next;
            }
            if(current==NULL){
                cout<<"Order not found."<<endl;
            }
            else{
                cout<<"Order Found"<<endl;
                cout<<"Order ID: O"<<current->id<<endl;
                cout<<"Customer: "<<current->name<<endl;
                cout<<"Food: "<<current->food<<endl;
            }
        }
        else if(choice==4){
            cout<<"Enter Order ID to remove: ";
            cin>>id;
            current=head;
            Node* prev=NULL;
            while(current!=NULL){
                if(current->id==id)
                    break;
                prev=current;
                current=current->next;
            }
            if(current==NULL){
                cout<<"Order not found."<<endl;
            }
            else{
                if(prev==NULL){
                    head=head->next;
                }
                else{
                    prev->next=current->next;
                }
                delete current;
                cout<<"Order delivered and removed."<<endl;
            }
        }
        else if(choice==5){
            Node* newNode=new Node();
            cout<<"Enter Urgent Order ID: ";
            cin>>newNode->id;
            cout<<"Enter Customer Name: ";
            cin>>newNode->name;
            cout<<"Enter Food Item: ";
            cin>>newNode->food;
            newNode->next=head;
            head=newNode;
            cout<<"Urgent order added."<<endl;
        }
        else if(choice==6){
            break;
        }
        else{
            cout<<"Invalid choice."<<endl;
        }
    }
}