#include<bits/stdc++.h>
using namespace std;
struct node{
	int data;
	node *left;
	node *right;
};
node *push(int data)
{
	node *temp=new node;
	temp->left=NULL;
	temp->right=NULL;
	temp->data=data;
	return temp;
}
bool symmetric(node *a,node *b)
{
	if(a==NULL && b==NULL)
		return true;
	if(a==NULL || b==NULL)
		return false;
	return (a->data==b->data)&&symmetric(a->left,b->left)&&symmetric(a->right,b->right);
}


void inorder(node *root)
{
	stack<node*>stck;
	node *curr=root;
	cout<<curr->data;
	while(curr!=NULL)
	{
		cout<<curr->data<<endl;
		if(curr->right)
		stck.push(curr->right);
		if(curr->left)
		stck.push(curr->left);
		if(!stck.empty()){
		node *t=stck.top();
	//	cout<<t->data<<endl;
		stck.pop();
		curr=t;
		}
		else{
			curr=NULL;
	}
}
}



int main()
{
	node *root=push(1);
	root->left=push(2);
	root->left->left=push(3);
	root->left->right=push(4);
	root->right=push(5);
	root->right->left=push(6);
	root->right->right=push(7);
	cout<<root->data;
	inorder(root);
}
