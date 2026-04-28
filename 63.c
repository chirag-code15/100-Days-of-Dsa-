#include <stdio.h>
#include <stdlib.h>

struct Node {
    int vertex;
    struct Node* next;
};

struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

void dfs(int node, struct Node* adj[], int visited[]) {
    visited[node] = 1;
    printf("%d ", node);

    struct Node* temp = adj[node];
    while (temp != NULL) {
        int neighbor = temp->vertex;
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited);
        }
        temp = temp->next;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    struct Node* adj[n];
    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
    }

    for (int i = 0; i < n; i++) {
        int k;
        scanf("%d", &k);

        struct Node* tail = NULL;

        for (int j = 0; j < k; j++) {
            int v;
            scanf("%d", &v);

            struct Node* newNode = createNode(v);

            if (adj[i] == NULL) {
                adj[i] = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
        }
    }

    int s;
    scanf("%d", &s);

    int visited[n];
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    dfs(s, adj, visited);

    return 0;
}