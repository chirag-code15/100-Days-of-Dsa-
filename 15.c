#include<stdio.h>
#include<limits.h>

int main(){
    int n; 
    scanf("%d",&n); 
    int arr[n]; 
    for(int i = 0 ; i<n ; i++){
        scanf("%d",&arr[i]); 
    }
    for(int i = 0 ; i<n ; i++){
        if(arr[i] == INT_MIN){
            continue;
        }
        int count = 1;  
        for(int j = i+1 ; j<n ; j++){
            if(arr[i] == arr[j]){
                count++;
                arr[j] = INT_MIN;  
            }
        }
        printf("%d : %d\n", arr[i], count);
    }
    return 0;
}