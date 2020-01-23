#include <stdio.h>
#include <stdlib.h>
int main(){
char string1[100];
int option;
printf("\n1 strlen\n2 strcpy \n3 strcat\n4 strupr\n5 strrev\n6 strlwr\n7 strset\n8 strcmp\n9 strchr\n10 strrchr\n\nEnter any number to perform: ");
scanf("%d",&option);

printf("Enter the string : ");
scanf("%s",&string1);

int i=0;
int string1length=0;
for(i=0;;i++){
if(string1[i]!='\0'){
string1length++;
}else{
break;}
}



if(option==1){
printf("%d",string1length);
}

else if(option == 2){
char stringcpy[string1length];
for(i=0;i<string1length;i++){
stringcpy[i]=string1[i];}
printf("string copied");
}

else if(option == 3){
printf("Enter string 2 : ");
char string2[100];
scanf("%s",&string2);
int string2length=0;
int j=0;
for (j=0;;j++){
if(string1[j]!='\0'){
string2length++;
}else{
break;}
}
char stringcat[string1length+string2length];
for(j=0;j<string1length+string2length;j++){
if(j<string1length){stringcat[j]=string1[j];
}else{stringcat[j]=string2[j-string1length];}
printf("%c",stringcat[j]);
}
}


else if(option == 4){
int j=0;
while(string1[j]!='\0'){
if(string1[j]>='a'&&string1[j]<='z')
string1[j]=string1[j]-32;
j++;
}
printf("%s",string1);
}


else if(option == 5){
char stringrev[string1length];
int j=0;
int indexrev=0;
for(j=string1length;j>0;j--){
stringrev[indexrev]=string1[j];
printf("%c",stringrev[indexrev]);
indexrev++;

}

}

else if(option == 6){
int j=0;
while(string1[j]!='\0'){
if(string1[j]>='A'&&string1[j]<='Z')
string1[j]=string1[j]+32;
j++;
}
printf("%s",string1);
}

else if(option == 7){
char charse[1];
printf("Enter the charachter you want to set to full legth: ");
scanf("%s",&charse);
int j=0;
for(j=0;j<string1length;j++){
string1[j]=charse[0];
printf("%c",string1[j]);
}
}

else if(option == 8){
printf("Enter string 2: ");
char string2[100];
scanf("%s",&string2);
int string2length=0;
int j=0;
for (j=0;;j++){
if(string2[j]!='\0'){
string2length++;
}else{
break;}
}
if(string1length==string2length){
int cmpstatus=0;
for(j=0;j<string1length;j++){
if(string1[j]!=string2[j])
cmpstatus=1;
}
if(cmpstatus==0)
printf("strings are equal");
else
printf("strings are different");
}else
printf("lengths not equal");

}

else if(option == 9){
printf("the first charachter is : %c",string1[0]);
}

else if(option == 10){
printf("the last charachter is : %c",string1[string1length-1]);
}

else {printf("input not valid");}


printf("\n");
return 0;
}
