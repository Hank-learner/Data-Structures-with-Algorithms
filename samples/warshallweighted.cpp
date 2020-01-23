#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define V 4
#define inf 99999

void printSolution(int dist[][V]){
    for (int i = 0; i < V; i++){
        for (int j = 0; j < V; j++){
            if (dist[i][j] == inf)
                cout << "inf"<< "   ";
            else
                cout << dist[i][j] << "   ";
        }
        cout << endl;
    }
}

void floydWarshall(int graph[][V]){
int dist[V][V], i, j, k;
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            dist[i][j] = graph[i][j];

    for (k = 0; k < V; k++){
        for (i = 0; i < V; i++){
            for (j = 0; j < V; j++){
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    printSolution(dist);
}

int main(){
int graph[V][V] = {{0,1,inf,inf},{inf,0,2,inf},{inf,inf,0,3},{4,7,inf,0}};
floydWarshall(graph);
return 0;
}
