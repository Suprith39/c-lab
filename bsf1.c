#include <stdio.h>

void bfs(int a[10][10], int n, int u, int s[]) {
    int f, r, q[10], v;

    printf("The nodes visited from %d: ", u);
    f = 0;
    r = -1;       // Queue empty
    q[++r] = u;   // Insert u into Q
    s[u] = 1;     // Mark u as visited
    printf("%d ", u); // Print node visited

    while (f <= r) {
        u = q[f++]; // Dequeue an element from Q
        for (v = 0; v < n; v++) {
            if (a[u][v] == 1 && s[v] == 0) { // If v is adjacent and not visited
                printf("%d ", v); // Print the node visited
                s[v] = 1;         // Mark v as visited
                q[++r] = v;       // Enqueue v
            }
        }
    }
    printf("\n");
}

int main() {
    int n, a[10][10], source, i, j;
    int s[10] = {0}; // Initialize all elements to 0 (no node visited)

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter the starting node for BFS traversal: ");
    scanf("%d", &source);

    bfs(a, n, source, s);

    return 0;
}
