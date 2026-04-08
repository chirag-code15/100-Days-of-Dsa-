#include<stdio.h>
#include<stdlib.h>
struct node {
    int val ; 
    struct node * left ; 
    struct node * right ; 
} ; 
struct node * createnode(int data){
    struct node * newnode = (struct node *)malloc(sizeof(struct node)) ; 
    newnode->val = data; 
    newnode->left = NULL ; 
    newnode->right = NULL ;
    return newnode ;  
}
struct node * insert(struct node * root, int data){
    if(root==NULL){
        root = createnode(data) ; 
        return root; 
    }
    struct node * temp = root ; 
    while(root->left!=NULL||root->right!=NULL){
        if(root->val>data){
            if(root->left==NULL){
                root->left = createnode(data) ;  
                return temp; 
            } 
            else{
                root = root->left ; 
            }
        }
        else if(root->val<=data){
            if(root->right==NULL){
                root->right = createnode(data) ; 
                return temp; 
            }
            else{
                root = root->right ; 
            }
        }
    }
    if(root->left==NULL&&root->right==NULL){
        if(root->val>data){
            root->left = createnode(data) ; 
        }
        else{
            root->right = createnode(data) ;
        }
    }
    return temp ; 
}
void postorder(struct node * root){
    if(root==NULL){
        return ; 
    }
    postorder(root->left) ;
    postorder(root->right) ;
    printf("%d ",root->val) ; 
}
void preorder(struct node * root){
    if(root==NULL){
        return ; 
    }
    printf("%d ",root->val) ; 
    preorder(root->left) ;
    preorder(root->right) ;
}
void inorder(struct node * root){
    if(root==NULL){
        return ; 
    }
    inorder(root->left) ; 
    printf("%d ",root->val) ; 
    inorder(root->right) ; 
}
int main(){
    int n ; 
    scanf("%d",&n) ; 
    struct node * root = NULL ; 
    for(int i = 0 ; i<n ; i++){
        int data ; 
        scanf("%d",&data) ; 
        root = insert(root,data) ; 
    }
    printf("Inorder : ") ;
    inorder(root) ; 
    printf("\n") ; 
    printf("Postorder : ");
    postorder(root) ; 
    printf("\n") ; 
    printf("Preorder : ") ;
    preorder(root) ; 
    return 0 ; 
}