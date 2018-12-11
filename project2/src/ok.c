#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ok.h"
#include <gtk/gtk.h>

void cmed (med m)
{
FILE *f;
f=fopen("/home/yasser/saisir/ok.txt","a+");
fprintf(f,"%s %s %s %s %s %s\n",m.nom_med,m.age_med,m.domaine_med,m.tel_med,m.exp_med,m.forma_med);	
fclose(f);
}
