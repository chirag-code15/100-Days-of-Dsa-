// Merge two sorted linked list 
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data ; 
    struct node * next ; 
}; 
struct node *  createnode(int k){
    struct node * newnode = (struct node*)malloc(sizeof(struct node)) ; 
    newnode->data = k ; 
    newnode->next = NULL ;
    return newnode ; 
}
void printlist(struct node* head){
    while(head!=NULL){
        printf("%d ",head->data) ; 
        head = head->next ; 
    }
}
int main(){
    int n ; 
    scanf("%d",&n) ; 
    struct node * head = NULL ; 
    struct node * temp ; 
    for(int i = 0 ; i<n ; i++){
        int a ; 
        scanf("%d",&a) ; 
        if(i==0){
            head = createnode(a) ; 
            temp = head ; 
            continue;
        }
        temp->next = createnode(a) ; 
        temp = temp->next ; 
    } 
    int n1 ; 
    scanf("%d",&n1) ; 
    struct node * head1 = NULL ;
    struct node * temp1 ;
    for(int i = 0 ; i<n1 ; i++){
        int a ; 
        scanf("%d",&a) ; 
        if(i==0){
            head1 = createnode(a) ; 
            temp1 = head1 ; 
            continue;
        }
        temp1->next = createnode(a) ; 
        temp1 = temp1->next ; 
    }
    temp = head ;
    temp1 = head1 ;
    struct node * ans = NULL ; 
    struct node * temp2 ; 
    while(temp!=NULL&&temp1!=NULL){
        if(temp->data<temp1->data){
            if(ans==NULL){
                ans = createnode(temp->data) ; 
                temp = temp->next ; 
                temp2 = ans ; 
                continue;
            }
            temp2->next = createnode(temp->data) ; 
            temp2 = temp2->next ; 
            temp = temp->next ; 
        }
        else{
            if(ans==NULL){
                ans = createnode(temp1->data) ; 
                temp1 = temp1->next ; 
                temp2 = ans ; 
                continue;
            }
            temp2->next = createnode(temp1->data) ; 
            temp2 = temp2->next ; 
            temp1 = temp1->next ; 
        }
    }
    if(temp==NULL){
        while(temp1!=NULL){
            temp2->next = createnode(temp1->data) ; 
            temp1 = temp1->next ; 
            temp2 = temp2->next ; 
        }
    }
    else{
        while(temp!=NULL){
            temp2->next = createnode(temp->data) ; 
            temp = temp->next ; 
            temp2 = temp2->next ; 
        }
    }
    printlist(ans) ; 
    return 0 ; 
}