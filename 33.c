// Infix to postfix conversion 
#include<stdio.h>
#include<ctype.h>
int check(char s[], int top, char a){
    if(top==-1||s[top]=='('){
        return 1 ; 
    }
    int x ; 
    if(a=='^'){
        x = 6 ; 
    }
    else if(a=='*'){
        x = 5 ;
    }
    else if(a=='/'){
        x = 4 ;
        
    }
    else if(a=='%'){
        x = 3 ;
    }
    else if(a=='+'){
        x = 2 ;
    }
    else{
        x = 1 ;
    }
    if(s[top]=='^'){
        return x-6 ; 
    }
    else if(s[top]=='*'){
        return x-5 ; 
        
    }
    else if(s[top]=='/'){
        return x-4 ; 
        
    }
    else if(s[top]=='%'){
        return x-3 ;
    }
    else if(s[top]=='+'){
        return x-2 ;
    }
    else{
        return x-1 ; 
    }
}
int main(){
    char s[100] ; 
    int top = -1; 
    char a[100] ; 
    scanf("%s",&a) ;
    int i = 0 ; 
    char b = a[i] ; 
    while(b!='\0'){
        if(b=='('){
            s[++top] = '(' ; 
        }
        else if(b==')'){
            while(s[top--]!='('){
                printf("%c",s[top+1]) ; 
            }
        }
        else if(isalpha(b)){
            printf("%c",b) ; 
        }
        else{
            while(check(s,top,b)<0||(check(s,top,b)==0&&b!='^')){
                printf("%c",s[top--]) ; 
            }
            s[++top] = b ; 
        }
        b = a[++i] ; 
    }
    while(top!=-1){
        printf("%c",s[top--]) ; 
    }
}