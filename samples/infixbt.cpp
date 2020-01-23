#include<bits/stdc++.h>
using namespace std;
#define basespace 10
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

int main(){
char postfix[]="ab+d/ef*-";	
et *r = constructtree(postfix);
printf("the binary tree : \n");
printtree(r,0);

}
