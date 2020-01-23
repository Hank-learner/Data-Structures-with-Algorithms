#include<bits/stdc++.h>
using namespace std;
#define basespace 10
char stacke[20];
int top = -1;

struct et{
char data;
et* left,*right;
};

bool isoperator(char c){
if(c=='+'||c=='-'||c=='*'||c=='/'||c=='^')
return true;
return false;
}

et *newnode(int v){
et* temp=new et;
temp->left=temp->right=NULL;
temp->data=v;
return temp;
}

et* constructtree(char postfix[]){
stack<et *> st;
et *t,*t1,*t2;
for (int i=0;i<strlen(postfix);i++){
if(!isoperator(postfix[i])){
t=newnode(postfix[i]);
st.push(t);
}
else
{
t=newnode(postfix[i]);
t1=st.top();
st.pop();
t2=st.top();
st.pop();
t->right=t1;
t->left=t2;
st.push(t);
}
}
t=st.top();
st.pop();
return t;
}

void printtree(et* root,int space){
	if(root==NULL)
	return;

space+=basespace;
printtree(root->right,space);
cout<<endl;
int i;

for(i=basespace;i<space;i++)
cout<<" ";

cout<<root->data<<"\n";
printtree(root->left,space);

return;
}



void pushe(char x){
stacke[++top] = x;
}
 
char tope(){
if(top == -1)
return -1;
else
return stacke[top];
}

char pope(){
if(top == -1)
return -1;
else
return stacke[top--];
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

char *e, x ,*ee;

printf("Enter the expression : ");
scanf("%s",exp);

e = exp;



while(*e != '\0'){

if(isalnum(*e)){
postfixexp[postfixlength++]=*e;
}

else if(*e == '('){
pushe(*e);
}

else if(*e == ')'){
while((x = pope()) != '('){  
postfixexp[postfixlength++]=x;
}
}
  
else{
while(priority(stacke[top]) >= priority(*e)){
postfixexp[postfixlength++]=pope();
}
pushe(*e);
}
e++;
}

while(top != -1){
postfixexp[postfixlength++]=pope();
}

et *r = constructtree(postfixexp);
printf("the binary tree : \n");
printtree(r,0);


printf("postfix expression is : ");
int i;
for(i=0;i<postfixlength;i++){
printf("%c",postfixexp[i]);
}
printf("\n");


return 0;

}
