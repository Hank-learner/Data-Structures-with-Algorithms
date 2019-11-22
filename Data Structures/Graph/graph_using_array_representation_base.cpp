#include<iostream>
using namespace std;
#define size 4


void printmatrix(int arr[size][size]){
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    int graph[size][size]={{0,1,0,1},{0,0,1,0},{0,0,0,0},{0,0,0,0}};
    printmatrix(graph);
    return 0;
}
