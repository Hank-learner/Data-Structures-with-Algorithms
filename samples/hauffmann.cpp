#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstdlib>
#define maxtreeht 100
using namespace std;

struct Minheapnode{
char data;
unsigned freq;
Minheapnode *left ,*right;
};
struct Minheap{
unsigned size,capacity;
Minheapnode **array;
};

struct Minheapnode *newnode(char data,unsigned freq){
struct Minheapnode *temp=(struct Minheapnode*)malloc(sizeof(struct Minheapnode));

temp->left=NULL;
temp->right=NULL;
temp->data=data;
temp->freq=freq;
return temp;
}

struct Minheap* createminheap(unsigned capacity){
struct Minheap* minheap=(Minheap*)malloc(sizeof(Minheap));
minheap->size=0;
minheap->capacity=capacity;
minheap->array=(struct Minheap**)malloc(struct Minheap->capacity*sizeof(struct Minheapnode*));
return minheap;
}


void swapminheapnode(struct Minheapnode* a,struct Minheapnode *b){
struct Minheapnode *t=*a;
*a=*b;
*b=*t;

}
void minheapify(struct Minheap* minheap,int idx){
int smallest=idx;
int left=2*idx+1;
int right=2*idx+2;

if(left < minheap->size && minheap->array[left]->freq<minheap->array[smallest]->freq){
smallest=left;
}
if(right < minheap->size && minheap->array[right]->freq<minheap->array[smallest]->freq){
smallest=right;
}
if(smallest!=idx){
swapminheapnode(&minheap->array[smallest],&minheap->array[idx]);
minheapify(minheap,smallest);
}
}

int issizeone(struct Minheap* minheap){
return (minheap->size==1);
}

struct Minheapnode* extractmin(struct Minheap* minheap){
struct Minheapnode* temp=minheap->array[0];
minheap->array[0]=minheap->array[minheap->size -1];
--minheap->size;
minheapify(minheap,0);
return temp;
}


void insertminheap(struct Minheap* minheap,struct Minheap* minheapnode){
int i=minheap->size++;
while(i && minheap->freq<minheap->array[(i-1)/2]->freq){
minheap->array[i]=minheap->array[(i-1)/2];
i=(i-1)/2;
}
minheap->array[i]=minheapnode;
}
int main(){
char chars[]={'a','b','c','d'};
int freq[]={3,1,5,7};
return 0;

}

