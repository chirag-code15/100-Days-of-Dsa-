#include<stdio.h>
#include<stdlib.h>
struct TreeNode{
    int val ; 
    struct TreeNode * left ;
    struct TreeNode * right ;
} ; 
struct TreeNode * createnode(int data){
    struct TreeNode * newnode = (struct TreeNode *)malloc(sizeof(struct TreeNode)) ; 
    newnode->val = data ; 
    newnode->left = NULL ;
    newnode->right = NULL ;
    return newnode ; 
}
void inorder(struct TreeNode * root){
    if(root==NULL){
        return ; 
    }
    inorder(root->left) ; 
    printf("%d ",root->val) ; 
    inorder(root->right) ; 
}
struct TreeNode* search(struct TreeNode* root, int data) {
    while (root != NULL) {
        if (root->val == data) {
            return root;   // found
        }
        else if (data < root->val) {
            root = root->left;   // go left
        }
        else {
            root = root->right;  // go right
        }
    }
    return NULL;  // not found
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
    int data ; 
    printf("Enter element to search : ");
    scanf("%d",&data) ; 
    struct TreeNode * temp = search(root,data) ; 
    if(temp==NULL){
        printf("NO value found") ; 
    }
    else{
        printf("%d",temp->val) ; 
    }
    return 0 ; 
}