#include<stdio.h>
#include<stdlib.h>
struct Treenode{
    int val ; 
    struct Treenode * left ;
    struct Treenode * right ;
} ; 
int max(int n1, int n2){
    if(n1>n2){
        return n1 ; 
    }
    return n2 ; 
}
struct Treenode * createnode(int data){
    struct Treenode * newnode = (struct Treenode *)malloc(sizeof(struct Treenode)) ; 
    newnode->val = data ; 
    newnode->left = NULL ; 
    newnode->right = NULL ;
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
    return root ; 
}
int count_leaf_nodes(struct Treenode * root){
    if(root==NULL){
        return 0 ; 
    }
    if(root->left==NULL && root->right==NULL){
        return 1 ; 
    }
    return count_leaf_nodes(root->left)+count_leaf_nodes(root->right) ; 
}
int main(){
    int n ; 
    scanf("%d",&n) ; 
    struct Treenode * root = NULL ; 
    for(int i = 0 ; i<n ; i++){
        int data ; 
        scanf("%d",&data) ; 
        root = insert(root,data) ; 
    }
    int count_ln = count_leaf_nodes(root) ;  
    printf("No of leaf nodes in the tree : %d",count_ln) ; 
    return 0 ; 
}
