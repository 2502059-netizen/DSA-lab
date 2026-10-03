#include <iostream>
using namespace std;
class Node
{
public:
    int roll;
    string name;
    string status;
    Node* next;
};
int main()
{
    Node* head=NULL;
    Node* current;
    int choice,roll;
    string name,status;
    while(true){
        cout<<endl;
        cout<<"1. Add Student"<<endl;
        cout<<"2. Search Student"<<endl;
        cout<<"3. Delete Student"<<endl;
        cout<<"4. Display Students"<<endl;
        cout<<"5. Count Present Students"<<endl;
        cout<<"6. Exit"<<endl;
        cout<<"Enter choice: ";
        cin>>choice;
        if(choice==1){
            Node* newNode=new Node();
            cout<<"Enter Roll Number: ";
            cin>>newNode->roll;
            cout<<"Enter Student Name: ";
            cin>>newNode->name;
            cout<<"Enter Attendance Status: ";
            cin>>newNode->status;
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
            cout<<"Student added."<<endl;
        }
        else if(choice==2){
            cout<<"Enter Roll Number: ";
            cin>>roll;
            current=head;
            while(current!=NULL){
                if(current->roll==roll)
                    break;
                current=current->next;
            }
            if(current==NULL){
                cout<<"Student not found."<<endl;
            }
            else{
                cout<<"Student Found"<<endl;
                cout<<"Roll Number: "<<current->roll<<endl;
                cout<<"Name: "<<current->name<<endl;
                cout<<"Attendance: "<<current->status<<endl;
            }
        }
        else if(choice==3){
            cout<<"Enter Roll Number to delete: ";
            cin>>roll;
            current=head;
            Node* prev=NULL;
            while(current!=NULL){
                if(current->roll==roll)
                    break;
                prev=current;
                current=current->next;
            }
            if(current==NULL){
                cout<<"Student not found."<<endl;
            }
            else{
                if(prev==NULL){
                    head=head->next;
                }
                else{
                    prev->next=current->next;
                }
                delete current;
                cout<<"Student deleted."<<endl;
            }
        }
        else if(choice==4){
            cout<<"Attendance List:"<<endl;
            current=head;
            if(current==NULL){
                cout<<"No students."<<endl;
            }
            while(current!=NULL){
                cout<<current->roll<<" "<<current->name<<" "<<current->status<<endl;
                current=current->next;
            }
        }
        else if(choice==5){
            int count=0;
            current=head;
            while(current!=NULL){
                if(current->status=="Present"||current->status=="present")
                    count++;
                current=current->next;
            }
            cout<<"Total Students Present = "<<count<<endl;
        }
        else if(choice==6){
            break;
        }
        else{
            cout<<"Invalid choice."<<endl;
        }
    }
}