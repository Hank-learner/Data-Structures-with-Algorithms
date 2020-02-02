#include <stdio.h>

#define N 8
int board[N][N];

bool safety(int row, int col) {
    int i, j;
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;

    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

bool queenposition(int col) {
    if (col >= N)
        return true;

    for (int i = 0; i < N; i++) {
        if (safety(i, col)) {
            board[i][col] = 1;
            if (queenposition(col + 1))
                return true;
            board[i][col] = 0;
        }
    }
    return false;
}

int main() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            board[i][j] = 0;
        }
    }

    queenposition(0);

    printf("the Queens can be placed on 1's like : \n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf(" %d ", board[i][j]);
        printf("\n");
    }

    return 0;
}
