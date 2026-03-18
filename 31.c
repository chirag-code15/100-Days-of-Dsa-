// Implimenting stack using array
#include<stdio.h>
# define max 100 
int s[max] ; 
int top = -1; 
void push(int val, int n ){
    if(top==n-1){
        printf("Stack overflow"); 
        return ; 
    }
    s[++top] = val ; 
}
void pop(){
    if(top==-1){
        printf("Stack underflow") ; 
        return ; 
    }
    top-- ; 
}
void print(){
    int a = top ; 
    while(a!=-1){
        printf("%d ",s[a--]) ; 
    }
}
int main(){
    int n ; 
    scanf("%d",&n) ; 
    for(int i = 0 ; i<n ; i++){
        int choice ; 
        scanf("%d",&choice) ; 
        if(choice==1){
            int val ; 
            scanf("%d",&val) ; 
            push(val,n) ; 
        }
        else if(choice==2){
            pop() ; 
        }
        else{
            print() ; 
        }
    }
}