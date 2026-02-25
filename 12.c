// To check whether the  matrix is symmetric
#include<stdio.h>
int main(){
    int n, m ;
    scanf("%d %d",&n,&m) ; 
    int matrix[n][m] ; 
    for(int i = 0 ; i<n ; i++){
        for(int j = 0 ;j<m ; j++){
            scanf("%d",&matrix[i][j]) ; 
        }
    }
    for(int i = 0 ; i<n ; i++){
        for(int j = (i+1) ; j<m ; j++){
            if(matrix[i][j]!=matrix[j][i]){
                printf("Matrix is not symmetric") ; 
                return 0 ; 
            }
        }
    }
    printf("Matrix is symmetric") ; 
    return 0 ; 
}