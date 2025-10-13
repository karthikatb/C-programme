#include <stdio.h>
#define MAXV 100  

int adj[MAXV][MAXV]; 
int visited[MAXV];
int queue_arr[MAXV];
int front_idx, rear_idx;
int n; 

void init_queue() {
    front_idx = 0;
    rear_idx = -1;
}

void enqueue(int v) {
    if (rear_idx < MAXV - 1) {
        queue_arr[++rear_idx] = v;
    }
   
}

int dequeue() {
    if (front_idx <= rear_idx) {
        return queue_arr[front_idx++];
    }
    return -1; 
}

int is_queue_empty() {
    return front_idx > rear_idx;
}

void bfs(int start) {
    int u, v;

    
    for (u = 0; u < n; u++) {
        visited[u] = 0;
    }

    
    init_queue();

 
    visited[start] = 1;
    enqueue(start);

    while (!is_queue_empty()) {
        u = dequeue();
        printf("%d ", u);

        for (v = 0; v < n; v++) {
            if (adj[u][v] && !visited[v]) {
                visited[v] = 1;
                enqueue(v);
            }
        }
    }
}

int main() {
    int i, j;
    int start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (%d×%d):\n", n, n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("Enter starting vertex (0 to %d): ", n-1);
    scanf("%d", &start);

    printf("BFS traversal from vertex %d:\n", start);
    bfs(start);
    printf("\n");

    return 0;
}
