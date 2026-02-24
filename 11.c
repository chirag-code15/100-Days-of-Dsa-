// Matrix addition 
#include<stdio.h>
int main(){
    int n ; 
    int m ; 
    scanf("%d %d",&n,&m) ; 
    int matrix1[n][m] ; 
    int matrix2[n][m] ; 
    printf("Enter element of matrix 1 : \n");
    for(int i = 0 ; i<n ; i++){
        for(int j = 0 ;j<m ; j++){
            scanf("%d",&matrix1[i][j]) ; 
        }
    }
    printf("Enter element of matrix 1 : \n");
    for(int i = 0 ; i<n ; i++){
        for(int j = 0 ;j<m ; j++){
            scanf("%d",&matrix2[i][j]) ; 
        }
    }
    int resultant_matrix[n][m] ;
    for(int i = 0 ; i<n ; i++){
        for(int j = 0 ;j<m ; j++){
            resultant_matrix[i][j] = matrix1[i][j] + matrix2[i][j] ;  
        }
    }
    printf("Resultant matrix : \n") ;
    for(int i = 0 ; i<n ; i++){
        for(int j = 0 ;j<m ; j++){
            printf("%d ",resultant_matrix[i][j]) ; 
        }
        printf("\n") ; 
    }
    return 0 ; 
}