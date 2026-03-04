// Create linked list 
#include<stdio.h>
#include<stdlib.h>
struct node{
    int val ; 
    struct node * next ; 
} ; 
struct node* createnode(int k){
    struct node * newnode = (struct node *)malloc(sizeof(struct node)) ; 
    newnode->val = k ; 
    newnode->next = NULL ; 
    return newnode ; 
}
void printlist(struct node * head){
    while(head!=NULL){
        printf("%d ",head->val) ;
        head = head->next ;  
    }
}
int main(){
    int n ;
    scanf("%d",&n) ; 
    struct node * head = NULL ; 
    struct node * temp= NULL ; 
    while(n!=0){
        int val ; 
        scanf("%d",&val) ; 
        struct node* newnode = createnode(val) ; 
        if(head==NULL){
            head = newnode ; 
            temp = newnode ; 
        }
        else{
            temp->next = newnode ; 
            temp = newnode ; 
        }
        n-- ; 
    }
    printlist(head) ; 
    return 0 ; 
}