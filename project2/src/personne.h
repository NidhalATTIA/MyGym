#include <gtk/gtk.h>

typedef struct
{

char Nom[20];
char age[20];
char poids[30];
char probleme_med[30];
char taille[10]; 
char allergie[30];
char sang[30];
char traitement[30];
char note[30];
char num[30];
}fiche;

void ajouter_fiche(fiche p);
void afficher_fiche(GtkWidget *liste);
