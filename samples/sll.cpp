#include<stdio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;

struct Node{
int data;
struct Node *prev,*next;
};

void printlist(struct Node* head){
struct Node* ptr=head;
while(ptr){
cout<<ptr->data;
ptr=ptr->next;
}
cout<<endl;
}

void push(struct Node** head,int data){
struct Node* newnode=(struct Node*)malloc(sizeof(Node));
newnode->data=data;
newnode->next=*head;
*head=newnode;

}

void movenode(struct Node** destref,struct Node** sourceref){
struct Node *newnode=* sourceref;
*sourceref=(*sourceref)->next;
newnode->next=*destref;
*destref=newnode;
}

void as(struct Node* source,struct Node** araf,struct Node** bref){
struct Node *a=NULL;
struct Node *b=NULL;
Node *current=source;
while(current!=NULL){
movenode(&b,&current);
}
*araf=a;
*bref=b;
}

int main(){
int info=0,n=0,i;
struct Node* head=NULL;
cout<<"Number of nodes : ";
cin>>n;
for(i=n-1;i>=0;i--){
cout<<"Number node val : ";
cin>>info;
push(&head,info);
}
struct Node *a=NULL,*b=NULL;
as(head,&a,&b);
cout<<"first list node values : ";
printlist(a);
cout<<"second list node values : ";
printlist(b);
return 0;
}




















