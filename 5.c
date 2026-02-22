// Linear search with comparsion count 
#include<stdio.h>
int main(){
    int n ; 
    scanf("%d",&n); 
    int arr[n] ; 
    for(int i= 0 ; i<n ; i++){
        scanf("%d",&arr[i]) ; 
    }
    int key ; 
    scanf("%d",&key) ; 
    int comparsion_count = 0 ; 
    int index = 0 ; 
    for(int i = 0 ;i<n ; i++){
        if(arr[i]==key){
            comparsion_count++ ;
            index = i ;  
            break;
        }
        comparsion_count++ ; 
    }
    printf("Found at index %d",index) ;
    printf("\nComparison : %d",comparsion_count) ;  
    return 0 ; 
}