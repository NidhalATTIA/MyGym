#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ajout.h"
#include <gtk/gtk.h>

void ajoute (date d)
{int n=0;
FILE *f;
f=fopen("dispo.txt","a+");
fprintf(f,"%d %d %d %d %d\n",d.num,d.heure,d.jour,d.mois,d.annee);

 	
fclose(f);

}
void afficher (GtkWidget *liste ) 
{ 
enum { NUM,
	HEURE,
       JOUR,
       MOIS, 
       ANNEE, 	
       COLUMNS
      };
char num[30],heure[30],jour[30],mois[30],annee[30];
	GtkTreeIter iter;
	GtkListStore *store;
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	store=NULL;
FILE *f;
		
	        if (store==NULL)
{
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("num", renderer,"text",NUM,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
           	renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("heure", renderer,"text",HEURE,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

                renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("jour", renderer,"text",JOUR,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
           	
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("mois", renderer,"text",MOIS,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("annee", renderer,"text",ANNEE,NULL);	
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
}	
		store=gtk_list_store_new (COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
	        

f=fopen("dispo.txt","r");
if(f!=NULL)
{
while(fscanf(f,"%s %s %s %s %s \n",num,heure,jour,mois,annee)!=EOF)
{
gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,NUM,num,HEURE,heure,JOUR,jour,MOIS,mois,ANNEE,annee,-1);
}
fclose(f);
gtk_tree_view_set_model (GTK_TREE_VIEW (liste),GTK_TREE_MODEL (store));
}
}

void supprim(int num1)
{
FILE *f;
FILE *f1;
date d;
int test=-1;
f=fopen("dispo.txt","r");
f1=fopen("fich.txt","a+");
while (fscanf(f,"%d %d %d %d %d",&d.num,&d.heure,&d.jour,&d.mois,&d.annee)!=EOF)
{if (d.num!=num1)
fprintf(f1,"%d %d %d %d %d\n",d.num,d.heure,d.jour,d.mois,d.annee);
}
fclose(f);
fclose(f1);
rename("fich.txt","dispo.txt");												

}
int verif(int num)
{FILE *f;
date d;
int n=0;
f=fopen("dispo.txt","r");

while (fscanf(f,"%d %d %d %d %d",&d.num,&d.heure,&d.jour,&d.mois,&d.annee)!=EOF)
{if (num==d.num)
n=1;
}
return(n);
}
void modif(int num1,int heure1,int jour1,int mois1,int annee1)
{
FILE *f;
FILE *f1;
date d;
int test=-1;
f=fopen("dispo.txt","r");
f1=fopen("fich.txt","a+");
while (fscanf(f,"%d %d %d %d %d",&d.num,&d.heure,&d.jour,&d.mois,&d.annee)!=EOF)
{if (d.num!=num1)
fprintf(f1,"%d %d %d %d %d\n",d.num,d.heure,d.jour,d.mois,d.annee);
else 
fprintf(f1,"%d %d %d %d %d\n",num1,heure1,jour1,mois1,annee1);

}
fclose(f);
fclose(f1);
rename("fich.txt","dispo.txt");

}

void afficher1 (GtkWidget *liste ) 
{ 
enum { NOM,

	
       
       PRENOM, 
       AGE, 	
       POID,
	TAILLE,
	COLUMNS
      };
char nom[30],prenom[30],age[30],poid[30],taille[30];
	GtkTreeIter iter;
	GtkListStore *store;
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	store=NULL;
FILE *f;
		
	        if (store==NULL)
{
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("nom", renderer,"text",NOM,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
           	renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("prenom", renderer,"text",PRENOM,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

                renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("age", renderer,"text",AGE,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
           	
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("poid", renderer,"text",POID,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("taille", renderer,"text",TAILLE,NULL);	
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
}	
		store=gtk_list_store_new (COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
	        

f=fopen("fichem.txt","r");
if(f!=NULL)
{
while(fscanf(f,"%s %s %s %s %s\n",nom,prenom,age,poid,taille)!=EOF)
{
gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,NOM,nom,PRENOM,prenom,AGE,age,POID,poid,TAILLE,taille,-1);
}
fclose(f);
gtk_tree_view_set_model (GTK_TREE_VIEW (liste),GTK_TREE_MODEL (store));
}
}
