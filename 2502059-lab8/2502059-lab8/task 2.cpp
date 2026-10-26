#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node*left;
    Node*right;
    Node(int v){
        data=v;
        left=NULL;
        right=NULL;
    }
};
class BST{
    Node*root;
    Node*insert(Node*n,int v){
        if(n==NULL)
            return new Node(v);
        if(v<n->data)
            n->left=insert(n->left,v);
        else if(v>n->data)
            n->right=insert(n->right,v);
        return n;
    }
    void inorder(Node*n){
        if(n==NULL)
            return;
        inorder(n->left);
        cout<<n->data<<" ";
        inorder(n->right);
    }
public:
    BST(){
        root=NULL;
    }
    void insert(int v){
        root=insert(root,v);
    }
    void display(){
        inorder(root);
        cout<<endl;
    }
};
int main(){
    BST t;
    int a[]={45,25,65,15,35,55,75};
    for(int i=0;i<7;i++)
        t.insert(a[i]);
    int x,y;
    cout<<"Enter two roll numbers: ";
    cin>>x>>y;
    t.insert(x);
    t.insert(y);
    cout<<"Roll numbers in ascending order: ";
    t.display();
    return 0;
}

