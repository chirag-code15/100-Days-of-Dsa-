// create a doubly linked list and transverse through it 
#include<stdio.h>
#include<stdlib.h>
struct node {
    int val ; 
    struct node * next ; 
    struct node * prev ; 
} ; 
struct node * createnode(int k){
    struct node * newnode = (struct node *)malloc(sizeof(struct node)); 
    newnode->val = k ; 
    newnode->next = NULL ; 
    newnode->prev = NULL ;
    return newnode ;  
}
void printlist(struct node * head){
    struct node * temp ; 
    printf("Printing forward : ") ; 
    while(head!=NULL){
        printf("%d ",head->val) ;
        temp = head ;  
        head = head->next ; 
    }
    printf("\nPrinting backward : ") ; 
    while(temp!=NULL){
        printf("%d ", temp->val) ; 
        temp = temp->prev ; 
    }
}
int main(){
    int n ; 
    scanf("%d",&n) ; 
    struct node * head = NULL ;
    struct node * temp ; 
    struct node * temp1 ; 
    for(int i = 0 ; i<n ; i++){
        int k ; 
        scanf("%d",&k) ; 
        if(i==0){
            head = createnode(k) ;
            temp = head ;  
            temp1 = head; 
            continue;
        }
        temp->next = createnode(k) ; 
        temp = temp->next ; 
        temp->prev = temp1 ; 
        temp1 = temp1->next ; 
    }
    printlist(head); 
    return 0 ; 
}