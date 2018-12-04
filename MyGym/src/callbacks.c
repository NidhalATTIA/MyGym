#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "admin.h"
#include <string.h>

	GtkWidget *authentification;
	GtkWidget *espaceAdmin;
	GtkWidget *gadherent;
	GtkWidget *formulaire_ajout;
	GtkWidget *afficher_adherent;

/*-------------------------------------------------------*/

void
on_connexion_clicked (GtkWidget  *widget, gpointer user_data)
{
	GtkWidget *login;
	GtkWidget *password;
	GtkWidget *role;
	GtkWidget *espaceAdmin;
	GtkWidget *espaceAdherent;
	espaceAdmin=create_espaceAdmin();
	espaceAdherent=create_espaceAdherent();
	int role2;
	char login3[30];char Password3[30];
	login=lookup_widget(widget,"login");
	password=lookup_widget(widget,"password");
	//role=lookup_widget(widget,"role");
	strcpy(login3,gtk_entry_get_text(GTK_ENTRY(login)));
	strcpy(Password3,gtk_entry_get_text(GTK_ENTRY(password)));
	role2 =verifier(login3,Password3);
	switch (role2)
		{case 1:gtk_widget_show(espaceAdmin);
			gtk_widget_hide;
			break;
		 case 2:gtk_widget_show(espaceAdherent);
                        break;}

gtk_widget_destroy(login);
espaceAdmin=create_espaceAdmin();
gtk_widget_show(espaceAdmin);

/*-------------------------------------------------------*/

void
on_ajouter_clicked     (GtkWidget       *objet,
                                        gpointer         user_data)
{

gtk_widget_destroy(gadherent);
formulaire_ajout=create_formulaire_ajout();
gtk_widget_show(formulaire_ajout);

In I;

GtkWidget *input1, *input2,*input3,*input4,*input5,*input6;
GtkWidget *fenetre_ajout;



formulaire_ajout=lookup_widget(objet,"formulaire_ajout");

input1=lookup_widget(objet,"cin");
input2=lookup_widget(objet,"nom");
input3=lookup_widget(objet,"prenom");
input4=lookup_widget(objet,"date");
input5=lookup_widget(objet,"adresse");
input6=lookup_widget(objet,"mail");


strcpy(I.cin,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(I.nom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(I.prenom,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(I.date,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(I.adresse,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy(I.mail,gtk_entry_get_text(GTK_ENTRY(input6)));

Inscrit(I);

}

/*-------------------------------------------------------*/

void
on_afficher_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{

GtkWidget *formulaire_ajout;
GtkWidget *fenetre_afficher;
GtkWidget *fenetre_ajout;
GtkWidget *treeview1;

formulaire_ajout=lookup_widget(objet,"formulaire_ajout");


gtk_widget_destroy(fenetre_ajout);
fenetre_afficher=lookup_widget(objet,"fenetre_afficher");
fenetre_afficher=create_fenetre_afficher();

gtk_widget_show(fenetre_afficher);
      

treeview1=lookup_widget(fenetre_afficher,"treeview1");

afficher_personne(treeview1); 

}


/*------------------------------------------------------------------------------*/


/*------------------------------------------------------------------------------*/


void
on_modifier_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
gtk_widget_destroy(authentification);
espaceAdmin=create_espaceAdmin();
gtk_widget_show(espaceAdmin);
}
/*------------------------------------------------------------------------------*/


void
on_supprimer_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
gtk_widget_destroy(authentification);
espaceAdmin=create_espaceAdmin();
gtk_widget_show(espaceAdmin);
}

}

/*------------------------------------------------------------------------------*/

void
on_gereradherent_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
gtk_widget_destroy(espaceAdmin);
gadherent=create_gadherent();
gtk_widget_show(gadherent);
}

/*------------------------------------------------------------------------------*/


void
on_gerercoach_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
gtk_widget_destroy(authentification);
espaceAdmin=create_espaceAdmin();
gtk_widget_show(espaceAdmin);
}

/*------------------------------------------------------------------------------*/

void
on_gerermed_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
gtk_widget_destroy(authentification);
espaceAdmin=create_espaceAdmin();
gtk_widget_show(espaceAdmin);
}

/*------------------------------------------------------------------------------*/

void
on_gererdiet_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
gtk_widget_destroy(authentification);
espaceAdmin=create_espaceAdmin();
gtk_widget_show(espaceAdmin);
}


/*------------------------------------------------------------------------------*/


void
on_gereraccueil_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
gtk_widget_destroy(authentification);
espaceAdmin=create_espaceAdmin();
gtk_widget_show(espaceAdmin);
}

/*------------------------------------------------------------------------------*/

void
on_quitterEA_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
gtk_widget_destroy(espaceAdmin);
authentification=create_authentification();
gtk_widget_show(authentification);
}

/*------------------------------------------------------------------------------*/

void
on_quitterlogin_leave                  (GtkButton       *button,
                                        gpointer         user_data)
{
gtk_widget_destroy(authentification);
}

/*------------------------------------------------------------------------------*/

void
on_authentification_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
gtk_widget_destroy(authentification);
espaceAdmin=create_espaceAdmin();
gtk_widget_show(espaceAdmin);
}

/*------------------------------------------------------------------------------*/

void
on_quittergestionadherent_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{
gtk_widget_destroy(gadherent);
espaceAdmin=create_espaceAdmin();
gtk_widget_show(espaceAdmin);
}

/*------------------------------------------------------------------------------*/

void
on_validerinscrit_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
gtk_widget_destroy(formulaire_ajout);
gadherent=create_gadherent();
gtk_widget_show(gadherent);
}

/*------------------------------------------------------------------------------*/

void
on_quitterinscrit_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
gtk_widget_destroy(formulaire_ajout);
gadherent=create_gadherent();
gtk_widget_show(gadherent);
}

/*------------------------------------------------------------------------------*/

void
on_afficher_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
gtk_widget_destroy(gadherent);
afficher_adherent=create_afficher_adherent();
gtk_widget_show(afficher_adherent);
}




