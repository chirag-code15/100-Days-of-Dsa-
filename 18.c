// Rotate array by k position 
#include<stdio.h>
void reverse(int str, int end ,int arr[]){
    while(str<end){
        int temp = arr[str] ;
        arr[str] = arr[end] ; 
        arr[end] = temp ;
        str++ ; 
        end-- ;  
    }
}
int main(){
    int n ; 
    scanf("%d",&n) ; 
    int arr[n] ; 
    for(int i = 0 ; i<n ; i++){
        scanf("%d",&arr[i]); 
    }
    int k ; 
    scanf("%d",&k) ; 
    reverse(0,n-1,arr) ;
    reverse(0,k-1,arr) ;
    reverse(k,n-1,arr) ; 
    for(int i = 0 ;i<n ; i++){
        printf("%d ",arr[i]) ; 
    }
    return 0 ; 
}