// remove the first occurence of the key
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
    printf("\n") ; 
}
struct node * delete(struct node *head, int pos){
    if(head==NULL){
        printf("Empty list") ;
        return head; 
    }
    struct node * temp1 = head ; 
    struct node * temp2 = NULL ; 
    while(temp1!=NULL){
        if(temp1->val==pos){
            break;
        }
        temp2 = temp1 ; 
        temp1 = temp1->next ; 
    }
    // No element found 
    if(temp1==NULL){
        printf("No element found") ; 
        return head ; 
    }
    // element found at start 
    if(temp2==NULL){
        temp2 = temp1 ;
        temp1 = temp1->next ; 
        free(temp2) ; 
        return temp1 ; 
    }
    temp2->next = temp1->next ; 
    free(temp1) ; 
    return head ; 
}
int main(){
    int n ; 
    scanf("%d",&n) ; 
    struct node * head = NULL ; 
    struct node * temp ; 
    for(int i = 0 ; i<n ; i++){
        int k ; 
        scanf("%d",&k) ; 
        if(i==0){
            head = createnode(k) ; 
            temp = head ; 
            continue;
        }
        temp->next = createnode(k) ; 
        temp = temp->next ; 
    }
    int target ; 
    scanf("%d",&target) ; 
    head = delete(head,target) ; 
    printlist(head) ; 
    return 0 ; 
}