#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include<ctype.h>
#include"maininterface.h"
#include"rsa.h"

void flush();
void dev_encrypt(netinfo*);
void dev_decrypt(netinfo*);
void numcpy(int *msg_int, int *en);

int main()
{char usid[100];char mess[100] = "Phone number:";char email_id[100],phonenum[11];
char pin1[5];
while(1)
{printf("Press\n1)For new user\n2)For pre-existing users\n0)For going back\n");
char ch;char ch1;
scanf("%c%c",&ch,&ch1);
switch(ch)
{case '1':{printf("Please enter your:\n");
printf("Name:(SERVES AS YOUR USERID)\n");
scanf("%[^\n]s",usid);
flush(stdin);

printf("Email id(most important part incase of password loss):");
scanf("%[^\n]s",email_id);
flush(stdin);

while(1)
{printf("%s", mess);
int flag=0;
scanf("%s",phonenum);

//checking if the phonenumber is entered correctly
if (strlen(phonenum)==10)
{for(int i=0;i<10;i++)
{if (isdigit(phonenum[i])!=0)

flag+=1;}}
if (flag==10)
{break;}
else
{
	strcpy(mess, "Please re-enter your phone number :\n");
}
}
flush(stdin);
printf("A 4 digit pin(can contain numbers,alphabets and special characters).THIS HAS TO BE REMEMBERED along with the respective cases(lower case and upper case)\n");
scanf("%[^\n]s",pin1);
flush(stdin);

//Generating USER-ID and password as well as a unique key for the new user-This will take random number&alphabet generator.
/*Also a random key will be generated.Each element of the key will then be XOR'ed with each element of
the generated password and the generated password will be stored internally in the encrypted manner*/
char c[100]="0123456789qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM!@#$%^&()/-+.?><,:{}[]";//Length of this array is 86 characters.
srand(time(0));

char* keyfornewuser;
keyfornewuser=(char *)malloc(sizeof(char)*11);
char* passwordfornewuser;
passwordfornewuser=(char *)malloc(sizeof(char)*11);

char key[11];
char pas[11];

for(int i=0;i<10;i++)
{int f=rand();char j=c[f%86];
*(keyfornewuser+i)=j;key[i]=j;}
*(keyfornewuser+10)='\0';
key[10]='\0';


for(int i=0;i<10;i++)
{int f=rand();char j=c[f%86];
*(passwordfornewuser+i)=j;

}
*(passwordfornewuser+10)='\0';

netinfo det;
char *pwdstored=(char *)malloc(sizeof(char)*11);
for(int i=0;i<10;i++)
{*(pwdstored+i)=*(keyfornewuser+9-i)^*(passwordfornewuser+i);pas[i]=*(pwdstored+i);}
pas[10]='\0';

for(int i=0;i<10;i++)
{*(pwdstored+i)=*(keyfornewuser+9-i)^*(passwordfornewuser+i);pas[i]=*(pwdstored+i);}
pas[10]='\0';

char use[50];
printf("Enter the use(WEBSITE NAME only)\n");
scanf("%[^\n]s",det.use);
flush(stdin);
strcpy(det.username,usid);
strcpy(det.emailid,email_id);
strcpy(det.phonenumber,phonenum);
strcpy(det.pass,pas);
strcpy(det.userkey,key);
strcpy(det.pin,pin1);

FILE *fp=fopen("userdetails.bin","ab");
dev_encrypt(&det);
fwrite(&det,sizeof(netinfo),1,fp);
fclose(fp);
break;}

case '2':{FILE *fp=fopen("userdetails.bin","ab+");

char username1[100];
printf("Enter username\n");
scanf("%s",username1);
flush(stdin);
char pin2[5];
printf("Enter 4 digit pin\n");
scanf("%[^\n]s",pin2);
flush(stdin);
int flag=0;
int i=0;
netinfo det1;
while(fread(&det1,sizeof(netinfo),1,fp))
{
dev_decrypt(&det1);
if (strcmp(det1.username,username1)==0 && strcmp(det1.pin,pin2)==0)
{netinfo det;
det=det1;
char usero[50];
printf("Enter the use(WEBSITE NAME only)\n");
scanf("%[^\n]s",usero);
flush(stdin);
strcpy(det.use,usero);

char* keyfornewuser;
keyfornewuser=(char *)malloc(sizeof(char)*11);
char* passwordfornewuser;
passwordfornewuser=(char *)malloc(sizeof(char)*11);
char key[11];
char pas[11];
char c[100]="0123456789qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM!@#$%^&()/-+.?><,:{}[]";

for(int i=0;i<10;i++)

{int f=rand();char j=c[f%86];
*(keyfornewuser+i)=j;;key[i]=*(keyfornewuser+i);}
*(keyfornewuser+10)='\0';
key[10]='\0';

for(int i=0;i<10;i++)
{int f=rand();char j=c[f%86];
*(passwordfornewuser+i)=j;}
*(passwordfornewuser+10)='\0';

char *pwdstored=(char *)malloc(sizeof(char)*11);
for(int i=0;i<10;i++)
{*(pwdstored+i)=*(keyfornewuser+9-i)^*(passwordfornewuser+i);pas[i]=*(pwdstored+i);}
pas[10]='\0';

strcpy(det.pass,pas);
strcpy(det.userkey,key);
dev_encrypt(&det);
fwrite(&det,sizeof(netinfo),1,fp);
flag=1;fclose(fp);
break;
}
if (flag==0)
{printf("RECORD NOT FOUND\n");}
}break;
}
case '0':system("./cproject.out");break;}}}

void flush()
{
while(getchar() != '\n');	
}

void dev_encrypt(netinfo *det)
{
	str rc;
	strcpy(rc.msg, det->use);
	numcpy(det->use_i, encry_inter(1, rc).msg_int);

	strcpy(rc.msg, det->username);
	numcpy(det->username_i, encry_inter(1, rc).msg_int);

	strcpy(rc.msg, det->emailid);
	numcpy(det->emailid_i, encry_inter(1, rc).msg_int);

	strcpy(rc.msg, det->phonenumber);
	numcpy(det->phonenumber_i, encry_inter(1, rc).msg_int);

	strcpy(rc.msg, det->pin);
	numcpy(det->pin_i, encry_inter(1, rc).msg_int);

	strcpy(rc.msg, det->userkey);
	numcpy(det->userkey_i, encry_inter(1, rc).msg_int);

	strcpy(rc.msg, det->pass);
	numcpy(det->pass_i, encry_inter(1, rc).msg_int);
}

void dev_decrypt(netinfo *det)
{
	str rc;
	numcpy(rc.msg_int, det->use_i);
	strcpy(det->use, encry_inter(2, rc).msg);

	numcpy(rc.msg_int, det->username_i);
	strcpy(det->username, encry_inter(2, rc).msg);

	numcpy(rc.msg_int, det->emailid_i);
	strcpy(det->emailid, encry_inter(2, rc).msg);

	numcpy(rc.msg_int, det->phonenumber_i);
	strcpy(det->phonenumber, encry_inter(2, rc).msg);

	numcpy(rc.msg_int, det->pin_i);
	strcpy(det->pin, encry_inter(2, rc).msg);

	numcpy(rc.msg_int, det->userkey_i);
	strcpy(det->userkey, encry_inter(2, rc).msg);

	numcpy(rc.msg_int, det->pass_i);
	strcpy(det->pass, encry_inter(2, rc).msg);
}

void numcpy(int *msg_int, int *en)
{
	int i;
	for(i=0;en[i] != -1;i++) 
    	msg_int[i] = en[i];
	msg_int[i] = -1;
}


/*Here we are bound to use XOR algorithm for encryption of our passwords as well as the user-id Since it 
would need reading from files and other concepts we haven't coded it as of now*/ 
