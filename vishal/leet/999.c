/* run in terminal : gcc -o vishal/leet/999.c */
#include <stdio.h>
#include <stdlib.h>
int numRookCaptures(char** board, int boardSize, int* boardColSize) {
    int r, c;

    // Find the rook
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[i][j] == 'R') {
                r = i;
                c = j;
            }
        }
    }

    int count = 0;

    // Up
    for (int i = r - 1; i >= 0; i--) {
        if (board[i][c] == 'B')
            break;

        if (board[i][c] == 'p') {
            count++;
            break;
        }
    }

    // Down
    for (int i = r + 1; i < 8; i++) {
        if (board[i][c] == 'B')
            break;

        if (board[i][c] == 'p') {
            count++;
            break;
        }
    }

    // Left
    for (int j = c - 1; j >= 0; j--) {
        if (board[r][j] == 'B')
            break;

        if (board[r][j] == 'p') {
            count++;
            break;
        }
    }

    // Right
    for (int j = c + 1; j < 8; j++) {
        if (board[r][j] == 'B')
            break;

        if (board[r][j] == 'p') {
            count++;
            break;
        }
    }

    return count;
}
int main() {
    char* board[8] = {
        "........",
        "........",
        "...p....",
        "...R...p",
        "........",
        "........",
        "........",
        "........"
    };
    int boardSize = 8;
    int boardColSize[8] = {8, 8, 8, 8, 8, 8, 8, 8};

    int result = numRookCaptures(board, boardSize, boardColSize);
    printf("Number of pawns the rook can capture: %d\n", result);

    return 0;
}
