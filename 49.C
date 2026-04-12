// Insert in a binary tree
#include<stdio.h>
#include<stdlib.h>
struct Treenode{
    int val ; 
    struct Treenode * left; 
    struct Treenode * right; 
} ; 
struct Treenode * createnode(int data){
    struct Treenode * newnode = (struct Treenode *)malloc(sizeof(struct Treenode)) ;
    newnode->val = data ; 
    newnode->right = NULL ; 
    newnode->left = NULL ; 
    return newnode ; 
}
struct Treenode * insert(struct Treenode * root, int data){
    if(root==NULL){
        return createnode(data) ;
    }
    struct Treenode * temp = root ; 
    while(temp->left!=NULL||temp->right!=NULL){
        if(temp->val>data){
            if(temp->left==NULL){
                temp->left = createnode(data) ; 
                return root ; 
            }
            else{
                temp = temp->left ; 
            }
        }
        else{
            if(temp->right==NULL){
                temp->right = createnode(data) ; 
                return root ; 
            }
            else{
                temp = temp->right ;  
            }
        }
    }
    if(temp->val>data){
        temp->left = createnode(data) ; 
    }
    else{
        temp->right = createnode(data) ; 
    }
    return root; 
}
void inorder(struct Treenode * root){
    if(root==NULL){
        return ; 
    }
    inorder(root->left) ;
    printf("%d ",root->val); 
    inorder(root->right) ; 
}
int main(){
    int n ; 
    scanf("%d",&n);
    struct Treenode * root = NULL ;
    for(int i = 0 ; i<n ; i++){
        int data ; 
        scanf("%d",&data) ; 
        root = insert(root,data) ; 
    }
    inorder(root) ; 
}