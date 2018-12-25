#include "verifier.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <gtk/gtk.h>

enum{
	PRENOM,
	NOM,
	HEURE,
	DATE,
	TYPE,
	COLUMNS1
};
enum{
	CINc,
	PRENOMc,
	NOMc,
	SPECIALITEc,
	TELc,
	EMAILc,
	COLUMNS2

};
enum{
	CINk,
	PRENOMk,
	NOMk,
	SPECIALITEk,
	TELk,
	EMAILk,
	COLUMNS4

};
enum{
	TYPE3,
	DATE3,
	HEURE3,
	COLUMNS3
};
enum{
	CINa,
	PRENOMa,
	NOMa,
	TELa,
	EMAILa,
	COLUMNS5

};
enum{
	CINad,
	PRENOMad,
	NOMad,
	TELad,
	EMAILad,
	COLUMNS6

};

/* ----- fonction verifier --------*/
personne verifier (char login[], char password[])
{FILE*f;
personne p;
int role12=0;
char login1[30],password1[30];

f=fopen("personne.txt","r");
if(f!=NULL) { 
while (fscanf(f,"%s %s %s %s %s %s %s %s\n",p.pcin,p.pprenom,p.pnom,p.prole,p.ppseudo,p.ppassword,p.pdatenaissance,p.pdateinscrit)!=EOF) 
{	
	if((strcmp(p.ppseudo,login)==0 )&& (strcmp(p.ppassword,password)==0) )
	{return p;}else {strcpy(p.prole,"invalide");}
	}}

return p;
fclose(f);
}

/*      ---------fonction admin -----------     */
void ajouter_personne(personne p){
FILE*f;
FILE*x;
FILE*a;
FILE*d;
FILE*m;
FILE*k;
FILE*e;
FILE*c;
f=fopen("personne.txt","a+"); 
a=fopen("admin.txt","a+");
d=fopen("adherent.txt","a+");
m=fopen("medcin.txt","a+");
k=fopen("kine.txt","a+");
e=fopen("diet.txt","a+");
c=fopen("coach.txt","a+");
x=fopen("fichemedicals.txt","a+");

if(f!=NULL) { 

fprintf(f,"%s %s %s %s %s %s %s %s\n",p.pcin,p.pprenom,p.pnom,p.prole,p.ppseudo,p.ppassword,p.pdatenaissance,p.pdateinscrit);
}
fclose(f);
if ((a!=NULL) && (strcmp(p.prole,"Administrateur")==0)){
fprintf(a,"%s %s %s %s %s %s %s %s %s %s\n",p.pcin,p.pprenom,p.pnom,p.prole,p.ppseudo,p.ppassword,p.pdatenaissance,p.pdateinscrit,"pas_encore_saisie","pas_encore_saisie");
}
fclose(a);
if ((d!=NULL) && (strcmp(p.prole,"Adhérent")==0)&& (x!=NULL)){
fprintf(d,"%s %s %s %s %s %s %s %s %s %s %s %s\n",p.pcin,p.pprenom,p.pnom,p.prole,p.ppseudo,p.ppassword,p.pdatenaissance,p.pdateinscrit,"pas_encore_saisie","pas_encore_saisie","pas_encore_saisie","pas_encore_saisie");
fprintf(x,"%s %s %s %s %s %s %s %s %s %s\n",p.pcin,p.pprenom,p.pnom,p.prole,p.pdatenaissance,p.pdateinscrit,"pas_encore_saisie","pas_encore_saisie","pas_encore_saisie","pas_encore_saisie");}
fclose(d);
fclose(x);

if ((c!=NULL) && (strcmp(p.prole,"Coach")==0)){
fprintf(c,"%s %s %s %s %s %s %s %s %s %s %s\n",p.pcin,p.pprenom,p.pnom,p.prole,p.ppseudo,p.ppassword,p.pdatenaissance,p.pdateinscrit,"pas_encore_saisie","pas_encore_saisie","pas_encore_saisie");
}
fclose(c);
if ((e!=NULL) && (strcmp(p.prole,"Diététicien")==0)){
fprintf(e,"%s %s %s %s %s %s %s %s %s %s %s\n",p.pcin,p.pprenom,p.pnom,p.prole,p.ppseudo,p.ppassword,p.pdatenaissance,p.pdateinscrit,"pas_encore_saisie","pas_encore_saisie","pas_encore_saisie");
}
fclose(e);
if ((k!=NULL) && (strcmp(p.prole,"Kinésithérapeute")==0)){
fprintf(k,"%s %s %s %s %s %s %s %s %s %s %s\n",p.pcin,p.pprenom,p.pnom,p.prole,p.ppseudo,p.ppassword,p.pdatenaissance,p.pdateinscrit,"pas_encore_saisie","pas_encore_saisie","pas_encore_saisie");
}
fclose(k);
fclose(x);
if ((m!=NULL) && (strcmp(p.prole,"Médecin")==0)){
fprintf(m,"%s %s %s %s %s %s %s %s %s %s %s\n",p.pcin,p.pprenom,p.pnom,p.prole,p.ppseudo,p.ppassword,p.pdatenaissance,p.pdateinscrit,"pas_encore_saisie","pas_encore_saisie","pas_encore_saisie");
}
fclose(m);

}



Admin chargeradmin(char cin[]){
Admin a;
FILE*f;
f=fopen("admin.txt","r");

if (f!=NULL){
while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s\n",a.acin,a.aprenom,a.anom,a.arole,a.apseudo,a.apassword,a.adatenaissance,a.adateinscrit,a.atel,a.aemail)!=EOF){
if(strcmp(cin,a.acin)==0){return a;}
}}
fclose(f);
}

void supprimercoach(char cin[]){

FILE*l;
FILE*t;
FILE*f;
FILE*d;
Coach b;
personne p;
f=fopen("personne.txt","r");
d=fopen("coach.txt","r");
l=fopen("tamp2.txt","a+");
t=fopen("tamp.txt","a+");
while (fscanf(f,"%s %s %s %s %s %s %s %s\n",p.pcin,p.pprenom,p.pnom,p.prole,p.ppseudo,p.ppassword,p.pdatenaissance,p.pdateinscrit)!=EOF)//na9raw mil fichier temporaire
{
fscanf(d,"%s %s %s %s %s %s %s %s %s %s %s\n",b.ccin,b.cprenom,b.cnom,b.crole,b.cpseudo,b.cpassword,b.cdatenaissance,b.cdateinscrit,b.cspecialite,b.cnumerotel,b.cemail);
if ((strcmp(p.pcin,cin)!=0))//ken la valeur ili na9raw fiha differente mil parametre ya3ni ncopiw i ligne fel fichier e jdid
{
fprintf(t,"%s %s %s %s %s %s %s %s %s %s %s\n",b.ccin,b.cprenom,b.cnom,b.crole,b.cpseudo,b.cpassword,b.cdatenaissance,b.cdateinscrit,b.cspecialite,b.cnumerotel,b.cemail);
//copie de la ligne fel fichier jdid
fprintf(l,"%s %s %s %s %s %s %s %s\n",p.pcin,p.pprenom,p.pnom,p.prole,p.ppseudo,p.ppassword,p.pdatenaissance,p.pdateinscrit);
}else{g_print("trouver");}
}
fclose(f);
fclose(d);
fclose(l);
fclose(t);
remove("coach.txt");//nfas5ou il fichier li9dim
rename("tamp.txt","coach.txt");
remove("personne.txt");
rename("tamp2.txt","personne.txt");
}
void profileadmin(Admin a){

FILE*d;
FILE*t;
Admin b;
d=fopen("admin.txt","r");
t=fopen("temp.txt","a+");
if(d!=NULL){
while(fscanf(d,"%s %s %s %s %s %s %s %s %s %s\n",b.acin,b.aprenom,b.anom,b.arole,b.apseudo,b.apassword,b.adatenaissance,b.adateinscrit,b.atel,b.aemail)!=EOF)
{
if (strcmp(b.acin,a.acin)!=0){
fprintf(t,"%s %s %s %s %s %s %s %s %s %s\n",b.acin,b.aprenom,b.anom,b.arole,b.apseudo,b.apassword,b.adatenaissance,b.adateinscrit,b.atel,b.aemail);
}else{fprintf(t,"%s %s %s %s %s %s %s %s %s %s\n",a.acin,a.aprenom,a.anom,a.arole,a.apseudo,a.apassword,a.adatenaissance,a.adateinscrit,a.atel,a.aemail);}
}

}
fclose(d);
fclose(t);
remove("admin.txt"); 
rename("temp.txt","admin.txt");
}
void supprimeradherent(char cin[]){


FILE*t;
FILE*f;
Adherent b;
f=fopen("adherent.txt","r");
t=fopen("tamp.txt","a+");
while (fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s\n",b.pcin,b.pprenom,b.pnom,b.prole,b.ppseudo,b.ppassword,b.pdatenaissance,b.pdateinscrit,b.taille,b.poids,b.numerotelad,b.email)!=EOF)//na9raw mil fichier temporaire
{

if ((strcmp(b.pcin,cin)!=0))//ken la valeur ili na9raw fiha differente mil parametre ya3ni ncopiw i ligne fel fichier e jdid
{
fprintf(t,"%s %s %s %s %s %s %s %s %s %s %s %s\n",b.pcin,b.pprenom,b.pnom,b.prole,b.ppseudo,b.ppassword,b.pdatenaissance,b.pdateinscrit,b.taille,b.poids,b.numerotelad,b.email);
//copie de la ligne fel fichier jdid
}else{g_print("trouver");}
}
fclose(f);
fclose(t);
remove("adherent.txt");//nfas5ou il fichier li9dim
rename("tamp.txt","adherent.txt");
}

/*   --------- fonction adherent -------------- */

Adherent chargeradherent(char cin[]){
Adherent b;
FILE*f;
f=fopen("adherent.txt","r");

if (f!=NULL){
while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s\n",b.pcin,b.pprenom,b.pnom,b.prole,b.ppseudo,b.ppassword,b.pdatenaissance,b.pdateinscrit,b.taille,b.poids,b.numerotelad,b.email)!=EOF){
if(strcmp(cin,b.pcin)==0){return b;}
}}
fclose(f);
}


void profile(Adherent a){

FILE*d;
FILE*t;
Adherent b;
d=fopen("adherent.txt","r");
t=fopen("temp.txt","a+");
if(d!=NULL){
while(fscanf(d,"%s %s %s %s %s %s %s %s %s %s %s %s\n",b.pcin,b.pprenom,b.pnom,b.prole,b.ppseudo,b.ppassword,b.pdatenaissance,b.pdateinscrit,b.taille,b.poids,b.numerotelad,b.email)!=EOF)
{
if (strcmp(b.pcin,a.pcin)!=0){
fprintf(t,"%s %s %s %s %s %s %s %s %s %s %s %s\n",b.pcin,b.pprenom,b.pnom,b.prole,b.ppseudo,b.ppassword,b.pdatenaissance,b.pdateinscrit,b.taille,b.poids,b.numerotelad,b.email);
}else{fprintf(t,"%s %s %s %s %s %s %s %s %s %s %s %s\n",a.pcin,a.pprenom,a.pnom,a.prole,a.ppseudo,a.ppassword,a.pdatenaissance,a.pdateinscrit,a.taille,a.poids,a.numerotelad,a.email);}
}

}
fclose(d);
fclose(t);
remove("adherent.txt"); 
rename("temp.txt","adherent.txt");
}

void sinscrireaucour(Adherent a,gchar *cin,gchar *date,gchar *type,gchar *heure){
FILE*f;
FILE*d;
char filename[30];
char filename2[30];
strcpy(filename,cin);
strcpy(filename2,a.pcin);
strcat(filename,heure);
strcat(filename2,".txt");
strcat(filename,".txt");
g_print("%s",cin);
f=fopen(filename,"a+");
d=fopen(filename2,"a+");
if (f!=NULL) {
fprintf(f,"%s %s %s\n",a.pcin,a.pprenom,a.pnom);
fprintf(d,"%s %s %s\n",type,date,heure);
}
fclose(f);
fclose(d);
}


void affichercoachsad(GtkWidget *liste){
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
Coach b;
store=NULL;
FILE*f;
store=gtk_tree_view_get_model(liste);

if(store == NULL){
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Cin",renderer,"text",CINc,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("prenom",renderer,"text",PRENOMc,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Nom",renderer,"text",NOMc,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Specialité",renderer,"text",SPECIALITEc,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Numero tel",renderer,"text",TELc,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Email",renderer,"text",EMAILc,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

store = gtk_list_store_new(COLUMNS2, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
f=fopen("coach.txt","r");
if (f!=NULL){
while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s\n",b.ccin,b.cprenom,b.cnom,b.crole,b.cpseudo,b.cpassword,b.cdatenaissance,b.cdateinscrit,b.cspecialite,b.cnumerotel,b.cemail)!=EOF){

gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,CINc,b.ccin,PRENOMc,b.cprenom,NOMc,b.cnom,SPECIALITEc,b.cspecialite,TELc,b.cnumerotel,EMAILc,b.cemail,-1);
}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
g_object_unref(store);
}

}

}
void afficherkinesad(GtkWidget *liste){
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
Kine b;
store=NULL;
FILE*f;
store=gtk_tree_view_get_model(liste);

if(store == NULL){
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Cin",renderer,"text",CINk,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("prenom",renderer,"text",PRENOMk,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Nom",renderer,"text",NOMk,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Specialité",renderer,"text",SPECIALITEk,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Numero tel",renderer,"text",TELk,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Email",renderer,"text",EMAILk,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

store = gtk_list_store_new(COLUMNS4, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
f=fopen("kine.txt","r");
if (f!=NULL){
while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s\n",b.dcin,b.dprenom,b.dnom,b.drole,b.dpseudo,b.dpassword,b.ddatenaissance,b.ddateinscrit,b.specialite,b.dtel,b.demail)!=EOF){

gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,CINk,b.dcin,PRENOMk,b.dprenom,NOMk,b.dnom,SPECIALITEk,b.specialite,TELk,b.dtel,EMAILk,b.demail,-1);
}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
g_object_unref(store);
}

}

}
void affichercourspouradgherent(GtkWidget *liste,char cin[30]){
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
cours b;
store=NULL;
FILE*f;
char filename[300];
strcpy(filename,cin);
strcat(filename,".txt");
store=gtk_tree_view_get_model(liste);

if(store == NULL){
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Prenom",renderer,"text",PRENOM,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Nom",renderer,"text",NOM,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Heure",renderer,"text",HEURE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Date",renderer,"text",DATE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Type",renderer,"text",TYPE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

store = gtk_list_store_new(COLUMNS1, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
f= fopen(filename,"r");
if (f!=NULL){
while(fscanf(f,"%s %s %s %s %s %s\n",b.cincoach,b.prenomcoach,b.nomcoach,b.horaire,b.date,b.type)!=EOF){

gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,PRENOM,b.prenomcoach,NOM,b.nomcoach,HEURE,b.horaire,DATE,b.date,TYPE,b.type,-1);
}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
g_object_unref(store);
}

}

}
void affichercoursdeadherent(GtkWidget *liste,char cin[30]){
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
char type[20],heure[20],date[20];

store=NULL;
FILE*f;
char filename[300];
strcpy(filename,cin);
strcat(filename,".txt");
store=gtk_tree_view_get_model(liste);

if(store == NULL){
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Type",renderer,"text",TYPE3,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Date",renderer,"text",DATE3,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Heure",renderer,"text",HEURE3,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

store = gtk_list_store_new(COLUMNS3, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
f= fopen(filename,"r");
if (f!=NULL){
while(fscanf(f,"%s %s %s\n",type,date,heure)!=EOF){

gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,TYPE3,type,DATE3,date,HEURE3,heure,-1);
}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
g_object_unref(store);
}

}


}
void supprimercours(char cin[30],gchar *type,gchar *date,gchar *heure){
char a1[20];
char b1[20];
char c1[20];
FILE *l;
FILE *t;
char filename[30];
strcpy(filename,cin);
strcat(filename,".txt");
l=fopen(filename,"r");
t=fopen("tamp.txt","a+");
while (fscanf(l,"%s %s %s\n",a1,b1,c1)!=EOF)//na9raw mil fichier temporaire
{
if ((strcmp(type,a1)!=0) || (strcmp(date,b1)!=0) || (strcmp(heure,c1)!=0))//ken la valeur ili na9raw fiha differente mil parametre ya3ni ncopiw i ligne fel fichier e jdid
{
fprintf(t,"%s %s %s\n",a1,b1,c1);//copie de la ligne fel fichier jdid
}
}
fclose(l);
fclose(t);
remove(filename);//nfas5ou il fichier li9dim
rename("tamp.txt",filename);

}
/* ------- fonction Coach ----------*/

Coach chargercoach(char cin[]){
Coach b;
FILE*f;
f=fopen("coach.txt","r");

if (f!=NULL){
while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s\n",b.ccin,b.cprenom,b.cnom,b.crole,b.cpseudo,b.cpassword,b.cdatenaissance,b.cdateinscrit,b.cspecialite,b.cnumerotel,b.cemail)!=EOF){
if(strcmp(cin,b.ccin)==0){return b;}
}}
fclose(f);
}

void profileCoach(Coach a){

FILE*d;
FILE*t;
Coach b;
d=fopen("coach.txt","r");
t=fopen("temp.txt","a+");
if(d!=NULL){
while(fscanf(d,"%s %s %s %s %s %s %s %s %s %s %s\n",b.ccin,b.cprenom,b.cnom,b.crole,b.cpseudo,b.cpassword,b.cdatenaissance,b.cdateinscrit,b.cspecialite,b.cnumerotel,b.cemail)!=EOF)
{
if (strcmp(b.ccin,a.ccin)!=0){
fprintf(t,"%s %s %s %s %s %s %s %s %s %s %s\n",b.ccin,b.cprenom,b.cnom,b.crole,b.cpseudo,b.cpassword,b.cdatenaissance,b.cdateinscrit,b.cspecialite,b.cnumerotel,b.cemail);
}else{fprintf(t,"%s %s %s %s %s %s %s %s %s %s %s\n",a.ccin,a.cprenom,a.cnom,a.crole,a.cpseudo,a.cpassword,a.cdatenaissance,a.cdateinscrit,a.cspecialite,a.cnumerotel,a.cemail);}
}

}
fclose(d);
fclose(t);
remove("coach.txt"); 
rename("temp.txt","coach.txt");
}

void ajoutercour(Coach c,cours cour){
FILE*f;
char nomfichier[30];
strcpy(nomfichier,c.ccin);
strcat(nomfichier,".txt");
f=fopen(nomfichier,"a+");
if(f!=NULL){
fprintf(f,"%s %s %s %s %s %s\n",cour.cincoach,cour.prenomcoach,cour.nomcoach,cour.horaire,cour.date,cour.type);
}
fclose(f);
}
void affichercours(GtkWidget *liste,Coach c){
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
cours b;
store=NULL;
FILE*f;
strcat(c.ccin,".txt");
store=gtk_tree_view_get_model(liste);

if(store == NULL){
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Prenom",renderer,"text",PRENOM,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Nom",renderer,"text",NOM,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Heure",renderer,"text",HEURE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Date",renderer,"text",DATE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Type",renderer,"text",TYPE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

store = gtk_list_store_new(COLUMNS1, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
f= fopen(c.ccin,"r");
if (f!=NULL){
while(fscanf(f,"%s %s %s %s %s %s\n",b.cincoach,b.prenomcoach,b.nomcoach,b.horaire,b.date,b.type)!=EOF){

gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,PRENOM,b.prenomcoach,NOM,b.nomcoach,HEURE,b.horaire,DATE,b.date,TYPE,b.type,-1);
}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
g_object_unref(store);
}

}

}
/* ------ fonction medecin -----------*/


Medecin chargermedecin(char cin[]){
Medecin b;
FILE*f;
f=fopen("medcin.txt","r");

if (f!=NULL){
while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s\n",b.mcin,b.mprenom,b.mnom,b.mrole,b.mpseudo,b.mpassword,b.mdatenaissance,b.mdateinscrit,b.specialite,b.mtel,b.memail)!=EOF){
if(strcmp(cin,b.mcin)==0){return b;}
}}
fclose(f);
}

void profilemedecin(Medecin a){

FILE*d;
FILE*t;
Medecin b;
d=fopen("medcin.txt","r");
t=fopen("temp.txt","a+");
if(d!=NULL){
while(fscanf(d,"%s %s %s %s %s %s %s %s %s %s %s\n",b.mcin,b.mprenom,b.mnom,b.mrole,b.mpseudo,b.mpassword,b.mdatenaissance,b.mdateinscrit,b.specialite,b.mtel,b.memail)!=EOF)
{
if (strcmp(b.mcin,a.mcin)!=0){
fprintf(t,"%s %s %s %s %s %s %s %s %s %s %s\n",b.mcin,b.mprenom,b.mnom,b.mrole,b.mpseudo,b.mpassword,b.mdatenaissance,b.mdateinscrit,b.specialite,b.mtel,b.memail);
}else{fprintf(t,"%s %s %s %s %s %s %s %s %s %s %s\n",a.mcin,a.mprenom,a.mnom,a.mrole,a.mpseudo,a.mpassword,a.mdatenaissance,a.mdateinscrit,a.specialite,a.mtel,a.memail);}
}

}
fclose(d);
fclose(t);
remove("medcin.txt"); 
rename("temp.txt","medcin.txt");
}
/*-----  fonction kiné  ---------*/

Kine chargerkine(char cin[]){
Kine b;
FILE*f;
f=fopen("kine.txt","r");

if (f!=NULL){
while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s\n",b.dcin,b.dprenom,b.dnom,b.drole,b.dpseudo,b.dpassword,b.ddatenaissance,b.ddateinscrit,b.specialite,b.dtel,b.demail)!=EOF){
if(strcmp(cin,b.dcin)==0){return b;}
}}
fclose(f);
}

void profileKine(Kine a){

FILE*d;
FILE*t;
Kine b;
d=fopen("kine.txt","r");
t=fopen("temp.txt","a+");
if(d!=NULL){
while(fscanf(d,"%s %s %s %s %s %s %s %s %s %s %s\n",b.dcin,b.dprenom,b.dnom,b.drole,b.dpseudo,b.dpassword,b.ddatenaissance,b.ddateinscrit,b.specialite,b.dtel,b.demail)!=EOF)
{
if (strcmp(b.dcin,a.dcin)!=0){
fprintf(t,"%s %s %s %s %s %s %s %s %s %s %s\n",b.dcin,b.dprenom,b.dnom,b.drole,b.dpseudo,b.dpassword,b.ddatenaissance,b.ddateinscrit,b.specialite,b.dtel,b.demail);
}else{fprintf(t,"%s %s %s %s %s %s %s %s %s %s %s\n",a.dcin,a.dprenom,a.dnom,a.drole,a.dpseudo,a.dpassword,a.ddatenaissance,a.ddateinscrit,a.specialite,a.dtel,a.demail);}
}

}
fclose(d);
fclose(t);
remove("kine.txt"); 
rename("temp.txt","kine.txt");
}
void afficherdispopouradgherent(GtkWidget *liste,char cin[30]){
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
cours b;
store=NULL;
FILE*f;
char filename[300];
strcpy(filename,cin);
strcat(filename,".txt");
store=gtk_tree_view_get_model(liste);

if(store == NULL){
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Prenom",renderer,"text",PRENOM,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Nom",renderer,"text",NOM,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Heure",renderer,"text",HEURE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Date",renderer,"text",DATE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Type",renderer,"text",TYPE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

store = gtk_list_store_new(COLUMNS1, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
f= fopen(filename,"r");
if (f!=NULL){
while(fscanf(f,"%s %s %s %s %s %s\n",b.cincoach,b.prenomcoach,b.nomcoach,b.horaire,b.date,b.type)!=EOF){

gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,PRENOM,b.prenomcoach,NOM,b.nomcoach,HEURE,b.horaire,DATE,b.date,TYPE,b.type,-1);
}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
g_object_unref(store);
}

}

}

void sinscrireaurdv(Adherent a,gchar *cin,gchar *date,gchar *type,gchar *heure){
FILE*f;
FILE*d;
char filename[30];
char filename2[30];
strcpy(filename,cin);
strcpy(filename2,a.pcin);
strcat(filename,heure);
strcat(filename2,".txt");
strcat(filename,".txt");
g_print("%s",cin);
f=fopen(filename,"a+");
d=fopen(filename2,"a+");
if (f!=NULL) {
fprintf(f,"%s %s %s\n",a.pcin,a.pprenom,a.pnom);
fprintf(d,"%s %s %s\n",type,date,heure);
}
fclose(f);
fclose(d);
}

void afficheradherent(GtkWidget *liste){
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
Adherent b;
store=NULL;
FILE*f;
store=gtk_tree_view_get_model(liste);

if(store == NULL){
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Cin",renderer,"text",CINa,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("prenom",renderer,"text",PRENOMa,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Nom",renderer,"text",NOMa,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Numero tel",renderer,"text",TELa,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Email",renderer,"text",EMAILa,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

store = gtk_list_store_new(COLUMNS5, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
f=fopen("adherent.txt","r");
if (f!=NULL){
while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s\n",b.pcin,b.pprenom,b.pnom,b.prole,b.ppseudo,b.ppassword,b.pdatenaissance,b.pdateinscrit,b.poids,b.taille,b.numerotelad,b.email)!=EOF){

gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,CINa,b.pcin,PRENOMa,b.pprenom,NOMa,b.pnom,TELa,b.numerotelad,EMAILa,b.email,-1);
}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
g_object_unref(store);
}
}
}
void afficherevenement(GtkWidget *liste){

}
void afficherboutique(GtkWidget *liste){

}

void afficheradmin(GtkWidget *liste){
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
Admin b;
store=NULL;
FILE*f;
store=gtk_tree_view_get_model(liste);

if(store == NULL){
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Cin",renderer,"text",CINad,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("prenom",renderer,"text",PRENOMad,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Nom",renderer,"text",NOMad,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Numero tel",renderer,"text",TELad,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Email",renderer,"text",EMAILad,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

store = gtk_list_store_new(COLUMNS5, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
f=fopen("admin.txt","r");
if (f!=NULL){
while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s\n",b.acin,b.aprenom,b.anom,b.arole,b.apseudo,b.apassword,b.adatenaissance,b.adateinscrit,b.atel,b.aemail)!=EOF){

gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,CINad,b.acin,PRENOMad,b.aprenom,NOMad,b.anom,TELad,b.atel,EMAILad,b.aemail,-1);
}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
g_object_unref(store);
}
}
}

