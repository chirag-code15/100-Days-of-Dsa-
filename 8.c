// Compute x^n  using recursion 
#include<stdio.h>
int power(int x, int n){
    if(n==0){
        return 1  ; 
    }
    return x*power(x,n-1) ;
}
int main(){
    int x ;
    scanf("%d",&x) ; 
    int n ; 
    scanf("%d",&n) ; 
    printf("%d",power(x,n)) ; 
    return 0 ; 
}