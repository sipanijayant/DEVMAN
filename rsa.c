#include<stdio.h> 
#include<stdlib.h> 
#include<math.h> 
#include<string.h> 
#include"rsa.h"


char *strrev(char *str);
char *strrev(char *str)
{
      char *p1, *p2;

      if (! str || ! *str)
            return str;
      for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
      {
            //swappping operation done below without temp variable
            *p1 ^= *p2;
            *p2 ^= *p1;
            *p1 ^= *p2;
      }
      return str;
}

void num_to_str(char * output, long num)
{
    int i = 0;
    while(num != 0)
    {
        output[i] = (num%10) + 48;
        num/= 10;
        i++;
    }
    output[i] = '\0';
    strcpy(output, strrev(output));
}

str encry_inter(int choice, str src)
{ 
str rc;
p = 7;
q = 11;
n=p*q; 
t=(p-1)*(q-1); 
ce(); 
int i = 0;

switch(choice)
{
case 1:
strcpy(msg, src.msg);
for(i=0;msg[i]!='\0';i++) 
	m[i]=msg[i]; 
rc = encrypt(); 
return rc;
break;

case 2:
for(i=0;src.msg_int[i]!=-1;i++) 
{
	en[i]=src.msg_int[i]; 
}
en[i]=-1;
rc = decrypt(); 
return rc;
}

} 


int prime(long int pr) 
{ 
int i; 
double j;
j=pow((double)pr,0.5); 
for(i=2;i<=j;i++) 
{ 
    if(pr%i==0) 
    return 0; 
} 
return 1; 
} 

void ce() 
{ 
int k; 
k=0; 
int i = 0;
for(i=2;i<t;i++) 
{ 
    if(t%i==0) 
    	continue; 
    flag=prime(i); 
    if(flag==1&&i!=p&&i!=q) 
    { 
        e[k]=i; 
        flag=cd(e[k]); 
        if(flag>0) 
        { 
            d[k]=flag; 
            k++; 
        } 
        if(k==99) 
        	break; 
    } 
} 
} 
long int cd(long int x) 
{ 
long int k=1; 
while(1) 
{ 
    k=k+t; 
    if(k%x==0) 
    	return(k/x); 
} 
} 

str encrypt() 
{ 
str rc;
long int pt,ct,key=e[0],k,len; 
int i = 0;
len=strlen(msg); 
while(i!=len) 
{ 
    pt=m[i]; 
    pt=pt-96; 
    k=1; 
    for(j=0;j<key;j++) 
    { 
        k=k*pt; 
        k=k%n; 
    } 
    ct=k+96; 
    en[i]=ct; 
    i++; 
} 
en[i]=-1; 

for(i=0;en[i]!=-1;i++) 
    rc.msg[i] = en[i]; 
rc.msg[i] = '\0';

for(i=0;en[i]!=-1;i++) 
    rc.msg_int[i] = en[i];
rc.msg_int[i] = -1;
return rc;
} 

str decrypt() 
{ 

str rc;
long int pt,ct,key=d[0],k; 
int i = 0;
while(en[i]!=-1) 
{ 
    ct=en[i] - 96; 
    k=1; 
    for(j=0;j<key;j++) 
    { 
        k=k*ct; 
        k=k%n; 
    } 
    pt=k+96; 
    m[i]=pt; 
    i++; 
} 
m[i]=-1; 

for(i=0;m[i]!=-1;i++) 
    rc.msg[i] = m[i];
rc.msg[i] = '\0';

for(i=0;m[i]!=-1;i++) 
    rc.msg_int[i] = m[i];
return rc; 
}

/*
int main()
{
    str rc;
    strcpy(rc.msg, "hello world");

    int num = 10890;
    char output[100];
    rc = encry_inter(1, rc);
    printf("e : %s\n", rc.msg);
    rc = encry_inter(2, rc);
    printf("d : %s\n", rc.msg);

    num_to_str(output, num);

    printf("%s\n", output);
    return 0;
}
*/
