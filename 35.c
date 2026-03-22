// Using arrays and function implement Queue data structure and its opeartion like insert, delete and display
#include<stdio.h>
#include<stdbool.h>
#define max 10
int queue[max] ; 
int back = -1 ;
void enque(int val){
    if(back==max-1){
        printf("Queue is full\n") ;
    }
    else{
        queue[++back] = val ; 
    }
} 
void dequeue(){
    if(back==-1){
        printf("Queue is already empty\n") ; 
    }
    else{
        for(int i = 0 ; i<back ; i++){
            queue[i] = queue[i+1] ; 
        }
        back-- ; 
    }
}
void print(){
    for(int i = 0 ; i<=back ; i++){
        printf("%d ",queue[i]) ; 
    }
    printf("\n") ; 
}
void last_value(){
    if(back==-1){
        printf("queue is empty\n") ; 
    }
    else{
        printf("%d\n",queue[back]) ;
    }
}
void first_value(){
    if(back==-1){
        printf("queue is empty\n") ; 
    }
    else{
        printf("%d\n",queue[0]) ;
    }
}
bool is_empty(){
    if(back==-1){
        return true ; 
    }
    else{
        return false ; 
    }
}
bool is_full(){
    if(back==max-1){
        return true ; 
    }
    else{
        return false ; 
    }
}
int main(){
    enque(1) ;
    enque(2) ;
    enque(3) ;
    print() ; 
    dequeue();
    print() ; 
    return 0 ; 
}