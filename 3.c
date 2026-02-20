// Reverse an array
#include<stdio.h>
void reverse_an_array(int arr[], int n){
    int low = 0 ; 
    int high = n-1 ;
    while(low<high){
        int temp = arr[low] ; 
        arr[low] = arr[high] ; 
        arr[high] = temp ; 
        low++;
        high-- ; 
    }
}
int main(){
    int n = 5 ;
    int arr[] = {1,2,3,4,5} ;
    reverse_an_array(arr,n) ; 
    for(int i = 0 ; i<n ; i++){
        printf("%d ",arr[i]) ; 
    }
    return 0 ; 
}