#include<stdio.h>
#include<stdlib.h>
struct node{
    float coff ; 
    int pow ; 
    struct node* next ; 
} ; 
struct node * createnode(float co, int po){
    struct node * newnode = (struct node*)malloc(sizeof(struct node)) ; 
    newnode->coff = co ; 
    newnode->pow = po ; 
    newnode->next = NULL ; 
    return newnode ; 
}
void printlist(struct node * head){
    while(head!=NULL){
        printf("%0.1f",head->coff) ;
        if(head->pow!=0){
            if(head->next==NULL){
                printf("x^%d",head->pow) ; 
            }
            else{
                printf("x^%d + ",head->pow) ; 
            }
        }
        head = head->next ; 
    }
}
int main(){
    int n ; 
    scanf("%d",&n) ; 
    struct node * head = NULL ; 
    struct node * temp = NULL ; 
    for(int i = 0 ; i<n ; i++){
        float co ; 
        scanf("%f",&co) ; 
        int po ; 
        scanf("%d",&po) ; 
        if(head==NULL){
            head = createnode(co,po) ; 
            temp = head ; 
        }
        temp->next = createnode(co, po) ;
        temp = temp->next ; 
    }
    printlist(head); 
}