#include <iostream>
using namespace std;
class Node
{
public:
int data;
Node *left, *right;
Node()
{
data = 0;
left = right = NULL;
}
};
class BST
{
public:
Node *root;
int i = 0;
Node *FindMin(Node *);
Node *FindMax(Node *);
Node *Insert(Node *, int);
Node *Delete(Node *, int);
int Search(Node *, int);
void Display(Node *);
int Depth(Node *);
Node *Mirror(Node *);
void LeafNode(Node *);
};
Node* BST :: FindMin(Node *root)
{
if(root == NULL)
{
return NULL;
}
if(root->left)
{
return FindMin(root->left); Name :- Sharvin Pharande
Roll No :- 8022
}
else
{
return root;
}
}
Node* BST :: FindMax(Node *root)
{
if(root==NULL)
{
return NULL;
}
if(root->right)
{
return(FindMax(root->right));
}
else
{
return root;
}
}
Node* BST :: Insert(Node *root, int n)
{
if(root == NULL)
{
Node* temp = new Node();
temp->data = n;
temp->left = NULL;
temp->right = NULL;
return temp;
}
if(n < root->data)
{
root->left = Insert(root->left, n);
}
else if(n > root->data)
{
root->right = Insert(root->right, n);
}
return root;
}
Node* BST :: Delete(Node *root, int n)
{
Node *temp;
if(root == NULL)
{
cout<<"Element not found"<<endl;
}
else if(n < root->data)
{
root->left = Delete(root->left, n);
}
else if(n > root->data)
{
root->right = Delete(root->right, n);
}
else
{
if(root->right != NULL && root->left != NULL)
{
temp = FindMin(root->right);
root->data = temp->data;
root->right = Delete(root->right, temp->data);
}
else
{
temp = root;
if(root->left == NULL)
{
root = root->right;
}
else if(root->right == NULL)
{
root = root->left;
}
free(temp);
}
}
return root;
}
int BST :: Search(Node* root, int n)
{
i = 0;
while (root != NULL)
{ if (n > root->data)
{
i++;
root = root->right;
}
else if (n < root->data)
{
i++;
root = root->left;
}
else
{
i++;
return i;
}
}
cout<<"\nElement not found! ";
return 0;
}
void BST :: Display(Node *root)
{
if(root==NULL)
{
return;
}
Display(root->left);
cout<<root->data<<" ";
Display(root->right);
}
int BST :: Depth(Node *root)
{
if (root == NULL)
return 0;
int l = Depth(root->left);
int r = Depth(root->right);
if (l > r)
return (l + 1);
else
return (r + 1);
}
Node* BST :: Mirror(Node *root)
{
if(root != NULL)
{
Node* temp;
Mirror(root->left);
Mirror(root->right);
temp = root->left;
root->left = root->right;
root->right = temp;
}
return root;
}
void BST :: LeafNode(Node *root)
{
if (root == NULL)
return;
if (root->left == NULL && root->right == NULL)
{
cout<<root->data<<" ";
return;
}
if (root->right != NULL)
LeafNode(root->right);
if (root->left != NULL)
LeafNode(root->left);
}
int main()
{
BST B;
Node *root = NULL, *temp;
int ch, num, z;
cout<<"\n1.Insert";
cout<<"\n2.Delete";
cout<<"\n3.Search(non-recursive)";
cout<<"\n4.Display(Inorder Traversal)";
cout<<"\n5.Display Depth of tree";
cout<<"\n6.Display Mirror Image";
cout<<"\n7.Display Leaf Nodes";
cout<<"\n8.Exit";
do
{
cout<<"\n\nEnter your choice: ";
cin>>ch;
switch(ch)
{
case 1:
cout<<"\nEnter element to be inserted: ";
cin>>num;
root = B.Insert(root, num);
cout<<"\nElements in BST are: ";
B.Display(root);
break;
case 2:
cout<<"\nEnter element to be deleted: ";
cin>>num;
root = B.Delete(root, num);
cout<<"\nAfter deletion elements in BST are: ";
B.Display(root);
break;
case 3:
cout<<"\nEnter element to be searched: ";
cin>>num;
z = 0;
z = B.Search(root, num);
if(z == 0)
{
cout<<"Element not found";
}
else
{
cout<<"Element "<<num<<" is Found at position "<<z<<" from the first node"<<endl;
}
break;
case 4:
cout<<"\nInorder Travesal is: ";
B.Display(root);
break;
case 5:
cout<<"Depth of the BST is "<<B.Depth(root)<<endl;
break;
case 6:
cout<<"\nMirror Image of the BST: ";
root = B.Mirror(root);
B.Display(root);
break;
case 7:
cout<<"\nLeaf nodes in the BST: ";
B.LeafNode(root);
case 8:
break;
default:
cout<<"\nEnter correct choice ";
break;
}
} while(ch != 8);
return 0;
}
