#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "verifier.h"
int verif (char login[],char passwordentry[])
{
FILE *f;
char username[20];
char password[20];
int role;
f=fopen("/home/yasser/saisir/perso.txt","r");
if(f!=NULL)
{ 
while (fscanf(f,"%s %s %d",username,password,&role)!=EOF)
  { 
if ((strcmp(login,username)==0) && strcmp(passwordentry,password)==0)
{
	return(role);
}
}
return 0;
}
fclose(f);
}
