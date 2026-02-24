// Check if the string is palindrome
#include<stdio.h>
int main(){
    char s[100] ;
    scanf("%s",&s) ; 
    int n = 0 ;
    char ch = s[0] ; 
    int a = 0 ; 
    while(ch!='\0'){
        n++ ;
        ch = s[++a] ; 
    } 
    int low = 0  ;
    int high = n-1 ; 
    while(low<high){
        if(s[low]!=s[high]){
            printf("String is not palindrome") ; 
            return 0 ; 
        }
        low++ ; 
        high-- ; 
    }
    printf("String is palindome") ;
    return 0 ; 
}