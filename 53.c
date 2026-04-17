#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int val) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

struct QNode {
    struct Node* node;
    int hd;
};

struct Queue {
    int front, rear, size;
    struct QNode* arr;
};

struct Queue* createQueue(int n) {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = 0;
    q->rear = -1;
    q->size = n;
    q->arr = (struct QNode*)malloc(n * sizeof(struct QNode));
    return q;
}

void enqueue(struct Queue* q, struct Node* node, int hd) {
    q->arr[++q->rear].node = node;
    q->arr[q->rear].hd = hd;
}

struct QNode dequeue(struct Queue* q) {
    return q->arr[q->front++];
}

int isEmpty(struct Queue* q) {
    return q->front > q->rear;
}

struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct Node* root = newNode(arr[0]);
    struct Node** queue = (struct Node**)malloc(n * sizeof(struct Node*));
    int front = 0, rear = 0;

    queue[rear++] = root;
    int i = 1;

    while (i < n) {
        struct Node* curr = queue[front++];

        if (arr[i] != -1) {
            curr->left = newNode(arr[i]);
            queue[rear++] = curr->left;
        }
        i++;

        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }
    return root;
}

void verticalOrder(struct Node* root) {
    if (!root) return;

    int offset = 100;
    int map[200][100];
    int count[200] = {0};

    struct Queue* q = createQueue(1000);
    enqueue(q, root, 0);

    int minHD = 0, maxHD = 0;

    while (!isEmpty(q)) {
        struct QNode temp = dequeue(q);
        struct Node* node = temp.node;
        int hd = temp.hd;

        int idx = hd + offset;
        map[idx][count[idx]++] = node->data;

        if (hd < minHD) minHD = hd;
        if (hd > maxHD) maxHD = hd;

        if (node->left)
            enqueue(q, node->left, hd - 1);
        if (node->right)
            enqueue(q, node->right, hd + 1);
    }

    for (int i = minHD; i <= maxHD; i++) {
        int idx = i + offset;
        for (int j = 0; j < count[idx]; j++) {
            printf("%d ", map[idx][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);
    verticalOrder(root);

    return 0;
}