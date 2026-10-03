#include <iostream>
using namespace std;

class Node
{
public:
    string code;
    string name;
    int credit;
    Node* next;
};

void addBeginning(Node*& head)
{
    Node* newNode=new Node();
    cout<<"Enter Course Code: ";
    cin>>newNode->code;
    cout<<"Enter Course Name: ";
    cin>>newNode->name;
    cout<<"Enter Credit Hours: ";
    cin>>newNode->credit;
    newNode->next=head;
    head=newNode;
    cout<<"Course added."<<endl;
}

void addEnd(Node*& head)
{
    Node* newNode=new Node();
    cout<<"Enter Course Code: ";
    cin>>newNode->code;
    cout<<"Enter Course Name: ";
    cin>>newNode->name;
    cout<<"Enter Credit Hours: ";
    cin>>newNode->credit;
    newNode->next=NULL;
    if(head==NULL){
        head=newNode;
    }
    else{
        Node* current=head;
        while(current->next!=NULL){
            current=current->next;
        }
        current->next=newNode;
    }
    cout<<"Course added."<<endl;
}

void searchCourse(Node* head)
{
    string code;
    cout<<"Enter Course Code: ";
    cin>>code;
    Node* current=head;
    while(current!=NULL){
        if(current->code==code)
            break;
        current=current->next;
    }
    if(current==NULL){
        cout<<"Course not found."<<endl;
    }
    else{
        cout<<"Course Found"<<endl;
        cout<<"Code: "<<current->code<<endl;
        cout<<"Name: "<<current->name<<endl;
        cout<<"Credit Hours: "<<current->credit<<endl;
    }
}

void deleteCourse(Node*& head)
{
    string code;
    cout<<"Enter Course Code to delete: ";
    cin>>code;
    Node* current=head;
    Node* prev=NULL;
    while(current!=NULL){
        if(current->code==code)
            break;
        prev=current;
        current=current->next;
    }
    if(current==NULL){
        cout<<"Course not found."<<endl;
    }
    else{
        if(prev==NULL){
            head=head->next;
        }
        else{
            prev->next=current->next;
        }
        delete current;
        cout<<"Course deleted."<<endl;
    }
}

void display(Node* head)
{
    Node* current=head;
    if(current==NULL){
        cout<<"No courses."<<endl;
    }
    while(current!=NULL){
        cout<<current->code;
        if(current->next!=NULL)
            cout<<" -> ";
        current=current->next;
    }
    cout<<endl;
}

void countCourses(Node* head)
{
    int count=0;
    Node* current=head;
    while(current!=NULL){
        count++;
        current=current->next;
    }
    cout<<"Total Courses = "<<count<<endl;
}

void concatenate(Node*& head1,Node* head2)
{
    if(head1==NULL){
        head1=head2;
        return;
    }
    Node* current=head1;
    while(current->next!=NULL){
        current=current->next;
    }
    current->next=head2;
}

int main()
{
    Node* morning=NULL;
    Node* evening=NULL;
    int choice;
    while(true){
        cout<<endl;
        cout<<"1. Add Course at Beginning"<<endl;
        cout<<"2. Add Course at End"<<endl;
        cout<<"3. Search Course"<<endl;
        cout<<"4. Delete Course"<<endl;
        cout<<"5. Display All Courses"<<endl;
        cout<<"6. Count Total Courses"<<endl;
        cout<<"7. Concatenate Another Course List"<<endl;
        cout<<"8. Exit"<<endl;
        cout<<"Enter choice: ";
        cin>>choice;
        if(choice==1){
            addBeginning(morning);
        }
        else if(choice==2){
            addEnd(morning);
        }
        else if(choice==3){
            searchCourse(morning);
        }
        else if(choice==4){
            deleteCourse(morning);
        }
        else if(choice==5){
            cout<<"Morning Courses:"<<endl;
            display(morning);
        }
        else if(choice==6){
            countCourses(morning);
        }
        else if(choice==7){
            cout<<"Enter Evening Courses:"<<endl;
            int n;
            cout<<"Enter number of courses: ";
            cin>>n;
            for(int i=0;i<n;i++){
                addEnd(evening);
            }
            concatenate(morning,evening);
            cout<<"Combined Course List:"<<endl;
            display(morning);
            evening=NULL;
        }
        else if(choice==8){
            break;
        }
        else{
            cout<<"Invalid choice."<<endl;
        }
    }
}