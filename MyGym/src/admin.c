#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "admin.h"

int verifier (char login[], char Password[])
{FILE*f;
int y=0,role=0;
char login1[30],Password1[30];

f=fopen("/home/Projects/project3/src/users.txt","r");
if(f!=NULL) { 
while (fscanf(f,"%s %s %d",login1,Password1,&role)!=EOF) 
{	
	if((strcmp(login1,login)==0) && (strcmp(Password1,Password)==0) )
	{return role; }
	}}


fclose(f);}

/*------------------------------------------------------------------*/

void ajout (In I)
{
	FILE *f;
	f=fopen("/home/Projects/project3/src/formulaire.txt","a+");
	if (f!=NULL)
	{
		fprintf(f,"%s %s %d %s %s %s",I.nom,I.prenom,I.cin,I.date,I.adresse,I.mail);
		fclose(f);
	}
}

/*------------------------------------------------------------------*/

void afficher(GtkWidget *liste)
{
        GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter    iter;
	GtkListStore *store;

	char nom [30];
	char prenom [30];
        int cin;
	char date [30];
	char adresse [30];
	char mail[40];

        store=NULL;

       FILE *f;
	
	store=gtk_tree_view_get_model(liste);	
	if (store==NULL)
	{

                renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  cin", renderer, "text",cin, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" nom", renderer, "text",nom, NULL);	
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);	
	
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  prenom", renderer, "text",prenom, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  date", renderer, "text",date, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  adresse", renderer, "text",adresse, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  mail", renderer, "text",mail, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
               
	
	}

	store=gtk_list_store_new (column, G_TYPE_STRING,  G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

	f = fopen("/home/Projects/project3/src/formulaire.txt", "r");
	
	if(f==NULL)
	{

		return;
	}		
	else 

	{ f = fopen("/home/Projects/project3/src/formulaire.txt", "a+");
              while(fscanf(f,"%s %s %d %s %s %s \n",nom,prenom,cin,date,adresse,mail)!=EOF)
		{

	gtk_list_store_append (store, &iter);
	gtk_list_store_set (store, &iter, cin, nom, prenom,date,adresse,mail, -1); 

		}
		fclose(f);
	gtk_tree_view_set_model (GTK_TREE_VIEW (liste),  GTK_TREE_MODEL (store));
    g_object_unref (store);
	}
}

/*------------------------------------------------------------------*/
	
