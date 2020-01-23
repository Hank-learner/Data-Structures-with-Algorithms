#include <stdio.h>
#include <stdlib.h>

#define size 5

void insert_by_priority(int);
void delete_by_priority();
void check(int);

void display_pqueue();

int pri_que[size];
int prique[size];
int front, rear;

int main(){

int n, ch;
printf("\n1 - Insert");
printf("\n2 - Delete");
printf("\n3 - Display");
printf("\n4 - Exit");

front = rear = -1;

while (1){
printf("\nEnter option : ");
scanf("%d", &ch);

switch (ch){

case 1: 
printf("\nEnter value to be inserted : ");
scanf("%d",&n);
insert_by_priority(n);
break;

case 2:
delete_by_priority();
break;

case 3: 
display_pqueue();
break;

case 4: 
exit(0);

default: 
printf("\noption is incorrect, Enter a correct option");
}
}

}

void insert_by_priority(int data){

if (rear >= size - 1){
printf("\nQueue overflow no more elements can be inserted");
return;
}

if ((front == -1) && (rear == -1)){
front++;
rear++;
pri_que[rear] = data;
return;
}
else
check(data);

rear++;
}

void check(int data){

int i,j;
for (i = 0; i <= rear; i++){
if (data >= pri_que[i]){
for (j = rear + 1; j > i; j--){
pri_que[j] = pri_que[j - 1];
}
pri_que[i] = data;
return;
}
}
pri_que[i] = data;
}

void delete_by_priority(){

int i;
if ((front==-1) && (rear==-1)){
printf("\nQueue is empty");
return;
}

//for (i = 0; i <= rear; i++){
//if (data == pri_que[i]){
//for (; i < rear; i++){
//pri_que[i] = pri_que[i + 1];
//}
//pri_que[i] = -99;
rear--;
if (rear == -1)
front = -1;
return;
//}

//}

}

void display_pqueue(){

if ((front == -1) && (rear == -1)){
printf("\nQueue is empty");
return;
}

printf("Priority queue : ");
for (; front <= rear; front++){
printf(" %d ", pri_que[front]);
}
printf("\n");
//printf("Ascending order of queue : ");
//for (front=rear; front >-1; --front){
//printf(" %d ", pri_que[front]);
//}
//printf("\n");
front = 0;
}


