// mirror the code name 
#include<stdio.h>
void mirror_the_name(char s[],int n){
    int low = 0 ; 
    int high = n-1 ; 
    while(low<high){
        char ch = s[low] ; 
        s[low] = s[high] ; 
        s[high] = ch ; 
        low++; 
        high-- ; 
    }
}
int main(){
    char s[100] ; 
    scanf("%s",&s) ; 
    int n  = 0 ;
    char ch = s[0] ;
    int i = 0 ;   
    while(ch!='\0'){
        n++ ; 
        i++ ; 
        ch = s[i] ; 
    }
    mirror_the_name(s,n) ; 
    printf("%s",s) ; 
    return 0 ; 
}