// To find the maximum and minimum element in an array
#include<stdio.h>
#include<limits.h>
int main(){
    int n ; 
    scanf("%d",&n) ;
    int arr[n] ; 
    for(int i = 0 ; i<n ; i++){
        scanf("%d",&arr[i]) ; 
    }    
    int min = INT_MAX ; 
    int max = INT_MIN ; 
    for(int i = 0 ; i<n ; i++){
        if(arr[i]<min){
            min = arr[i] ; 
        }
        if(arr[i]>max){
            max = arr[i] ; 
        }
    }
    printf("Max : %d",max) ; 
    printf("Min : %d",min) ; 
    return 0 ; 
}