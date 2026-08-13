// Linked list implimentation using c
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data ; 
    struct node * next ; 
} ;
struct node * createnode(int data){
    struct node * newnode = (struct node *)malloc(sizeof(struct node)) ; 
    newnode->data = data ; 
    newnode->next = NULL  ;
    return newnode ; 
}
void print(struct node * head){
    while(head!=NULL){
        printf("%d ",head->data) ; 
        head = head->next ; 
    }
}
int main(){
    struct node * head = createnode(1) ; 
    head->next = createnode(2) ; 
    head->next->next = createnode(3) ; 
    head->next->next->next = createnode(4) ; 
    print(head) ; 
}