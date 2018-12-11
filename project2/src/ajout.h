#include <gtk/gtk.h>
typedef struct
{
int heure;
int jour;
int mois;
int annee;
int Num;
}date;
void ajoute(date d);
void afficher(GtkWidget *liste);
