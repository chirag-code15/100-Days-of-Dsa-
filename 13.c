// Spiral matrix
#include<stdio.h>
int main(){
    int n ; 
    int m ;
    scanf("%d %d",&n,&m) ; 
    int matrix[n][m] ; 
    for(int i = 0 ; i<n ; i++){
        for(int j = 0 ; j<m ; j++){
            scanf("%d",&matrix[i][j]) ; 
        }
    }
    int upper_row = 0 ; 
    int lower_row = n-1 ; 
    int left_col = 0 ; 
    int right_col = m-1 ; 
    while(upper_row<=lower_row&&left_col<=right_col){
        // printing upper row 
        for(int i = left_col ; i<=right_col ; i++){
            printf("%d ",matrix[upper_row][i]) ; 
        }
        upper_row++ ; 
        // printing right col 
        for(int i = upper_row ; i<=lower_row ; i++){
            printf("%d ",matrix[i][right_col]) ; 
        }
        right_col-- ;
        // printing lower row
        if(upper_row<=lower_row){
            for(int i = right_col ; i>=left_col ; i--){
                printf("%d ",matrix[lower_row][i]) ; 
            }
        }
        lower_row-- ;
        // printing left_col
        if(left_col<=right_col){
            for(int i = lower_row ; i>=upper_row ; i--){
                printf("%d ",matrix[i][left_col]) ; 
            }
        }
        left_col++ ; 
    }
    return 0  ;
}