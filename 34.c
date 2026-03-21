#include<stdio.h>
#include<ctype.h>
#include<math.h>
int main(){
    float  s[100] ; 
    int top = -1 ; 
    char a[100] ; 
    scanf("%s",&a) ;
    int i = 0 ; 
    char b = a[i] ;
    while(b!='\0'){
        if(isdigit(b)){
            s[++top] = b-48 ; 
        }
        else{
            float result = 0 ; 
            float operand2 = s[top--] ; 
            float operand1 = s[top--] ; 
            if(b=='+'){
                result = operand1 + operand2 ; 
                s[++top] = result ; 
            }
            else if(b=='-'){
                result = operand1 - operand2 ; 
                s[++top] = result ; 
            }
            else if(b=='*'){
                result = operand1 * operand2 ; 
                s[++top] = result ; 
            }
            else if(b=='/'){
                result = operand1 / operand2 ; 
                s[++top] = result ; 
            }
            else {
                result = (int)operand1%(int)operand2 ; 
                s[++top] = result ; 
            }
        }
        b = a[++i] ; 
    }  
    while(top!=-1){
        printf("%0.2f",s[top--]) ;
    }
    return 0 ; 
}