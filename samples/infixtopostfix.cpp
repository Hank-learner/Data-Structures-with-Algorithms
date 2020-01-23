#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

char stack[20];
int top = -1;

void push(char x){
stack[++top] = x;
}
 
char pop(){
if(top == -1)
return -1;
else
return stack[top--];
}

int priority(char x){
if(x == '(')
return 0;
if(x == '+' || x == '-')
return 1;
if(x == '*' || x == '/')
return 2;
}
 
int main(){

    char exp[20];

    char postfixexp[20];
    int postfixlength=0;
    char variables[10];
    int variablevalues[10];
    int variablelength=0;

    char *e, x ,*ee;

    printf("Enter the expression : ");
    scanf("%s",exp);

    e = exp;



    while(*e != '\0')
    {
        if(isalnum(*e)){
            variables[variablelength++]=*e;
            postfixexp[postfixlength++]=*e;
        }

        else if(*e == '('){
            push(*e);
        }

        else if(*e == ')'){
            while((x = pop()) != '('){  
                postfixexp[postfixlength++]=x;
            }
        }
        
        else{
            while(priority(stack[top]) >= priority(*e)){
                postfixexp[postfixlength++]=pop();
            }
        push(*e);
        }
        e++;
    }

    while(top != -1){
        postfixexp[postfixlength++]=pop();
    }


    printf("postfix expression is : ");
    int i;
    for(i=0;i<postfixlength;i++){
        printf("%c",postfixexp[i]);
    }
    printf("\n");



    for(i=0;i<variablelength;i++){
        printf("Enter the value of %c : ",variables[i]);
        scanf("%d",&variablevalues[i]);
    }


    int n1,n2,n3,num,variableval,testnum;

    int k=0;
    while(postfixexp[k] != '\0')
    {
        if(isalnum(postfixexp[k]))
        {
            testnum=postfixexp[k];
            if(testnum>96 && testnum<123){
                num = variablevalues[variableval++];
                push(num);
            }
        }
        else{
            n1 = pop();
            n2 = pop();
            switch(postfixexp[k]){
            case '+':n3 = n1 + n2;break;
            case '-':n3 = n2 - n1;break;
            case '*':n3 = n1 * n2;break;
            case '/':n3 = n2 / n1;break;
        }
        push(n3);
        }

        k++;
    }

    printf("\nresult =  %d \n",pop());

    return 0;

}

