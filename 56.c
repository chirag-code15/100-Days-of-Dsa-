#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int x) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->val = x;
    node->left = node->right = NULL;
    return node;
}

struct Node* buildTree(int v[], int n) {
    if (n == 0 || v[0] == -1) return NULL;
    struct Node** q = (struct Node**)malloc(n * sizeof(struct Node*));
    int front = 0, rear = 0;
    struct Node* root = newNode(v[0]);
    q[rear++] = root;
    int i = 1;
    while (front < rear && i < n) {
        struct Node* curr = q[front++];
        if (v[i] != -1) {
            curr->left = newNode(v[i]);
            q[rear++] = curr->left;
        }
        i++;
        if (i < n && v[i] != -1) {
            curr->right = newNode(v[i]);
            q[rear++] = curr->right;
        }
        i++;
    }
    free(q);
    return root;
}

int isMirror(struct Node* a, struct Node* b) {
    if (!a && !b) return 1;
    if (!a || !b) return 0;
    if (a->val != b->val) return 0;
    return isMirror(a->left, b->right) && isMirror(a->right, b->left);
}

int main() {
    int n;
    scanf("%d", &n);
    int* v = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) scanf("%d", &v[i]);
    struct Node* root = buildTree(v, n);
    if (isMirror(root, root)) printf("YES");
    else printf("NO");
    free(v);
    return 0;
}