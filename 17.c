// Create and transvere singly linked list
#include<stdio.h>
#include<stdlib.h>
struct node{
    int val ; 
    struct node * next ; 
} ; 
struct node * createnode(int k){
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
    struct node * head = createnode(1) ; 
    head->next = createnode(2) ; 
    head->next->next = createnode(3) ; 
    head->next->next->next = createnode(4) ; 
    printlist(head); 
    return 0 ; 
}