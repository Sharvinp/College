#include <iostream>
using namespace std;
class Node
{
public:
int lbit, rbit;
int value;
Node *left, *right;
Node()
{
lbit = rbit = 0;
value = 0;
left = right = NULL;
}
};
class ThreadedBinaryTree
{
public:
Node* root;
ThreadedBinaryTree()
{
root = new Node();
root->value = 0;
root->rbit = 1;
root->lbit = 0;
root->left = root;
root->right = root;
}
void create();
void insert(int value);
void preorder();
Node* preorderSuccessor(Node*);
void inorder();
Node* inorderSuccessor(Node*);
};
void ThreadedBinaryTree :: insert(int data)
Name :- Sharvin Pharande
Roll No :- 8022
DSA Lab Assignment No 6 (TBT)

{
if (root->left == root && root->right == root)
{
Node* temp = new Node();
temp->value = data;
temp->left = root->left;
temp->lbit = root->lbit;
temp->rbit = 0;
temp->right = root->right;
root->left = temp;
root->lbit = 1;
return;
}
Node* cur = new Node;
cur = root->left;
while (1)
{
if (cur->value < data)
{
Node* p = new Node();
p->value = data;
if (cur->rbit == 0)
{
p->right = cur->right;
p->rbit = cur->rbit;
p->lbit = 0;
p->left = cur;
cur->rbit = 1;
cur->right = p;
return;
}
else
cur = cur->right;

}
if (cur->value > data) {
Node* p = new Node();
p->value = data;
if (cur->lbit == 0) {
p->left = cur->left;
p->lbit = cur->lbit;
p->rbit = 0;
p->right = cur;
cur->lbit = 1;

cur->left = p;
return;
}
else
cur = cur->left;

}
}
}
void ThreadedBinaryTree :: preorder()
{
Node* c = root->left;
while (c != root) {
cout << " " << c->value;
c = preorderSuccessor(c);
}
}
Node* ThreadedBinaryTree :: preorderSuccessor(Node* c)
{
if (c->lbit == 1) {
return c->left;
}
while (c->rbit == 0) {
c = c->right;
}
return c->right;
}
void ThreadedBinaryTree :: inorder()
{
Node* c;
c = root->left;
while (c->lbit == 1)
c = c->left;
while (c != root)
{
cout << " " << c->value;
c = inorderSuccessor(c);
}
}
Node* ThreadedBinaryTree :: inorderSuccessor(Node* c)
{
if (c->rbit == 0)
return c->right;

else
c = c->right;
while (c->lbit == 1) {
c = c->left;
}
return c;
}
int main()
{
int n, i;
int val;
ThreadedBinaryTree tbt;
cout<<"Enter how many elements to insert: ";
cin>>n;
for(i=0; i<n; i++)
{
cout<<"Enter element "<<i+1<<" : ";
cin>>val;
tbt.insert(val);
}
cout<<"Inorder Travesal of Threaded Binary Tree:"<<endl;
tbt.inorder();
cout<<"\nPreorder Travesal of Threaded Binary Tree:"<<endl;
tbt.preorder();
return 0;
}
