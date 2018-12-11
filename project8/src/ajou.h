#include <gtk/gtk.h>
typedef struct
{int num;
int  annee;
int mois;
int jour;
int de;
int a;
}dispo;
void afficherr(GtkWidget *liste );
int verife(int num);
void supprime(int num1);
void modife(int num1,int de1,int a1,int jour1,int mois1,int annee1);
