#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ajout.h"
#include <gtk/gtk.h>

void ajoute (date d)
{
FILE *f;
f=fopen("/home/yasser/saisir/rdv.txt","a+");
fprintf(f,"%d %d %d %d %d\n",d.heure,d.jour,d.mois,d.annee,d.Num);	
fclose(f);
}
void afficher(GtkWidget *liste ) 
{ 
enum { HEURE,
       JOUR,
       MOIS, 
       ANNEE,
       NUM,	
       COLUMNS
      };
char heure[30],jour[30],mois[30],annee[30],Num[30];
	GtkTreeIter iter;
	GtkListStore *store;
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	store=NULL;
FILE *f;
	
	        if (store==NULL)
{

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
                
                renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Num", renderer,"text",NUM,NULL);	
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
}	
		store=gtk_list_store_new (COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
	        

f=fopen("/home/yasser/saisir/rdv.txt","r");
if(f!=NULL)
{
while(fscanf(f,"%s %s %s %s %s \n",heure,jour,mois,annee,Num)!=EOF)
{
gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,JOUR,jour,MOIS,mois,ANNEE,annee,HEURE,heure,NUM,Num,-1);
}
fclose(f);
gtk_tree_view_set_model (GTK_TREE_VIEW (liste),GTK_TREE_MODEL (store));
}
}
