#include <stdio.h>
#include <stdlib.h>
#include "suppdispo.h"
#include <gtk/gtk.h>

void sup_dispo(char Num[30])// a dekhla en parametre 
{
	char heure1 [30];
	char jour1 [30];
	char mois1 [30];
	char annee1 [30];
        char num1[30];
	FILE *l;
	FILE *t;
	l=fopen("/home/yasser/saisir/rdv.txt","r");
	t=fopen("utilisateur.tmp","a+");
	while (fscanf(l,"%s %s %s %s %s \n",heure1,jour1,mois1,annee1,num1)!=EOF)//na9raw mil fichier temporaire
	{
		if (strcmp(Num,num1)!=0)//ken la valeur ili na9raw fiha differente mil parametre ya3ni ncopiw i ligne fel fichier e jdid
		{
			fprintf(t,"%s %s %s %s %s  \n",heure1,jour1,mois1,annee1,num1);//copie de la ligne fel fichier jdid
		}
	}
	fclose(l);
	fclose(t);
	remove("/home/yasser/saisir/rdv.txt");//nfas5ou il fichier li9dim
	rename("utilisateur.tmp","/home/yasser/saisir/rdv.txt");//enronomiw il fichier ejdid b esm li9dim bech ye5ou blastou
}
