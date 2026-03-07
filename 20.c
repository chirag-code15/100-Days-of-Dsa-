// Top calculate the subarray with sum 0
#include<stdio.h>
int main(){
    int n ; 
    int count = 0 ; 
    scanf("%d",&n) ; 
    int arr[n] ; 
    for(int i = 0 ; i<n ; i++){
        scanf("%d",&arr[i]) ; 
    }
    for(int i = 0 ;i<n ; i++){
        int sum = 0 ; 
        for(int j = i ; j<n ; j++){
            sum += arr[j] ; 
            if(sum==0){
                count++ ; 
            }
        }
    }
    printf("%d",count); 
    return 0 ; 
}