#include<stdio.h>
#include<stdlib.h>
int main(){
    int n ; 
    scanf("%d",&n) ; 
    int * arr = (int*)malloc(n*sizeof(int)) ;
    for(int i = 0 ; i<n ; i++){
        scanf("%d",&arr[i]) ; 
    } 
    int n1 ; 
    scanf("%d",&n1) ; 
    int * arr1 = (int*)malloc(sizeof(int)) ; 
    for(int i = 0 ; i<n1 ; i++){
        scanf("%d",&arr1[i]) ; 
    }
    int a[n+n1] ; 
    int ptr = 0 ;
    int ptr1 = 0 ;
    int count = 0 ;  
    while(ptr!=n&&ptr1!=n1){
        if(arr[ptr]<=arr1[ptr1]){
            a[count++] = arr[ptr++] ; 
        }
        else{
            a[count++]  = arr1[ptr1++] ; 
            // ptr1 ++ ; 
        }
    }
    if(ptr==n){
        while(ptr1!=n1){
            a[count++] = arr1[ptr1++] ; 
            // ptr1++ ; 
        }
    }
    else{
        while(ptr!=n){
            a[count++] = arr[ptr++] ; 
            // ptr++ ; 
        }
    }
    for(int i = 0 ; i<count ; i++){
        printf("%d ",a[i]) ; 
    }
    free(arr1) ;
    free(arr); 
    return 0 ; 
}