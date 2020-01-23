#include<iostream>
using namespace std;
#define size 4


void printmatrix(int arr[size][size]){
for(int i=0;i<size;i++){
for(int j=0;j<size;j++){
cout<<arr[i][j]<<" ";
}
cout<<endl;
}
}

void transitiveclosure(int graph[size][size]){
for(int k=0;k<size;k++){
for(int i=0;i<size;i++){
for(int j=0;j<size;j++){
graph[i][j]=graph[i][j] || (graph[i][k]&&graph[k][j]);
}}}
printmatrix(graph);
}

int main(){
int graph[size][size]={{0,1,0,1},{0,0,1,0},{0,0,0,0},{0,0,0,0}};
transitiveclosure(graph);
return 0;
}
