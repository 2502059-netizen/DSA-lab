#include <iostream>
using namespace std;
class Node
{
public:
    int id;
    string name;
    int age;
    Node* next;
};
int main()
{
    Node* head=NULL;
    Node* current;
    int choice,id,age;
    string name;
    while(true){
        cout<<endl;
        cout<<"1. Add Patient"<<endl;
        cout<<"2. Add Emergency Patient"<<endl;
        cout<<"3. Search Patient"<<endl;
        cout<<"4. Remove Patient"<<endl;
        cout<<"5. Display Patients"<<endl;
        cout<<"6. Exit"<<endl;
        cout<<"Enter choice: ";
        cin>>choice;
        if(choice==1){
            Node* newNode=new Node();
            cout<<"Enter Patient ID: ";
            cin>>newNode->id;
            cout<<"Enter Patient Name: ";
            cin>>newNode->name;
            cout<<"Enter Patient Age: ";
            cin>>newNode->age;
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
            cout<<"Patient added."<<endl;
        }
        else if(choice==2){
            Node* newNode=new Node();
            cout<<"Enter Patient ID: ";
            cin>>newNode->id;
            cout<<"Enter Patient Name: ";
            cin>>newNode->name;
            cout<<"Enter Patient Age: ";
            cin>>newNode->age;
            newNode->next=head;
            head=newNode;
            cout<<"Emergency patient added."<<endl;
        }
        else if(choice==3){
            cout<<"Enter Patient ID: ";
            cin>>id;
            current=head;
            while(current!=NULL){
                if(current->id==id)
                    break;
                current=current->next;
            }
            if(current==NULL){
                cout<<"Patient not found."<<endl;
            }
            else{
                cout<<"Patient Found"<<endl;
                cout<<"ID: "<<current->id<<endl;
                cout<<"Name: "<<current->name<<endl;
                cout<<"Age: "<<current->age<<endl;
            }
        }
        else if(choice==4){
            cout<<"Enter Patient ID to remove: ";
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
                cout<<"Patient not found."<<endl;
            }
            else{
                if(prev==NULL){
                    head=head->next;
                }
                else{
                    prev->next=current->next;
                }
                delete current;
                cout<<"Patient removed."<<endl;
            }
        }
        else if(choice==5){
            cout<<"Waiting Patients:"<<endl;
            current=head;
            if(current==NULL){
                cout<<"No patients waiting."<<endl;
            }
            while(current!=NULL){
                cout<<"ID: "<<current->id<<" Name: "<<current->name<<" Age: "<<current->age<<endl;
                current=current->next;
            }
        }
        else if(choice==6){
            break;
        }
        else{
            cout<<"Invalid choice."<<endl;
        }
    }
}