// Create a circular linked list
#include<stdio.h>
#include<stdlib.h>
struct node {
    int val ; 
    struct node * next ; 
} ; 
struct node * createnode(int data){
    struct node * newnode = (struct node *)malloc(sizeof(struct node)) ; 
    newnode->val = data ; 
    newnode->next = NULL ; 
    return newnode ; 
}
void printlist(struct node * head){
    struct node * temp = head ;
    do{
        printf("%d ",temp->val) ;
        temp = temp->next ; 
    }while(temp!=head) ; 
}
int main(){
    int n ; 
    scanf("%d",&n) ; 
    struct node * head = NULL ; 
    struct node * temp; 
    for(int i = 0 ; i<n ; i++){
        int data ; 
        scanf("%d",&data) ; 
        if(i==0){
            head = createnode(data) ; 
            temp = head ; 
            continue;
        }
        temp->next = createnode(data) ; 
        temp = temp->next ; 
    }
    temp->next = head ; 
    printlist(head); 
    return 0 ; 
}