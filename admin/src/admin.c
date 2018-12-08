#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "admin.h"
#include <gtk/gtk.h>

/*-----------------authentification-(vérifier)----------------------*/

int verifier (char login[], char Password[])
{
FILE*f;
int r,role=-1;
char login1[30],Password1[30];

f=fopen("/home/nidhal/Projects/admin/src/users.txt","r");
if(f!=NULL)
	{ 
	while (fscanf(f,"%s %s \n",login1,Password1,&r)!=EOF) 
		{	
	if((strcmp(login,login1)==0) && (strcmp(Password,Password1)==0) )
	
		role=r; 
		}
	fclose(f);
	}	

	return role;
}

/*------------------------ajouter_adherent--------------------------*/

void ajouter_adherent(Adherent ad)
{

 FILE *f;
  f=fopen("/home/nidhal/Projects/admin/src/adherent.txt","a+");
  if(f!=NULL) 
  {
  fprintf(f,"%s %s %s %s %s %s %s %s \n",ad.a_nom,ad.a_prenom,ad.a_cin,ad.a_jour,ad.a_mois,ad.a_an,ad.a_mail,ad.a_adresse);
  fclose(f);

  }

}

/*---------------------afficher_adherent----------------------------*/

enum
{
	NOM,
	PRENOM,
	CIN,
	DATE,
	DE,
	NAISSANCE,
	MAIL,
	ADRESSE,
	COLUMNS
};

void afficher_adherent(GtkWidget *liste)
{
        GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter    iter;
	GtkListStore *store;

	char nom[20];
	char prenom[20];
	char cin[20];
	char jour[20];
	char mois[20];
	char an[20];
	char mail[30];
	char adresse[50];
        store=NULL;

       FILE *f;
	
	store=gtk_tree_view_get_model(liste);	
	if (store==NULL)
	{

                renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" nom", renderer, "text",NOM, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" prenom", renderer, "text",PRENOM, NULL);	
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);	
	
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" cin", renderer, "text",CIN, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" jour", renderer, "text",DATE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" mois", renderer, "text",DE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" an", renderer, "text",NAISSANCE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" mail", renderer, "text",MAIL, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" adresse", renderer, "text",ADRESSE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
         	
	}

	
	store=gtk_list_store_new (COLUMNS, G_TYPE_STRING,  G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

	f = fopen("/home/nidhal/Projects/admin/src/adherent.txt", "r");
	
	if(f==NULL)
	{

		return;
	}		
	else 

	{ f = fopen("/home/nidhal/Projects/admin/src/adherent.txt", "a+");
              while(fscanf(f,"%s %s %s %s %s %s %s %s \n",nom,prenom,cin,jour,mois,an,mail,adresse)!=EOF)
		{
	gtk_list_store_append (store, &iter);
	gtk_list_store_set (store, &iter, NOM, nom, PRENOM, prenom, CIN, cin, DATE, jour, DE, mois, NAISSANCE, an, MAIL, mail, ADRESSE, adresse, -1); 
		}
		fclose(f);
	gtk_tree_view_set_model (GTK_TREE_VIEW (liste),  GTK_TREE_MODEL (store));
    g_object_unref (store);
	}
}

/*-----------------------supprimer_adherent----------------------------*/

void supprimer_adherent(char cinn[20])
{
	char nom[30];
	char prenom[30];
	char cin[30];
	char jour[30];
	char mois[30];
	char an[30];
	char mail[30];
	char adresse[50];

	FILE *l;
	FILE *t;
	l=fopen("/home/nidhal/Projects/admin/src/adherent.txt","r");
	t=fopen("/home/nidhal/Projects/admin/src/adherent.tmp","a+");
	while (fscanf(l,"%s %s %s %s %s %s %s %s \n",nom,prenom,cin,jour,mois,an,mail,adresse)!=EOF)
	{
		if (strcmp(cinn,cin)!=0)
		{
			fprintf(t,"%s %s %s %s %s %s %s %s \n",nom,prenom,cin,jour,mois,an,mail,adresse);
		}
	}
	fclose(l);
	fclose(t);
	remove("/home/nidhal/Projects/admin/src/adherent.txt");
	rename("/home/nidhal/Projects/admin/src/adherent.tmp","/home/nidhal/Projects/admin/src/adherent.txt");
}

/*-----------------------modifier_adherent----------------------------*/

void modifier_adherent(Adherent adm,char cinn[50])
{
Adherent ad;
FILE *f;
FILE *f2;
f=fopen("/home/nidhal/Projects/admin/src/adherent.txt","r");
f2=fopen("/home/nidhal/Projects/admin/src/nadherent.txt","w"); 
if (f!=NULL)
{
if (f2!=NULL)

{ 
     while (fscanf(f,"%s %s %s %s %s %s %s %s \n",ad.a_nom,ad.a_prenom, ad.a_cin, ad.a_jour, ad.a_mois, ad.a_an, ad.a_mail, ad.a_adresse)!=EOF)
    { 
    if((strcmp(cinn,ad.a_cin))!=0)
    {
    fprintf(f2,"%s %s %s %s %s %s %s %s \n",ad.a_nom,ad.a_prenom, ad.a_cin, ad.a_jour, ad.a_mois, ad.a_an, ad.a_mail, ad.a_adresse);
     }
else {
	fprintf(f2,"%s %s %s %s %s %s %s %s \n",adm.a_nom,adm.a_prenom, adm.a_cin, adm.a_jour, adm.a_mois, adm.a_an, adm.a_mail, adm.a_adresse);
     }
     }
     }}
fclose(f);
fclose(f2);

remove("/home/nidhal/Projects/admin/src/adherent.txt") ;
rename ("/home/nidhal/Projects/admin/src/nadherent.txt" , "/home/nidhal/Projects/admin/src/adherent.txt") ;
}

///////////////////COACH//////////////////////

/*------------------------ajouter_coach--------------------------*/

void ajouter_coach(Coach co)
{

 FILE *f;
  f=fopen("/home/nidhal/Projects/admin/src/coach.txt","a+");
  if(f!=NULL) 
  {
  fprintf(f,"%s %s %s %s %s %s %s %s \n",co.c_nom,co.c_prenom,co.c_cin,co.c_jour,co.c_mois,co.c_an,co.c_mail,co.c_adresse);
  fclose(f);

  }

}

/*---------------------afficher_coach----------------------------*/

enum
{
	c_NOM,
	c_PRENOM,
	c_CIN,
	c_DATE,
	c_DE,
	c_NAISSANCE,
	c_MAIL,
	c_ADRESSE,
	c_COLUMNS
};

void afficher_coach(GtkWidget *liste)
{
        GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter    iter;
	GtkListStore *store;

	char nom[20];
	char prenom[20];
	char cin[20];
	char jour[20];
	char mois[20];
	char an[20];
	char mail[30];
	char adresse[50];
        store=NULL;

       FILE *f;
	
	store=gtk_tree_view_get_model(liste);	
	if (store==NULL)
	{

                renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" nom", renderer, "text",NOM, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" prenom", renderer, "text",PRENOM, NULL);	
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);	
	
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" cin", renderer, "text",CIN, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" jour", renderer, "text",DATE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" mois", renderer, "text",DE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" an", renderer, "text",NAISSANCE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" mail", renderer, "text",MAIL, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" adresse", renderer, "text",ADRESSE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
         	
	}

	
	store=gtk_list_store_new (COLUMNS, G_TYPE_STRING,  G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

	f = fopen("/home/nidhal/Projects/admin/src/coach.txt", "r");
	
	if(f==NULL)
	{

		return;
	}		
	else 

	{ f = fopen("/home/nidhal/Projects/admin/src/coach.txt", "a+");
              while(fscanf(f,"%s %s %s %s %s %s %s %s \n",nom,prenom,cin,jour,mois,an,mail,adresse)!=EOF)
		{
	gtk_list_store_append (store, &iter);
	gtk_list_store_set (store, &iter, c_NOM, nom, c_PRENOM, prenom, c_CIN, cin, c_DATE, jour, c_DE, mois, c_NAISSANCE, an, c_MAIL, mail, c_ADRESSE, adresse, -1); 
		}
		fclose(f);
	gtk_tree_view_set_model (GTK_TREE_VIEW (liste),  GTK_TREE_MODEL (store));
    g_object_unref (store);
	}
}

/*-----------------------supprimer_coach----------------------------*/

void supprimer_coach(char cinn[20])
{
	char nom[30];
	char prenom[30];
	char cin[30];
	char jour[30];
	char mois[30];
	char an[30];
	char mail[30];
	char adresse[50];

	FILE *l;
	FILE *t;
	l=fopen("/home/nidhal/Projects/admin/src/coach.txt","r");
	t=fopen("/home/nidhal/Projects/admin/src/coach.tmp","a+");
	while (fscanf(l,"%s %s %s %s %s %s %s %s \n",nom,prenom,cin,jour,mois,an,mail,adresse)!=EOF)
	{
		if (strcmp(cinn,cin)!=0)
		{
			fprintf(t,"%s %s %s %s %s %s %s %s \n",nom,prenom,cin,jour,mois,an,mail,adresse);
		}
	}
	fclose(l);
	fclose(t);
	remove("/home/nidhal/Projects/admin/src/coach.txt");
	rename("/home/nidhal/Projects/admin/src/coach.tmp","/home/nidhal/Projects/admin/src/coach.txt");
}


/////////////////MEDECIN//////////////////

/*------------------------ajouter_med--------------------------*/

void ajouter_medecin(Medecin med)
{

 FILE *f;
  f=fopen("/home/nidhal/Projects/admin/src/medecin.txt","a+");
  if(f!=NULL) 
  {
  fprintf(f,"%s %s %s %s %s %s %s %s \n",med.m_nom,med.m_prenom,med.m_cin,med.m_jour,med.m_mois,med.m_an,med.m_mail,med.m_adresse);
  fclose(f);

  }

}

/*---------------------afficher_med----------------------------*/

enum
{
	m_NOM,
	m_PRENOM,
	m_CIN,
	m_DATE,
	m_DE,
	m_NAISSANCE,
	m_MAIL,
	m_ADRESSE,
	m_COLUMNS
};

void afficher_medecin(GtkWidget *liste)
{
        GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter    iter;
	GtkListStore *store;

	char nom[20];
	char prenom[20];
	char cin[20];
	char jour[20];
	char mois[20];
	char an[20];
	char mail[30];
	char adresse[50];
        store=NULL;

       FILE *f;
	
	store=gtk_tree_view_get_model(liste);	
	if (store==NULL)
	{

                renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" nom", renderer, "text",NOM, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" prenom", renderer, "text",PRENOM, NULL);	
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);	
	
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" cin", renderer, "text",CIN, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" jour", renderer, "text",DATE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" mois", renderer, "text",DE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" an", renderer, "text",NAISSANCE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" mail", renderer, "text",MAIL, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" adresse", renderer, "text",ADRESSE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
         	
	}

	
	store=gtk_list_store_new (COLUMNS, G_TYPE_STRING,  G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

	f = fopen("/home/nidhal/Projects/admin/src/medecin.txt", "r");
	
	if(f==NULL)
	{

		return;
	}		
	else 

	{ f = fopen("/home/nidhal/Projects/admin/src/medecin.txt", "a+");
              while(fscanf(f,"%s %s %s %s %s %s %s %s \n",nom,prenom,cin,jour,mois,an,mail,adresse)!=EOF)
		{
	gtk_list_store_append (store, &iter);
	gtk_list_store_set (store, &iter, m_NOM, nom, m_PRENOM, prenom, m_CIN, cin, m_DATE, jour, m_DE, mois, m_NAISSANCE, an, m_MAIL, mail, m_ADRESSE, adresse, -1); 
		}
		fclose(f);
	gtk_tree_view_set_model (GTK_TREE_VIEW (liste),  GTK_TREE_MODEL (store));
    g_object_unref (store);
	}
}

/*-----------------------supprimer_medecin----------------------------*/

void supprimer_medecin(char cinn[20])
{
	char nom[30];
	char prenom[30];
	char cin[30];
	char jour[30];
	char mois[30];
	char an[30];
	char mail[30];
	char adresse[50];

	FILE *l;
	FILE *t;
	l=fopen("/home/nidhal/Projects/admin/src/medecin.txt","r");
	t=fopen("/home/nidhal/Projects/admin/src/medecin.tmp","a+");
	while (fscanf(l,"%s %s %s %s %s %s %s %s \n",nom,prenom,cin,jour,mois,an,mail,adresse)!=EOF)
	{
		if (strcmp(cinn,cin)!=0)
		{
			fprintf(t,"%s %s %s %s %s %s %s %s \n",nom,prenom,cin,jour,mois,an,mail,adresse);
		}
	}
	fclose(l);
	fclose(t);
	remove("/home/nidhal/Projects/admin/src/medecin.txt");
	rename("/home/nidhal/Projects/admin/src/medecin.tmp","/home/nidhal/Projects/admin/src/medecin.txt");
}
////////////DIETETICIEN/////////////////////

/*------------------------ajouter_diet--------------------------*/

void ajouter_diet(Diet diet)
{

 FILE *f;
  f=fopen("/home/nidhal/Projects/admin/src/diet.txt","a+");
  if(f!=NULL) 
  {
  fprintf(f,"%s %s %s %s %s %s %s %s \n",diet.d_nom,diet.d_prenom,diet.d_cin,diet.d_jour,diet.d_mois,diet.d_an,diet.d_mail,diet.d_adresse);
  fclose(f);

  }

}

/*---------------------afficher_diet----------------------------*/

enum
{
	d_NOM,
	d_PRENOM,
	d_CIN,
	d_DATE,
	d_DE,
	d_NAISSANCE,
	d_MAIL,
	d_ADRESSE,
	d_COLUMNS
};

void afficher_diet(GtkWidget *liste)
{
        GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter    iter;
	GtkListStore *store;

	char nom[20];
	char prenom[20];
	char cin[20];
	char jour[20];
	char mois[20];
	char an[20];
	char mail[30];
	char adresse[50];
        store=NULL;

       FILE *f;
	
	store=gtk_tree_view_get_model(liste);	
	if (store==NULL)
	{

                renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" nom", renderer, "text",NOM, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" prenom", renderer, "text",PRENOM, NULL);	
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);	
	
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" cin", renderer, "text",CIN, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" jour", renderer, "text",DATE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" mois", renderer, "text",DE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" an", renderer, "text",NAISSANCE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" mail", renderer, "text",MAIL, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" adresse", renderer, "text",ADRESSE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
         	
	}

	
	store=gtk_list_store_new (COLUMNS, G_TYPE_STRING,  G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

	f = fopen("/home/nidhal/Projects/admin/src/diet.txt", "r");
	
	if(f==NULL)
	{

		return;
	}		
	else 

	{ f = fopen("/home/nidhal/Projects/admin/src/diet.txt", "a+");
              while(fscanf(f,"%s %s %s %s %s %s %s %s \n",nom,prenom,cin,jour,mois,an,mail,adresse)!=EOF)
		{
	gtk_list_store_append (store, &iter);
	gtk_list_store_set (store, &iter, d_NOM, nom, d_PRENOM, prenom, d_CIN, cin, d_DATE, jour, d_DE, mois, d_NAISSANCE, an, d_MAIL, mail, d_ADRESSE, adresse, -1); 
		}
		fclose(f);
	gtk_tree_view_set_model (GTK_TREE_VIEW (liste),  GTK_TREE_MODEL (store));
    g_object_unref (store);
	}
}

/*-----------------------supprimer_diet----------------------------*/

void supprimer_diet(char cinn[20])
{
	char nom[30];
	char prenom[30];
	char cin[30];
	char jour[30];
	char mois[30];
	char an[30];
	char mail[30];
	char adresse[50];

	FILE *l;
	FILE *t;
	l=fopen("/home/nidhal/Projects/admin/src/diet.txt","r");
	t=fopen("/home/nidhal/Projects/admin/src/diet.tmp","a+");
	while (fscanf(l,"%s %s %s %s %s %s %s %s \n",nom,prenom,cin,jour,mois,an,mail,adresse)!=EOF)
	{
		if (strcmp(cinn,cin)!=0)
		{
			fprintf(t,"%s %s %s %s %s %s %s %s \n",nom,prenom,cin,jour,mois,an,mail,adresse);
		}
	}
	fclose(l);
	fclose(t);
	remove("/home/nidhal/Projects/admin/src/diet.txt");
	rename("/home/nidhal/Projects/admin/src/diet.tmp","/home/nidhal/Projects/admin/src/diet.txt");
}

///////////////KINESITHERAPEUTE///////////////////

/*------------------------ajouter_kine--------------------------*/

void ajouter_kine(Kine kine)
{

 FILE *f;
  f=fopen("/home/nidhal/Projects/admin/src/kine.txt","a+");
  if(f!=NULL) 
  {
  fprintf(f,"%s %s %s %s %s %s %s %s \n",kine.k_nom,kine.k_prenom,kine.k_cin,kine.k_jour,kine.k_mois,kine.k_an,kine.k_mail,kine.k_adresse);
  fclose(f);

  }

}

/*---------------------afficher_kine----------------------------*/

enum
{
	k_NOM,
	k_PRENOM,
	k_CIN,
	k_DATE,
	k_DE,
	k_NAISSANCE,
	k_MAIL,
	k_ADRESSE,
	k_COLUMNS
};

void afficher_kine(GtkWidget *liste)
{
        GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter    iter;
	GtkListStore *store;

	char nom[20];
	char prenom[20];
	char cin[20];
	char jour[20];
	char mois[20];
	char an[20];
	char mail[30];
	char adresse[50];
        store=NULL;

       FILE *f;
	
	store=gtk_tree_view_get_model(liste);	
	if (store==NULL)
	{

                renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" nom", renderer, "text",NOM, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" prenom", renderer, "text",PRENOM, NULL);	
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);	
	
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" cin", renderer, "text",CIN, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" jour", renderer, "text",DATE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" mois", renderer, "text",DE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" an", renderer, "text",NAISSANCE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" mail", renderer, "text",MAIL, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" adresse", renderer, "text",ADRESSE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
         	
	}

	
	store=gtk_list_store_new (COLUMNS, G_TYPE_STRING,  G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

	f = fopen("/home/nidhal/Projects/admin/src/kine.txt", "r");
	
	if(f==NULL)
	{

		return;
	}		
	else 

	{ f = fopen("/home/nidhal/Projects/admin/src/kine.txt", "a+");
              while(fscanf(f,"%s %s %s %s %s %s %s %s \n",nom,prenom,cin,jour,mois,an,mail,adresse)!=EOF)
		{
	gtk_list_store_append (store, &iter);
	gtk_list_store_set (store, &iter, k_NOM, nom, k_PRENOM, prenom, k_CIN, cin, k_DATE, jour, k_DE, mois, k_NAISSANCE, an, k_MAIL, mail, k_ADRESSE, adresse, -1); 
		}
		fclose(f);
	gtk_tree_view_set_model (GTK_TREE_VIEW (liste),  GTK_TREE_MODEL (store));
    g_object_unref (store);
	}
}

/*-----------------------supprimer_kine----------------------------*/

void supprimer_kine(char cinn[20])
{
	char nom[30];
	char prenom[30];
	char cin[30];
	char jour[30];
	char mois[30];
	char an[30];
	char mail[30];
	char adresse[50];

	FILE *l;
	FILE *t;
	l=fopen("/home/nidhal/Projects/admin/src/kine.txt","r");
	t=fopen("/home/nidhal/Projects/admin/src/kine.tmp","a+");
	while (fscanf(l,"%s %s %s %s %s %s %s %s \n",nom,prenom,cin,jour,mois,an,mail,adresse)!=EOF)
	{
		if (strcmp(cinn,cin)!=0)
		{
			fprintf(t,"%s %s %s %s %s %s %s %s \n",nom,prenom,cin,jour,mois,an,mail,adresse);
		}
	}
	fclose(l);
	fclose(t);
	remove("/home/nidhal/Projects/admin/src/kine.txt");
	rename("/home/nidhal/Projects/admin/src/kine.tmp","/home/nidhal/Projects/admin/src/kine.txt");
}

