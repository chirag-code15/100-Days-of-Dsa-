#include<stdio.h>
#include<stdlib.h>
struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
struct TreeNode* createNode(int data){
    struct TreeNode* newnode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newnode->val = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}
struct TreeNode* insert(struct TreeNode* root, int data){
    if(root == NULL) return createNode(data);
    if(data < root->val)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    return root;
}
struct TreeNode* LCA(struct TreeNode* root, int p, int q){
    if(root == NULL) return NULL;
    if(p < root->val && q < root->val)
        return LCA(root->left, p, q);
    if(p > root->val && q > root->val)
        return LCA(root->right, p, q);
    return root;
}
int main(){
    int n;
    scanf("%d", &n);
    struct TreeNode* root = NULL;
    for(int i = 0; i < n; i++){
        int x;
        scanf("%d", &x);
        root = insert(root, x);
    }
    int p, q;
    scanf("%d %d", &p, &q);
    struct TreeNode* ans = LCA(root, p, q);
    printf("%d\n", ans->val);
    return 0;
}