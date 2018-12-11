#include <stdio.h>
#include <string.h>
#include "personne.h"
#include <gtk/gtk.h>
enum
{
   NOM,
   AGE,
   POIDS,
   PROBLEME_MED,
   TAILLE,
   ALLERGIE,
   SANG,
   TRAITEMENT,
   NOTE,
   NUM,
   COLUMNS
};
void ajouter_fiche(fiche p)

{
FILE *f;
f=fopen("/home/yasser/saisir/ajouter.txt","a+");
if(f!=NULL) 
  {
fprintf(f,"%s %s %s %s %s %s %s %s %s %s \n",p.Nom,p.age,p.poids,p.probleme_med,p.taille,p.allergie,p.sang,p.traitement,p.note,p.num);
fclose(f); 
}
}




void afficher_fiche (GtkWidget *liste)
{
        GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter    iter;
	GtkListStore *store;

	char Nom [30];
	char age [30];
	char poids [30];
	char probleme_med [30];
        char taille[30];
        char allergie[30];
        char sang[30];
        char traitement[30];
        char note[30];
        char num[30];
        store=NULL;

       FILE *f;
	
	store=gtk_tree_view_get_model(liste);	
	if (store==NULL)
	{

                renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  nom", renderer, "text",NOM, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" age", renderer, "text",AGE, NULL);	
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);	
	
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  poids", renderer, "text",POIDS, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  probleme_med", renderer, "text",PROBLEME_MED, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  taille", renderer, "text",TAILLE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

                renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  allergie", renderer, "text",ALLERGIE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

                renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  sang", renderer, "text",SANG, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

                renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  traitement", renderer, "text",TRAITEMENT, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
 
                renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  note", renderer, "text",NOTE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

                renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  num", renderer, "text",NUM, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);




               
	
	}

	
	store=gtk_list_store_new (COLUMNS, G_TYPE_STRING,  G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,  G_TYPE_STRING,  G_TYPE_STRING,  G_TYPE_STRING,  G_TYPE_STRING, G_TYPE_STRING);

	f = fopen("/home/yasser/saisir/ajouter.txt", "r");
	
	if(f==NULL)
	{

		return;
	}		
	else 

	{ f = fopen("/home/yasser/saisir/ajouter.txt", "a+");
              while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s \n",Nom,age,poids,probleme_med,taille,allergie,sang,traitement,note,num)!=EOF)
		{
	gtk_list_store_append (store, &iter);
	gtk_list_store_set (store, &iter, NOM, Nom, AGE, age, POIDS, poids,PROBLEME_MED,probleme_med,TAILLE,taille,ALLERGIE,allergie,SANG,sang,TRAITEMENT,traitement,NOTE,note,NUM,num, -1); 
		}
		fclose(f);
	gtk_tree_view_set_model (GTK_TREE_VIEW (liste),  GTK_TREE_MODEL (store));
    g_object_unref (store);
	}
}

