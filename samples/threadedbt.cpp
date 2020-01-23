#include<iostream>
#include<sstream>
#include<stdio.h>
#include<algorithm>
using namespace std;

struct Node{
int key;
int is_rchild;
struct Node *left ,*right;
};

struct Node* newnode(int key){
struct Node* temp= new Node;
temp->key=key;
temp->left=temp->right=NULL;
return temp;
}


void create(Node **parent ,int child){
int key;
Node *curr;
scanf("%d",&key);
if(key==-1){
	return;
}
if(*parent !=NULL){
	curr=newnode(key);
	if(child==0){
		curr->right=*parent;
		(*(*parent)).left=curr;
	}else{
		if((*(*parent)).right!=NULL){
			curr->right=(*(*parent)).right;
		}
		(*(*parent)).right=curr;
		(*(*parent)).is_rchild=1;
	}
}
else{
	curr=newnode(key);
	*parent=curr;
}

printf("left child of %d : ",curr->key);
create(&curr,0);
printf("right child of %d : ",curr->key);
create(&curr,1);

}


void preorder(struct Node* root){
Node* curr=root;
	while(curr!=NULL){
		printf("%d  ",curr->key);
		if(curr->left!=NULL){
			curr=curr->left;
		}
		else if(curr->is_rchild==1){
			curr=curr->right;
		}
		else{ 
			while(curr->right!=NULL && curr->is_rchild==0)
				curr=curr->right;
			if(curr->right==NULL){
				break;
			}else{
				curr=curr->right;
			}
			
		}
	}
}

int main(){
struct Node *root=NULL;
create(&root,0);
preorder(root);
cout<<endl;
return 0;
}
