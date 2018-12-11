#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ajout.h"
#include "personne.h"
#include "supprimer.h"
#include <gtk/gtk.h>

void sup_speci(char num[30])// a dekhla en parametre 
{
	char Nom1 [30];
	char age1 [30];
	char poids1 [30];
	char probleme_med1 [30];
        char taille1[30];
        char allergie1[30];
        char sang1[30];
        char traitement1[30];
        char note1[30];
        char num1[30];

	FILE *l;
	FILE *t;
	l=fopen("/home/yasser/saisir/ajouter.txt","r");
	t=fopen("utilisateur.tmp","a+");
	while (fscanf(l,"%s %s %s %s %s %s %s %s %s %s \n",Nom1,age1,poids1,probleme_med1,taille1,allergie1,sang1,traitement1,note1,num1)!=EOF)//na9raw mil fichier temporaire
	{
		if (strcmp(num,num1)!=0)//ken la valeur ili na9raw fiha differente mil parametre ya3ni ncopiw i ligne fel fichier e jdid
		{
			fprintf(t,"%s %s %s %s %s %s %s %s %s %s \n",Nom1,age1,poids1,probleme_med1,taille1,allergie1,sang1,traitement1,note1,num1);//copie de la ligne fel fichier jdid
		}
	}
	fclose(l);
	fclose(t);
	remove("/home/yasser/saisir/ajouter.txt");//nfas5ou il fichier li9dim
	rename("utilisateur.tmp","/home/yasser/saisir/ajouter.txt");//enronomiw il fichier ejdid b esm li9dim bech ye5ou blastou
}

