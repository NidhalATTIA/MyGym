#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ajout.h"
#include "personne.h"
#include "modifier.h"
#include "supprimer.h"
#include <gtk/gtk.h>

void modifi(char Nom[],char age[],char poids[],char probleme_med[],char taille[],char allergie[],char sang[],char traitement[],char note[],char num[])
{
FILE*f;
FILE*f1;
char Nom2[50];
char age2[50];
char poids2[50];
char probleme_med2[50];
char taille2[50];
char allergie2[50];
char sang2[50];
char traitement2[50];
char note2[50];
char num2[50];
f=fopen("/home/yasser/saisir/ajouter.txt","r");
f1=fopen("fichier.txt","w");
while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s \n",Nom2,age2,poids2,probleme_med2,taille2,allergie2,sang2,traitement2,note2,num2)!=EOF)
{
if(strcmp(num,num2)==0)
{
fprintf(f1,"%s %s %s %s %s %s %s %s %s %s \n",Nom,age,poids,probleme_med,taille,allergie,sang,traitement,note,num);
}
else
{
fprintf(f1,"%s %s %s %s %s %s %s %s %s %s \n",Nom2,age2,poids2,probleme_med2,taille2,allergie2,sang2,traitement2,note2,num2);
}
}
  fclose(f);
  fclose(f1);
  remove("/home/yasser/saisir/ajouter.txt");
  rename("fichier.txt","/home/yasser/saisir/ajouter.txt");
}
