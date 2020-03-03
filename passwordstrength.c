#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void flush()
{while(getchar()!='\n');}
int main()//here,we will take a string along with it's length as parameters
{char c[100];
printf("ENTER the password you want to check for\n");
scanf("%[^\n]s",c);
flush(stdin);
int flag=0;
int alpc=0,non=0,noc=0,alpl=0;
if (strlen(c)>9)

{for (int i=0;i<strlen(c);i++)
{int k=(int)c[i];

if (k>64 && k<91)
alpc++;
else if (k>96 && k<123)
alpl++;
else if (k>47 && k<58)
non++;
else if (k!=32)
noc++;}}
else
{
flag=1;
}
if (flag==0 && alpc+alpl>0 && non>0 && noc>0)
{printf("-> Valid Password !\n");}
else
{printf("-> Invalid Password !\n");}
getchar();
system("./cproject.out");}



