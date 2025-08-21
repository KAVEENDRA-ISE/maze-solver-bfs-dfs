#include <stdio.h>
#include <stdlib.h>

#define ROWS 5
#define COLS 5

int maze[ROWS][COLS] = {
    {0, 1, 0, 0, 0},
    {0, 1, 0, 1, 0},
    {0, 0, 0, 1, 0},
    {1, 1, 0, 1, 0},
    {0, 0, 0, 0, 0}
};

int visited[ROWS][COLS];
int dx[] = {-1, 1, 0, 0}; // up, down
int dy[] = {0, 0, -1, 1}; // left, right

// Check if cell is valid
int isValid(int x, int y) {
    return (x >= 0 && x < ROWS && y >= 0 && y < COLS &&
            maze[x][y] == 0 && !visited[x][y]);
}

// DFS Implementation
int DFS(int x, int y, int ex, int ey) {
    if (x == ex && y == ey) {
        printf("Reached End at (%d,%d)\n", x, y);
        return 1;
    }
    visited[x][y] = 1;
    printf("Visiting (%d,%d)\n", x, y);

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (isValid(nx, ny)) {
            if (DFS(nx, ny, ex, ey)) {
                return 1;
            }
        }
    }
    return 0;
}

// BFS Node structure
typedef struct {
    int x, y;
} Node;

Node queue[ROWS * COLS];
int front = 0, rear = 0;

// BFS Implementation
void BFS(int sx, int sy, int ex, int ey) {
    front = rear = 0;
    queue[rear++] = (Node){sx, sy};
    visited[sx][sy] = 1;

    while (front < rear) {
        Node current = queue[front++];
        printf("Visiting (%d,%d)\n", current.x, current.y);

        if (current.x == ex && current.y == ey) {
            printf("Reached End at (%d,%d)\n", ex, ey);
            return;
        }

        for (int i = 0; i < 4; i++) {
            int nx = current.x + dx[i];
            int ny = current.y + dy[i];
            if (isValid(nx, ny)) {
                visited[nx][ny] = 1;
                queue[rear++] = (Node){nx, ny};
            }
        }
    }
    printf("No Path Found!\n");
}

void resetVisited() {
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            visited[i][j] = 0;
}

int main() {
    printf("=== DFS Maze Solver ===\n");
    resetVisited();
    if (!DFS(0, 0, 4, 4))
        printf("No path found using DFS\n");

    printf("\n=== BFS Maze Solver ===\n");
    resetVisited();
    BFS(0, 0, 4, 4);

    return 0;
}
