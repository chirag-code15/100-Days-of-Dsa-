#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;
int search(int inorder[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value)
            return i;
    }
    return -1;
}

Node* buildTree(int preorder[], int inorder[], int inStart, int inEnd, int* preIndex) {
    if (inStart > inEnd)
        return NULL;

    Node* node = (Node*)malloc(sizeof(Node));
    node->data = preorder[*preIndex];
    node->left = node->right = NULL;
    (*preIndex)++;

    if (inStart == inEnd)
        return node;

    int inIndex = search(inorder, inStart, inEnd, node->data);

    node->left = buildTree(preorder, inorder, inStart, inIndex - 1, preIndex);
    node->right = buildTree(preorder, inorder, inIndex + 1, inEnd, preIndex);

    return node;
}

void postorder(Node* root) {
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main() {
    int n;
    scanf("%d", &n);

    int preorder[n], inorder[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &preorder[i]);

    for (int i = 0; i < n; i++)
        scanf("%d", &inorder[i]);

    int preIndex = 0;

    Node* root = buildTree(preorder, inorder, 0, n - 1, &preIndex);

    postorder(root);

    return 0;
}