#include<stdio.h>
int main(){
    int n ; 
    printf("Enter the size of an array : ");
    scanf("%d",&n); 
    int arr[n+1] ; 
    printf("Enter element of an array : "); 
    for(int i = 0 ;i<n ; i++){
        scanf("%d",&arr[i]) ; 
    }
    int index ; 
    printf("Enter index : ");
    scanf("%d",&index) ; 
    int element ; 
    printf("Enter element : "); 
    scanf("%d",&element) ; 
    for(int i = n-1 ; i>=index ; i--){
        arr[i+1] = arr[i] ; 
    }
    arr[index] = element ; 
    printf("Resultant array : ");
    for(int i = 0 ;i<n+1 ; i++){
        printf("%d ",arr[i]) ; 
    }
    return 0 ; 
}