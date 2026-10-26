
#include<iostream>
using namespace std;
class Node{
public:
string name;
Node*left;
Node*right;
Node(string n){
name=n;
left=right=NULL;
}
};
void display(Node*root){
if(root==NULL)return;
cout<<"Person: "<<root->name<<endl;
cout<<"Left Child: "<<(root->left?root->left->name:"None")<<endl;
cout<<"Right Child: "<<(root->right?root->right->name:"None")<<endl<<endl;
display(root->left);
display(root->right);
}
int main(){
Node*root=new Node("Grandfather");
root->left=new Node("Father");
root->right=new Node("Uncle");
root->left->left=new Node("Son");
root->left->right=new Node("Daughter");
root->right->left=new Node("Cousin1");
root->right->right=new Node("Cousin2");
display(root);
return 0;
}

