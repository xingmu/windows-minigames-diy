// Simple Minesweeper in C
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 9

typedef struct {
    int m;
    int o;
    int f;
    int n;
} Cell;

Cell board[N][N];
int game_over = 0;
int win = 0;

void init() {
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            board[r][c].m = 0;
            board[r][c].o = 0;
            board[r][c].f = 0;
            board[r][c].n = 0;
        }
    }
    srand((unsigned)time(0));
    int count = 0;
    while (count < 10) {
        int r = rand() % N;
        int c = rand() % N;
        if (!board[r][c].m) {
            board[r][c].m = 1;
            count++;
        }
    }
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            if (board[r][c].m) continue;
            int t = 0;
            for (int dr = -1; dr <= 1; dr++) {
                for (int dc = -1; dc <= 1; dc++) {
                    int nr = r + dr;
                    int nc = c + dc;
                    if (nr >= 0 && nr < N && nc >= 0 && nc < N && board[nr][nc].m) {
                        t++;
                    }
                }
            }
            board[r][c].n = t;
        }
    }
}
void show() {
    printf("  123456789\n +--------+\n");
    for (int r = 0; r < N; r++) {
        printf("%d|", r+1);
        for (int c = 0; c < N; c++) {
            if (board[r][c].f) printf("F");
            else if (!board[r][c].o) printf(".");
            else if (board[r][c].m) printf("*");
            else printf("%d", board[r][c].n);
        }
        printf("|\n");
    }
    printf(" +--------+\n");
}

void reveal(int r, int c) {
    if (r < 0 || r >= N || c < 0 || c >= N) return;
    if (board[r][c].o || board[r][c].f) return;
    board[r][c].o = 1;
    if (board[r][c].m) {
        game_over = 1;
        return;
    }
    if (board[r][c].n == 0) {
        for (int dr = -1; dr <= 1; dr++) {
            for (int dc = -1; dc <= 1; dc++) {
                if (dr != 0 || dc != 0) reveal(r+dr, c+dc);
            }
        }
    }
}

int check_win() {
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            if (!board[r][c].m && !board[r][c].o) return 0;
        }
    }
    return 1;
}

int main() {
    init();
    printf("=== Minesweeper ===\n");
    show();
    while (!game_over && !win) {
        printf("r c (0 flag): ");
        int r, c;
        if (scanf("%d %d", &r, &c) != 2) break;
        if (r == 0 && c >= 1 && c <= 9) {
            board[c-1][(c-1)%9].f = !board[c-1][(c-1)%9].f;
        }
        else if (r >= 1 && r <= 9 && c >= 1 && c <= 9) {
            reveal(r-1, c-1);
            if (check_win()) win = 1;
        }
        show();
    }
    if (game_over) printf("BOOM! Game Over!\n");
    if (win) printf("You Win!\n");
    return 0;
}