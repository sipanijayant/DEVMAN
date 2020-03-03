#include<stdio.h>
#include"ui.h"
#include<stdlib.h>
void flush()
{while(getchar()!='\n');}
int main()
{system("clear");
char choice;
int flag=1;

title("WELCOME TO THE DEVMAN", '|', '-', 2);
do
{choice='\0';
printf("Enter:\n1)for Developing passwords\n2)for Managing/Accessing passwords\n3)CHECK my password strength\n0)FOR exitting\n");
scanf("%c",&choice);
flush(stdin);
switch(choice)
{case '1':{flag=0;system("./devpassk.out");break;}//int n=devpass();
case '2':{flag=0;system("./seepassk.out");break;}//int n=seepass();
case '3':{flag=0;system("./passwordstrength.out");break;}
case '0':exit(0);break;
default:flag=1;
}
}while(choice);
return 0;}


