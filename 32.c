// Impliment pop and push function 
#include<stdio.h>
#include<stdlib.h>
struct stack{
    int * arr ; 
    int capaicity ; 
    int top ; 
} ; 
struct stack * createstack(int cap){
    struct stack * newstack = (struct stack *)malloc(sizeof(struct stack)) ;
    newstack->arr = (int*)malloc(sizeof(int)*cap) ; 
    newstack->capaicity = cap ;
    newstack->top = -1 ;
}
void push(struct stack * head, int val){
    if(head->top==head->capaicity-1){
        printf("Stack overflow\n") ;   
    }
    else{
        head->arr[++head->top] = val ; 
    }
}
void pop(struct stack *head ){
    if(head->top==-1){
        printf("Stack undeflow\n") ;
    }
    else{
        printf("%d\n",head->arr[head->top--]) ; 
    }
}
void print(struct stack * head){
    int a = head->top ; 
    for(int i = a ; i>=0 ; i--){
        printf("%d ",head->arr[i]) ; 
    }
    printf("\n") ; 
}
int main(){
    struct stack * head = createstack(5) ; 
    push(head,1) ; 
    push(head,2) ; 
    push(head,3) ; 
    print(head) ;  
    pop(head) ;
    print(head) ; 
    return 0 ; 
}
