// Rotate linked list by k position  
#include<stdio.h>
#include<stdlib.h>
struct node {
    int val ; 
    struct node * next ; 
} ; 
struct node * createnode(int data){
    struct node *newnode = (struct node *)malloc(sizeof(struct node)) ; 
    newnode->next = NULL ; 
    newnode->val = data ; 
    return newnode; 
}
void printlist(struct node * head){
    while(head!=NULL){
        printf("%d ",head->val) ; 
        head = head->next ; 
    }
}
struct node * rotate(struct node * head, int k, int n){ 
    struct node * temp = head ; 
    while(temp->next!=NULL){
        temp = temp->next ; 
    }
    struct node * temp1 = head ; 
    for(int i = 0 ;i<n-k ; i++){
        temp1 = temp1->next ; 
    }
    temp->next = head ; 
    while(head->next!=temp1){
        head = head->next ; 
    }
    head->next = NULL ; 
    return temp1 ; 
}
int main(){
    int n ; 
    scanf("%d",&n) ; 
    struct node * head = NULL ; 
    struct node * temp = NULL ; 
    for(int i = 0 ; i<n ; i++){
        int k ; 
        scanf("%d",&k) ; 
        if(head==NULL){
            head = createnode(k); 
            temp = head ; 
            continue;
        }
        temp->next = createnode(k) ; 
        temp = temp->next ; 
    } 
    int k ; 
    scanf("%d",&k) ; 
    head = rotate(head,k,n) ; 
    printlist(head);  
}