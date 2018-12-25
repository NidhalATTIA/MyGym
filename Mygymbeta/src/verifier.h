#ifndef VERIFIER_H
#define VERIFIER_H
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <gtk/gtk.h>




/*  --------------   structures admin --------------*/
typedef struct 
{
char pnom[20];
char pprenom[20];
char pcin[20];
char prole[30];
char ppseudo[20];
char ppassword[20];
char pdatenaissance[20];
char pdateinscrit[20];
}personne;
personne verifier(char login[], char password[]);
void ajouter_personne(personne p);

typedef struct 
{
char anom[20];
char aprenom[20];
char acin[20];
char arole[30];
char apseudo[20];
char apassword[20];
char adatenaissance[20];
char adateinscrit[20];
char atel[20];
char aemail[20];
}Admin;

typedef struct {
char nom[30];
char date [30];
char heure [30];
char type [30];

}Evenement;
void ajouterEvenement (Evenement e);
void afficherEvenement (GtkWidget *liste);
void modifierEvenement (Evenement e);
void supprimerEvenement (Evenement e);
typedef struct {
char nom[30];
char prix[30];
char stock[30];
}Item;
void ajouterItem (Item i);
void afficherItem (GtkWidget *liste);
void modifierItem (Item i);
void supprimerItem (Item i);

void profileadmin(Admin a);

Admin chargeradmin(char cin[]);
void afficher_admin(GtkWidget *liste);
void supprimercoach(gchar *cin);


/* --------        structure adherents         ---------------*/

typedef struct{

char pnom[20];
char pprenom[20];
char pcin[20];
char prole[30];
char ppseudo[20];
char ppassword[20];
char pdatenaissance[20];
char pdateinscrit[20];
char poids[30];
char taille[30];
char numerotelad[30];
char email[30];

}Adherent;

void profile(Adherent a);
void afficher_adherent(GtkWidget *liste);
Adherent chargeradherent(char cin[]);
void affichercoachsad(GtkWidget *liste);
typedef struct
{

char nommedcien[20];
char c_horaire[20];
char date[30];
char c_type[30];

}RDV;

void ajouter_RDV (RDV r);
void afficher_RDV (GtkWidget *liste);
void modifier_RDV (RDV r);
void supprimer_RDV (RDV r);
void affichercourspouradgherent(GtkWidget *liste,char cin[30]);
void sinscrireaurdv(Adherent a,gchar *cin,gchar *date,gchar *type,gchar *heure);
void supprimercours(char cin[30],gchar *type,gchar *date,gchar *heure);
void affichercoursdeadherent(GtkWidget *liste,char cin[30]);
void afficherkinesad(GtkWidget *liste);
/*     ------------- structure Coach ----------*/

typedef struct{

char cnom[20];
char cprenom[20];
char ccin[20];
char crole[30];
char cpseudo[20];
char cpassword[20];
char cdatenaissance[20];
char cdateinscrit[20];
char cspecialite[50];
char cnumerotel[50];
char cemail[50];
}Coach;

void profilecoach(Coach a);

Coach chargercoach(char cin[]);
void afficher_coach(GtkWidget *liste);
void affichercours(GtkWidget *liste, Coach c);
typedef struct
{
char cincoach[20];
char nomcoach[20];
char prenomcoach[20];
char horaire[20];
char date[30];
char type[30];

}cours;

void ajoutercour (Coach c,cours cour);
void afficher_cours (GtkWidget *liste);

/* ---------------- structure medecin  --------------*/

typedef struct
{

char mnom[20];
char mprenom[20];
char mcin[20];
char mrole[30];
char mpseudo[20];
char mpassword[20];
char mdatenaissance[20];
char mdateinscrit[20];
char specialite[20];
char mtel[20];
char memail[20];

}Medecin;

void profilemedecin(Medecin m);
void afficher_Medecin(GtkWidget *liste);
Medecin chargermedecin(char cin[]);


typedef struct
{
char cinmedecin[30];
char nommedcien[20];
char prenommedcin[20];
char horaire[20];
char date[30];

}dispomedecin;

typedef struct{
	char cin[30];
	char nom[30];
	char prenom[30];
	char Datenaiissance [30];
	char poids[30];
        char taille[30];
	char probleme_med[30];
        char allergie[30];
        char sang[30];
        char traitement[50];
}fichmedical;

void ajouter_dispomed (dispomedecin d);
void afficher_dispomed (GtkWidget *liste);

/* ---------- structure diet ------------*/
typedef struct
{

char dnom[20];
char dprenom[20];
char dcin[20];
char drole[30];
char dpseudo[20];
char dpassword[20];
char ddatenaissance[20];
char ddateinscrit[20];
char specialite[20];
char dtel[20];
char demail[20];
}Kine;



void profileKine(Kine k);
void afficher_Kine(GtkWidget *liste);
Kine chargerkine(char cin[]);


typedef struct
{
char cinkine[20];
char dnomdiet[20];
char dprenomdeiet[20];
char dhoraire[20];
char date[30];

}dispoKine;

void ajouter_dispodiet(dispoKine d);
void afficher_dispodiet (GtkWidget *liste);
void afficherdispopouradgherent(GtkWidget *liste,char cin[30]);
void afficheradherent(GtkWidget *liste);
void afficherevenement(GtkWidget *liste);
void afficherboutique(GtkWidget *liste);
void afficheradmin(GtkWidget *liste);
#endif /* VERIFIER_H__*/

