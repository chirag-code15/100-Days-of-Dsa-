#include<stdio.h>
#include<stdlib.h>
struct TreeNode{
    int val ; 
    struct TreeNode * left ;
    struct TreeNode * right ;
} ; 
int max(int n1, int n2 ){
    if(n1>n2){
        return n1 ;
    }
    return n2 ; 
}
struct TreeNode * createnode(int data){
    struct TreeNode * newnode = (struct TreeNode *)malloc(sizeof(struct TreeNode)) ; 
    newnode->val = data ; 
    newnode->left = NULL ;
    newnode->right = NULL ;
    return newnode ; 
}
int max_height(struct TreeNode * root){
    if(root==NULL){
        return 0 ; 
    }
    if(root->left==NULL && root->right == NULL){
        return 1 ; 
    }
    return max(max_height(root->left),max_height(root->right))+1 ;
}
void inorder(struct TreeNode * root){
    if(root==NULL){
        return ; 
    }
    inorder(root->left) ; 
    printf("%d ",root->val) ; 
    inorder(root->right) ; 
}
int main(){
    struct TreeNode * root = createnode(5) ;
    root->left = createnode(3) ; 
    root->right = createnode(7) ; 
    root->left->left = createnode(1) ; 
    root->left->left->right = createnode(2) ; 
    root->right->left = createnode(6) ;
    root->left->right = createnode(4) ;
    root->right->right = createnode(9) ;
    root->right->right->left = createnode(8) ;
    int n = max_height(root) ; 
    printf("%d",n) ; 
    return 0 ; 
}