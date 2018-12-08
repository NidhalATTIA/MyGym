#include <gtk/gtk.h>

int verifier (char login[], char Password[]);

/*-------------------structure_adherent---------------------*/

typedef struct
{

char a_nom[20];
char a_prenom[20];
char a_cin[20];
char a_jour[20];
char a_mois[20];
char a_an[20];
char a_mail[30];
char a_adresse[50];



}Adherent;

void ajouter_adherent(Adherent ad);

void afficher_adherent(GtkWidget *liste);

void supprimer_adherent(char cinn[20]);

void modifier_adherent(Adherent adm,char cinn[50]);

/*-------------------structure_coach---------------------*/

typedef struct
{

char c_nom[20];
char c_prenom[20];
char c_cin[20];
char c_jour[20];
char c_mois[20];
char c_an[20];
char c_mail[30];
char c_adresse[50];



}Coach;

void ajouter_coach(Coach co);

void afficher_coach(GtkWidget *liste);

void supprimer_coach(char cinn[20]);

/*-------------------structure_medecin---------------------*/

typedef struct
{

char m_nom[20];
char m_prenom[20];
char m_cin[20];
char m_jour[20];
char m_mois[20];
char m_an[20];
char m_mail[30];
char m_adresse[50];



}Medecin;

void ajouter_medecin(Medecin med);

void afficher_medecin(GtkWidget *liste);

void supprimer_medecin(char cinn[20]);

/*-------------------structure_dieteticien---------------------*/

typedef struct
{

char d_nom[20];
char d_prenom[20];
char d_cin[20];
char d_jour[20];
char d_mois[20];
char d_an[20];
char d_mail[30];
char d_adresse[50];



}Diet;

void ajouter_diet(Diet diet);

void afficher_diet(GtkWidget *liste);

void supprimer_diet(char cinn[20]);

/*-------------------structure_kine---------------------*/

typedef struct
{

char k_nom[20];
char k_prenom[20];
char k_cin[20];
char k_jour[20];
char k_mois[20];
char k_an[20];
char k_mail[30];
char k_adresse[50];



}Kine;

void ajouter_kine(Kine kine);

void afficher_kine(GtkWidget *liste);

void supprimer_kine(char cinn[20]);



