#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#include"maininterface.h"
#include"rsa.h"
void flush()
{while(getchar() != '\n');	
}

void dev_encrypt(netinfo*);
void dev_decrypt(netinfo*);
void numcpy(int *msg_int, int *en);


int main()
{while(1)
{char n;
printf("ENTER\n1:For seeing one of your passwords\n2:For seeing all  your passwords\n0:For going back\n");
scanf("%c",&n);flush(stdin);
switch(n)
{case '1':{char username1[100];char pin1[5];
	printf("Enter the userid\n");
	scanf("%s",username1);flush(stdin);
	printf("Enter the 4 digit pin\n");
	scanf("%[^\n]s",pin1);flush(stdin);
	char useo[50];
	printf("Enter the USE i.e. WEBSITE name\n");
	scanf("%[^\n]s",useo);flush(stdin);
	FILE *fp=fopen("userdetails.bin","rb+");
	netinfo det;
int flag=0;
	while(fread(&det,sizeof(netinfo),1,fp))
		{	
			dev_decrypt(&det);
			if (strcmp(det.username,username1)==0 && strcmp(det.pin,pin1)==0 && strcmp(det.use,useo)==0)
			{char *pwdstored=(char *)malloc(sizeof(char)*11);
printf("Encrypted password:\t");
			for(int i=0;i<10;i++)
				{*(pwdstored+i)=(char)(((int)det.userkey[9-i]^(int)det.pass[i]));
				printf("%c",*(pwdstored+i));}
			printf("\n");
printf("\n%s\n",det.userkey);flag=1;
			break;}}
	if (flag==0)
		printf("RECORD not FOUND\n");break;}

case '2':{char username1[100];char pin1[5];
	printf("Enter the userid\n");
	scanf("%s",username1);flush(stdin);
	printf("Enter the 4 digit pin\n");
	scanf("%[^\n]s",pin1);flush(stdin);
	FILE *fp=fopen("userdetails.bin","rb+");
	netinfo det;
	int flag=0;
	while(fread(&det,sizeof(netinfo),1,fp))
		{	dev_decrypt(&det);
			if (strcmp(det.username,username1)==0 && strcmp(det.pin,pin1)==0)
			{printf("%s:\n",det.use);

		char *pwdstored=(char *)malloc(sizeof(char)*11);
			for(int i=0;i<10;i++)
				{*(pwdstored+i)=(char)(((int)det.userkey[9-i]^(int)det.pass[i])%256);

				printf("%c",*(pwdstored+i));}

			flag=1;
			}}
	if (flag==0)
		printf("RECORD not FOUND\n");
	break;}
case '0':system("./cproject.out");break;}}}
			
			
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

//seepass.c
//Displaying seepass.c.

