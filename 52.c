#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data){
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

struct Node* buildTree(int arr[], int n){
    if(n == 0) return NULL;
    struct Node** nodes = (struct Node**)malloc(n * sizeof(struct Node*));
    for(int i = 0; i < n; i++){
        if(arr[i] == -1) nodes[i] = NULL;
        else nodes[i] = newNode(arr[i]);
    }
    for(int i = 0; i < n; i++){
        if(nodes[i] != NULL){
            int l = 2*i + 1;
            int r = 2*i + 2;
            if(l < n) nodes[i]->left = nodes[l];
            if(r < n) nodes[i]->right = nodes[r];
        }
    }
    return nodes[0];
}

struct Node* LCA(struct Node* root, int n1, int n2){
    if(root == NULL) return NULL;
    if(root->data == n1 || root->data == n2) return root;
    struct Node* left = LCA(root->left, n1, n2);
    struct Node* right = LCA(root->right, n1, n2);
    if(left && right) return root;
    return left ? left : right;
}

int main(){
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
    int x, y;
    scanf("%d %d", &x, &y);
    struct Node* root = buildTree(arr, n);
    struct Node* ans = LCA(root, x, y);
    if(ans) printf("%d", ans->data);
    return 0;
}