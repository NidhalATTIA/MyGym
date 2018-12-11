#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ajou.h"
#include <gtk/gtk.h>

void ajouter ( dispo d)
{int n=0;
FILE *f;
f=fopen("dispo1.txt","a+");
fprintf(f,"%d %d %d %d %d %d\n",d.num,d.de,d.a,d.jour,d.mois,d.annee);

 	
fclose(f);

}


void afficherr (GtkWidget *liste ) 
{ 
enum { NUM,
	DE,
	A,
       JOUR,
       MOIS, 
       ANNEE, 	
       COLUMNS
      };
char num[30],de[30],a[30],jour[30],mois[30],annee[30];
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
		column = gtk_tree_view_column_new_with_attributes("de", renderer,"text",DE,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

           	renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("a", renderer,"text",A,NULL);
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
		store=gtk_list_store_new (COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
	        

f=fopen("dispo1.txt","r");
if(f!=NULL)
{
while(fscanf(f,"%s %s %s %s %s %s \n",num,de,a,jour,mois,annee)!=EOF)
{
gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,NUM,num,DE,de,A,a,JOUR,jour,MOIS,mois,ANNEE,annee,-1);
}
fclose(f);
gtk_tree_view_set_model (GTK_TREE_VIEW (liste),GTK_TREE_MODEL (store));
}
}

int verife(int num)
{FILE *f;
dispo d;
int n=0;
f=fopen("dispo1.txt","r");

while (fscanf(f,"%d %d %d %d %d %d",&d.num,&d.de,&d.a,&d.jour,&d.mois,&d.annee)!=EOF)
{if (num==d.num)
n=1;
}}

void supprime(int num1)
{
FILE *f;
FILE *f1;
dispo d;
int test=-1;
f=fopen("dispo1.txt","r");
f1=fopen("fich.txt","a+");
while (fscanf(f,"%d %d %d %d %d %d",&d.num,&d.de,&d.a,&d.jour,&d.mois,&d.annee)!=EOF)
{if (d.num!=num1)
fprintf(f1,"%d %d %d %d %d %d\n",d.num,d.de,d.a,d.jour,d.mois,d.annee);
}
fclose(f);
fclose(f1);
rename("fich.txt","dispo1.txt");												

}

void modife(int num1,int de1,int a1,int jour1,int mois1,int annee1)
{
FILE *f;
FILE *f1;
dispo d;
int test=-1;
f=fopen("dispo1.txt","r");
f1=fopen("fich.txt","a+");
while (fscanf(f,"%d %d %d %d %d %d",&d.num,&d.de,&d.a,&d.jour,&d.mois,&d.annee)!=EOF)
{if (d.num!=num1)
fprintf(f1,"%d %d %d %d %d %d\n",d.num,d.de,d.a,d.jour,d.mois,d.annee);
else 
fprintf(f1,"%d %d %d %d %d %d\n",num1,de1,a1,jour1,mois1,annee1);

}
fclose(f);
fclose(f1);
rename("fich.txt","dispo1.txt");

}
