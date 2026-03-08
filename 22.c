// Count the number of nodes in the linked list
#include<stdio.h>
#include<stdlib.h>
struct node{
    int val ; 
    struct node * next ; 
} ; 
struct node * createnode(int k){
    struct node * newnode = (struct node *)malloc(sizeof(struct node)) ; 
    newnode->val = k ; 
    newnode->next = NULL; 
}
int count_node(struct node * head){
    int count = 0 ; 
    while(head!=NULL){
        count += 1; 
        head = head->next ; 
    }
    return count ; 
}
int main(){
    struct node * head = createnode(1) ; 
    head->next = createnode(2) ; 
    head->next->next = createnode(3) ; 
    head->next->next->next = createnode(4) ;
    head->next->next->next->next = createnode(5) ;
    printf("%d",count_node(head)) ;
    return 0 ; 
}