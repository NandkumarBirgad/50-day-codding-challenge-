#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 1001

int adj[MAX_NODES][MAX_NODES]; // adjacency matrix
int visited[MAX_NODES];
int distance[MAX_NODES];
int queue[MAX_NODES];
int front = 0, rear = 0;

void enqueue(int node) {
    queue[rear++] = node;
}

int dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front == rear;
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    // Initialize adjacency matrix
    for (int i = 0; i < M; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1; // since undirected
    }

    // Initialize visited and distance arrays
    for (int i = 1; i <= N; i++) {
        visited[i] = 0;
        distance[i] = -1;
    }

    // Start BFS from node 1
    enqueue(1);
    visited[1] = 1;
    distance[1] = 0;

    while (!isEmpty()) {
        int current = dequeue();
        for (int i = 1; i <= N; i++) {
            if (adj[current][i] && !visited[i]) {
                visited[i] = 1;
                distance[i] = distance[current] + 1;
                enqueue(i);
            }
        }
    }

    printf("%d\n", distance[N]);

    return 0;
}