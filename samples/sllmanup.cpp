#include <bits/stdc++.h>
using namespace std;

struct node{
int data;
node *next;
};

node *insert (node *list,int data){
node *temp=(node*)malloc(sizeof(node));
temp->data=data;
temp->next=NULL;

if(list==NULL){
list=temp;
return list;
}
node *t=NULL;
t=list;
while(t->next!=NULL)
t=t->next;
t->next=temp;

return list;
}

void display(node *list){
cout<<"the list elements are : ";

if(list==NULL)
cout<<"empty"<<endl;
else{
node *t=NULL;
t=list;
while(t!=NULL){
cout<<t->data<<" ";
t=t->next;
}
}
cout<<endl;
}

node *append(node *a,node* b){
node *t=a;

while(t->next!=NULL){
	t=t->next;}
t->next=b;
b=NULL;
return a;

}

void sort (node *list){
if(list==NULL){
cout<<"empty list";
}else{
node *ptr1,*ptr;
ptr1=ptr=NULL;
int swapped=0;

do{
swapped=0;
ptr1=list;

while(ptr1->next!=ptr){
if(ptr1->data>ptr1->next->data){
int temp=ptr1->data;
ptr1->data=ptr1->next->data;
ptr1->next->data=temp;
swapped=1;
}
ptr1=ptr1->next;
}
ptr=ptr1;
}while(swapped);
}
}

void alternatesplit(node* list){
node *a=NULL;
node *b=NULL;
node *t=list;
int flag=-1;
while(t!=NULL){
if(flag==-1)
a=insert(a,t->data);
else
b=insert(b,t->data);
flag*=-1;
t=t->next;

}
cout<<endl<<"the first list : ";
display(a);
cout<<endl<<"the second list : ";
display(b);
}

int main(){

char choice;
node *list=NULL;
node *b=NULL;

cout<<endl;
cout<<"Enter the values for choice : "<<endl;
cout<<"1 for insert"<<endl;
cout<<"2 for sort"<<endl;
cout<<"3 for split"<<endl;
cout<<"4 for append"<<endl;
cout<<"5 for display"<<endl;
cout<<"0 for exit"<<endl;

do{

cout<<"enter your choice : ";
cin>>choice;
switch(choice){
case '0':
break;
case '1':
int data;
cout<<"value to insert:";
cin>>data;
list=insert(list,data);
cout<<"Inserted";
break;
case '2':
sort(list);
cout<<"list sorted"<<endl;
break;
case '3':
alternatesplit(list);
break;
case '4':
char ch;
int dataval;
cout<<"Enter elements of second list to insert"<<endl;
do{
cout<<"Enter element to insert : ";
cin>>dataval;
b=insert(b,dataval);
cout<<"Enter another data in the list? y?";
cin>>ch;
}while(ch=='y');
cout<<"the second new list :";
display(b); 
list=append(list,b);
cout<<"second list appended"<<endl;
break;
case '5':
display(list);
break;
default:
cout<<"invalid number in choice ;";
break;
}
}while(choice!='0');

cout<<endl;
return 0;
}
