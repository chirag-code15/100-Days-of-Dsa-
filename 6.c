// remove duplicate from an array
#include<stdio.h>
int remove_duplicate(int arr[], int n){
    int ptr = 1 ; 
    int ptr1 = 1 ;
    while(ptr1!=n){
        if(arr[ptr1]!=arr[ptr1-1]){
            arr[ptr] = arr[ptr1] ;
            ptr++ ; 
        } 
        ptr1++ ; 
    } 
    return ptr ; 
}
int main(){
    int n ; 
    scanf("%d",&n) ; 
    int arr[n] ; 
    for(int i = 0 ;i<n ;i++){
        scanf("%d",&arr[i]) ; 
    }
    n = remove_duplicate(arr,n) ; 
    for(int i = 0 ;i<n ; i++){
        printf("%d ",arr[i]) ; 
    }
    return 0 ; 
}