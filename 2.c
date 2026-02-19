// Delete an element from an array
#include<stdio.h>
int main(){
    int n ; 
    printf("Enter the size of an array : "); 
    scanf("%d",&n) ; 
    int arr[n] ; 
    printf("Enter the elements of an array : \n");  
    for(int i = 0 ; i<n ; i++){
        scanf("%d",&arr[i]) ; 
    }
    int index ; 
    printf("Enter the index you want to delete : "); 
    scanf("%d",&index) ; 
    for(int i = index+1 ; i<n ; i++){
        arr[i-1] = arr[i] ; 
    }
    printf("Array after deletion : "); 
    for(int i = 0; i<n-1 ; i++){
        printf("%d ",arr[i]) ; 
    }
    return 0 ; 
}