#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "coordonner.h"
#include <gtk/gtk.h>

void coor(char nom[],char nom1[] ,char age[],char age1[],char domaine[],char domaine1[],char tel[],char tel1[],char exp[],char exp1[],char forma[],char forma1[]){
  strcpy(nom1,"Nom&prenom");
  strcat(nom1,nom);
  
 
  strcpy(age1,"age");
  strcat(age1,age);
 
  strcpy(domaine1,"Domaine");
  strcat(domaine1,domaine);

  strcpy(tel1,"N°telephone");
  strcat(tel1,tel);
 
  strcpy(exp1,"Experience");
  strcat(exp1,exp);
  
  strcpy(forma,"Formation");
  strcat(forma1,forma);
}
