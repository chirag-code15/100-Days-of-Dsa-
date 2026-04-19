#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *newNode(int val)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

struct Queue
{
    struct Node *arr[1000];
    int front, rear;
};

void initQueue(struct Queue *q)
{
    q->front = q->rear = 0;
}

int isEmpty(struct Queue *q)
{
    return q->front == q->rear;
}

void push(struct Queue *q, struct Node *node)
{
    q->arr[q->rear++] = node;
}

struct Node *pop(struct Queue *q)
{
    return q->arr[q->front++];
}

struct Node *buildTree(int arr[], int n)
{
    if (n == 0 || arr[0] == -1)
        return NULL;

    struct Queue q;
    initQueue(&q);

    struct Node *root = newNode(arr[0]);
    push(&q, root);

    int i = 1;
    while (!isEmpty(&q) && i < n)
    {
        struct Node *curr = pop(&q);

        if (arr[i] != -1)
        {
            curr->left = newNode(arr[i]);
            push(&q, curr->left);
        }
        i++;

        if (i < n && arr[i] != -1)
        {
            curr->right = newNode(arr[i]);
            push(&q, curr->right);
        }
        i++;
    }

    return root;
}

void rightView(struct Node *root)
{
    if (!root)
        return;

    struct Queue q;
    initQueue(&q);
    push(&q, root);

    while (!isEmpty(&q))
    {
        int size = q.rear - q.front;

        for (int i = 0; i < size; i++)
        {
            struct Node *curr = pop(&q);

            if (i == size - 1)
            {
                printf("%d ", curr->data);
            }

            if (curr->left)
                push(&q, curr->left);
            if (curr->right)
                push(&q, curr->right);
        }
    }
}
int main()
{
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node *root = buildTree(arr, n);

    rightView(root);

    return 0;
}