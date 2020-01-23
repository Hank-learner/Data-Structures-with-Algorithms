#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
using namespace std;

struct node{
int data;
node *next;
node *prev;
}*list=NULL,*pist=NULL,*tist=NULL;

node *insert(node *list,int a){

node *temp,*t=list;
temp=(node*)malloc(sizeof(node));
temp->data=a;
temp->next=NULL;
temp->prev=NULL;

if(list==NULL){
temp->next=NULL;
temp->prev=NULL;
list=temp;
}
else{
while(t->next!=NULL)
t=t->next;
t->next=temp;
temp->prev=t;
}

return list;
}


void display(node *list){
node *t=list;
cout<<"the list : ";

	if(list==NULL)
	cout<<"empty"<<endl;
	else{
	while(t!=NULL){
	cout<<t->data<<" ";
	t=t->next;
	}
	}
cout<<endl;
}


void reverse(node *list){
node *t=list;
	if(list==NULL)
	cout<<"empty"<<endl;

	else{
	while(t->next!=NULL)
	t=t->next;
	while(t->prev!=NULL){
	 cout<<t->data<<" ";
	 t=t->prev;
	}
	cout<<t->data;
	}
}


int count(node *list){
node *t=list;
int count=0;
	if(list==NULL)
	cout<<"empty"<<endl;
	else{
	while(t->next!=NULL){
	t=t->next;
	count++;
	}
	count++;
	}


cout<<"number of linked lists are :"<<count<<endl;
return(count);
}



void split(node *list){
int nodes,flag=0;
node *t=list;
nodes=count(list);
	if(list==NULL)
	cout<<"Empty list"<<endl;
	else{
	while(t->next!=NULL){
	t=t->next;
	++flag;
	if(flag>=nodes/2)
	pist=insert(pist,t->data);
	}

	t=list;
	flag=0;

	while(t->next!=NULL){
	++flag;
	if(flag<=nodes/2)
	tist=insert(tist,t->data);
	t=t->next;
	}
	}

display(tist);
display(pist);
}


int main(){
int i,a,n,option,nodes;
char choice;
cout<<"enter total set of lists : ";
cin>>n;
cout<<"enter the values one by one for each list : "<<endl;

for(i=0;i<n;++i){
cin>>a;
list=insert(list,a);
}

display(list);

do{
cout<<endl;
cout<<"1 for reverse"<<endl;
cout<<"2 for count"<<endl;
cout<<"3 for split"<<endl;
cout<<"enter your choice : ";
cin>>option;
switch(option){
case 1:reverse(list);break;
case 2:nodes=count(list);break;
case 3:split(list);break;
default:cout<<"enter correct number in choice ;";break;
}
cout<<endl;
cout<<"again? (y) : "<<endl;
cin>>choice;
}while(choice=='y');

}
