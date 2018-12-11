#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "verifl.h"

int verifier (char login[], char password[])
{
	
	int role=-1,r;
	char log[20],pass[20];
	FILE* f;


	f=fopen("/home/amin/Projects/project8/src/veriflogin.txt","r");
	if(f !=NULL) 
	{
		while(fscanf(f,"%s %s \n",log,pass,&r)!=EOF)
		{ 
			if((strcmp(login,log)==0) && (strcmp(password,pass)==0))
				role=r;	
		}
	fclose(f);
	}
	
	return role;
}

