#include <stdio.h>
#include <iostream>
using namespace std;
#define size 5

void printmatrix(int arr[size][size]) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void warshall(int graph[size][size]) {
    int reach[size][size], i, j, k;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            reach[i][j] = graph[i][j];
        }
    }

    for (int k = 0; k < size; k++) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                reach[i][j] = reach[i][j] || (reach[i][k] && reach[k][j]);
            }
        }
        cout << "P" << k + 1 << " matrix : " << endl;
        printmatrix(reach);
        cout << endl;
    }
}

int main() {
    int graph[size][size] = {{0, 1, 1, 0, 0}, {0, 0, 0, 1, 0}, {0, 0, 0, 1, 1}, {0, 0, 0, 0, 1}, {0, 1, 0, 0, 0}};
    warshall(graph);
    return 0;
}
