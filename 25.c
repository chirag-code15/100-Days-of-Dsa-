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
void count_occurence(struct node * head, int n){
    int count = 0 ; 
    while(head!=NULL){
        if(head->val==n){
            count++ ; 
        }
        head = head->next ; 
    }
    printf("%d",count) ; 
}
int main(){
    struct node * head = createnode(1) ; 
    head->next = createnode(2) ; 
    head->next->next = createnode(3) ; 
    head->next->next->next = createnode(2) ; 
    head->next->next->next->next = createnode(4) ;
    int n = 2 ; 
    count_occurence(head,n) ; 
    return 0 ; 
}