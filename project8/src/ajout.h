#include <gtk/gtk.h>
typedef struct
{int num;
int  annee;
int mois;
int jour;
int heure;
}date;
void ajoute(date d);
void afficher(GtkWidget *liste);
void supprim(int num1);
int verif(int num);
void modif(int num1,int heure1,int jour1,int mois1,int annee1);
