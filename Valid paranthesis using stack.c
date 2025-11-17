#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
# define n 100
char stack[n];
int t=-1;
void push(char val);
void pop();
char top();
bool isempty();
void push(char val){
	t++;
	stack[t]=val;
}
void pop(){
	t--;
}
char top(){
    return stack[t];
}
bool isempty(){
    if(t==-1){
        return true;
    }
    else{
        return false;
    }
}
int main()
{
    char s[]="([{()()}])";
    for(int i=0;i<strlen(s);i++){
        if(s[i]=='('||"{"||"["){
            push(s[i]);
        }
        else{
            if(isempty== false && ((top()=='(' && s[i]==')') ||  (top()=='{' && s[i]=='}') || (top()=='[' && s[i]==']' ))){
                pop();
            }
            else{
                push(s[i]);
            }
        }
    }
    if(isempty()== true){
        printf("valid");
    }
    else{
        printf("invalid");
    }
}