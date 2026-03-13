// To find the intersection of the two linked list 
#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node* next;
};
struct node* createNode(int val) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = NULL;
    return newnode;
}
struct node * intersection(struct node * head, struct node * head1){
    struct node * p1 = head ; 
    struct node * p2 = head1 ;
    while(p1!=p2){
        if(p1==NULL){
            p1 = head1 ; 
        }
        else{
            p1 = p1->next ; 
        }
        if(p2==NULL){
            p2 = head ; 
        }
        else{
            p2 = p2->next ; 
        }
    }
    return p1 ;
}
void printList(struct node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}
int main() {
    struct node * head = createNode(10) ; 
    head->next = createNode(20) ; 
    head->next->next = createNode(30) ; 
    head->next->next->next = createNode(40) ; 
    head->next->next->next->next = createNode(50) ; 
    struct node * head1 = createNode(15) ; 
    head1->next = head->next->next ; 
    head1->next->next = head->next->next->next ; 
    head1->next->next->next = head->next->next->next->next ; 
    struct node * head2 = intersection(head,head1) ; 
    if(head2==NULL){
        printf("No intersection") ; 
        return 0 ; 
    }
    printf("Intersection at : %d",head2->data) ; 
    return 0 ; 
}