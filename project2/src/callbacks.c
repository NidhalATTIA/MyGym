#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif
#include <gtk/gtk.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "verifier.h"
#include "personne.h"
#include "ajout.h"
#include "supprimer.h"
#include "modifier.h"
#include "ok.h"
#include "suppdispo.h"
#include <string.h>
#include "coordonner.h"

void
on_button1_clicked (GtkWidget *widget , gpointer user_data)
{
int V ;
GtkWidget *login ;
GtkWidget *password1 ;
GtkWidget *role1 ;
GtkWidget *admin ;
GtkWidget *medecin;



admin=create_admin();
medecin=create_medecin();
char username[20];
char password[20];
int role ;
login=lookup_widget(widget ,"entry1");
password1=lookup_widget(widget ,"entry2");
//role=lookup_widget(widget,"role")

strcpy(username,gtk_entry_get_text(GTK_ENTRY(login)));
strcpy(password,gtk_entry_get_text(GTK_ENTRY(password1)));
V = verif (username , password );
if (V==1){
gtk_widget_show(admin);
gtk_widget_hide(GTK_WIDGET(lookup_widget(widget,"window1")));}
if (V==2){
gtk_widget_show(medecin);
gtk_widget_hide(GTK_WIDGET(lookup_widget(widget,"window1")));
} 
}
void
on_button2_clicked (GtkWidget *widget  , gpointer   user_data)
{GtkWidget *desponibilite;
desponibilite=create_desponibilite();
gtk_widget_show(desponibilite);
gtk_widget_hide(GTK_WIDGET(lookup_widget(widget,"medecin")));
}




void
on_button3_clicked (GtkWidget *widget  , gpointer   user_data)
{GtkWidget *fiche_medicale;
fiche_medicale=create_fiche_medicale();
gtk_widget_show(fiche_medicale);
gtk_widget_hide(GTK_WIDGET(lookup_widget(widget,"medecin")));

}


void
on_sceance_clicked (GtkWidget *widget  , gpointer   user_data)
{GtkWidget *sceance;
sceance=create_sceance();
gtk_widget_show(sceance);

}


void
on_button5_clicked  (GtkWidget   *widget, gpointer   user_data)
{
}

void
on_button11_clicked  (GtkWidget       *objet_graphique, gpointer         user_data)
{
GtkWidget *input1, *input2,*input3,*input4,*input5,*input6,*input7,*input8,*input9,*input10;






fiche p;

GtkWidget *Ajouter_fiche;


input1=lookup_widget(objet_graphique,"Nom");
strcpy(p.Nom,gtk_entry_get_text(GTK_ENTRY(input1)));
input2=lookup_widget(objet_graphique,"age");
strcpy(p.age,gtk_entry_get_text(GTK_ENTRY(input2)));
input3=lookup_widget(objet_graphique,"poids");
strcpy(p.poids,gtk_entry_get_text(GTK_ENTRY(input3)));
input4=lookup_widget(objet_graphique,"probleme_med");
strcpy(p.probleme_med,gtk_entry_get_text(GTK_ENTRY(input4)));
input5=lookup_widget(objet_graphique,"taille");
strcpy(p.taille,gtk_entry_get_text(GTK_ENTRY(input5)));
input6=lookup_widget(objet_graphique,"allergie");
strcpy(p.allergie,gtk_entry_get_text(GTK_ENTRY(input6)));
input7=lookup_widget(objet_graphique,"sang");
strcpy(p.sang,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input7)));
input8=lookup_widget(objet_graphique,"traitement");
strcpy(p.traitement,gtk_entry_get_text(GTK_ENTRY(input8)));
input9=lookup_widget(objet_graphique,"note");
strcpy(p.note,gtk_entry_get_text(GTK_ENTRY(input9)));
input10=lookup_widget(objet_graphique,"num");
strcpy(p.num,gtk_entry_get_text(GTK_ENTRY(input10)));

ajouter_fiche(p);

Ajouter_fiche=create_Ajouter_fiche();
gtk_widget_show(Ajouter_fiche);
gtk_widget_hide(GTK_WIDGET(lookup_widget(objet_graphique,"Ajouter_fiche")));


}



void on_button8_clicked (GtkWidget       *button, gpointer         user_data)
{
GtkWidget *Ajouter_fiche;
Ajouter_fiche=create_Ajouter_fiche();
gtk_widget_show(Ajouter_fiche);
gtk_widget_hide(GTK_WIDGET(lookup_widget(button,"fiche_medicale")));
}



void
on_button12_clicked  (GtkWidget       *button, gpointer         user_data)
{
GtkWidget *fiche_medicale;
fiche_medicale=create_fiche_medicale();
gtk_widget_show(fiche_medicale);
gtk_widget_hide(GTK_WIDGET(lookup_widget(button,"Ajouter_fiche")));
}

void on_affichager_clicked (GtkWidget *widget  , gpointer   user_data)
{
GtkWidget *affichage;
GtkWidget *Ajouter_fiche;
GtkWidget *treeview1;
GtkWidget *affichager;

Ajouter_fiche=lookup_widget(widget,"Ajouter_fiche");
affichager=lookup_widget(widget,"affichager");


gtk_widget_destroy(Ajouter_fiche);
affichage=create_affichage();
gtk_widget_show(affichage);

gtk_widget_hide(GTK_WIDGET(lookup_widget(widget,"fiche_medicale")));
      

treeview1=lookup_widget(affichage,"treeview1");

afficher_fiche(treeview1); 



}






void on_Retour_clicked  (GtkWidget       *widget,
                                        gpointer         user_data)
{


GtkWidget *fiche_medicale, *affichage;

affichage=lookup_widget(widget,"affichage");


gtk_widget_destroy(affichage);
fiche_medicale=create_fiche_medicale();
gtk_widget_show(fiche_medicale);


}




void
on_button4_clicked  (GtkWidget  *objet_graphique  , gpointer   user_data)
{date d;

GtkWidget *jour;
GtkWidget *mois;
GtkWidget *annee;
GtkWidget *heure;
GtkWidget *Num;
GtkWidget *desponibilite;

jour=lookup_widget(objet_graphique,"jour");
mois=lookup_widget(objet_graphique,"mois");
annee=lookup_widget(objet_graphique,"annee");
heure=lookup_widget(objet_graphique,"heure");
Num=lookup_widget(objet_graphique,"Num");
     
 
d.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (jour));
d.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (mois));
d.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (annee));
d.heure=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (heure));
d.Num=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (Num));
ajoute (d);


desponibilite=create_desponibilite ();
gtk_widget_show(desponibilite);
gtk_widget_hide(GTK_WIDGET(lookup_widget(objet_graphique,"desponibilite")));

}



void
on_voir_clicked    (GtkWidget  *widget, gpointer   user_data)
{
GtkWidget *rdv;
GtkWidget *treeview2;
GtkWidget *desponibilite;
GtkWidget *voir;


voir=lookup_widget(widget,"voir");
desponibilite=lookup_widget(widget,"desponibilite");


rdv=create_rdv();
gtk_widget_show(rdv);



treeview2=lookup_widget(rdv,"treeview2");
afficher(treeview2);
gtk_widget_hide(GTK_WIDGET(lookup_widget(widget,"desponibilite")));



}


void
on_supprima_clicked    (GtkWidget  *widget, gpointer   user_data)
{
GtkWidget *effacer;
effacer=create_effacer();
gtk_widget_show(effacer);


}


void
on_button13_clicked  (GtkButton       *widget, gpointer         user_data)
{
        char num[30];
	GtkWidget *input1;
        GtkWidget *effacer;
        GtkWidget *numi;
	effacer=lookup_widget(widget,"effacer");
	input1=lookup_widget(widget,"numi");
	strcpy(num,gtk_entry_get_text(GTK_ENTRY(input1)));
	sup_speci(num);

}
void
on_button14_clicked (GtkButton      *widget, gpointer         user_data)

{
GtkWidget *supprime_desp;
supprime_desp=create_supprime_desp();
gtk_widget_show(supprime_desp);
}




void
on_modifi_clicked  (GtkButton       *widget, gpointer         user_data)

{
GtkWidget *modifier;
modifier=create_modifier();
gtk_widget_show(modifier);
}


void
on_modifier_fiche_clicked(GtkButton       *objet_graphique,  gpointer         user_data)
{
GtkWidget *modifier;
GtkWidget *input1, *input2,*input3,*input4,*input5,*input6,*input7,*input8,*input9,*input10;
fiche p;

input1=lookup_widget(objet_graphique,"Nom2");
strcpy(p.Nom,gtk_entry_get_text(GTK_ENTRY(input1)));
input2=lookup_widget(objet_graphique,"age2");
strcpy(p.age,gtk_entry_get_text(GTK_ENTRY(input2)));
input3=lookup_widget(objet_graphique,"poids2");
strcpy(p.poids,gtk_entry_get_text(GTK_ENTRY(input3)));
input4=lookup_widget(objet_graphique,"probleme_med2");
strcpy(p.probleme_med,gtk_entry_get_text(GTK_ENTRY(input4)));
input5=lookup_widget(objet_graphique,"taille2");
strcpy(p.taille,gtk_entry_get_text(GTK_ENTRY(input5)));
input6=lookup_widget(objet_graphique,"allergie2");
strcpy(p.allergie,gtk_entry_get_text(GTK_ENTRY(input6)));
input7=lookup_widget(objet_graphique,"sang2");
strcpy(p.sang,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input7)));
input8=lookup_widget(objet_graphique,"traitement2");
strcpy(p.traitement,gtk_entry_get_text(GTK_ENTRY(input8)));
input9=lookup_widget(objet_graphique,"note2");
strcpy(p.note,gtk_entry_get_text(GTK_ENTRY(input9)));
input10=lookup_widget(objet_graphique,"num2");
strcpy(p.num,gtk_entry_get_text(GTK_ENTRY(input10)));

modifi(p.Nom,p.age,p.poids,p.probleme_med,p.taille,p.allergie,p.sang,p.traitement,p.note,p.num);

}


void
on_deconnection_clicked  (GtkButton       *widget, gpointer         user_data)
{
GtkWidget *window1;
window1=create_window1();
gtk_widget_show(window1);
gtk_widget_hide(GTK_WIDGET(lookup_widget(widget,"medecin")));

}


void
on_coordonnees_medecin_clicked    (GtkButton       *widget,gpointer         user_data)
{
GtkWidget *coordonner;
coordonner=create_coordonner();
gtk_widget_show(coordonner);
gtk_widget_hide(GTK_WIDGET(lookup_widget(widget,"medecin")));

}


void on_modif_coor_activate  (GtkButton       *widget, gpointer         user_data)
{
GtkWidget *modifier_coor;
modifier_coor=create_modifier_coor();
gtk_widget_show(modifier_coor);
gtk_widget_hide(GTK_WIDGET(lookup_widget(widget,"coordonner")));

}


void on_re_clicked (GtkButton       *widget, gpointer         user_data)
{
GtkWidget *medecin;
medecin=create_medecin();
gtk_widget_show(medecin);
gtk_widget_hide(GTK_WIDGET(lookup_widget(widget,"coordonner")));

}


void
on_modif_re_clicked (GtkButton       *objet_graphique ,  gpointer         user_data)
{


GtkWidget *input,*input1,*input2,*input3,*input4,*input5;
GtkWidget *output,*output1,*output2,*output3,*output4,*output5;
char nom[30];char nom1[30] ;char age[30];char age1[30];char domaine[30];char domaine1[30];char tel[30];char tel1[30];char exp[30];char exp1[30];char forma[30];char forma1[30];

input=lookup_widget(objet_graphique,"entry1");
output=lookup_widget(objet_graphique,"Nom");
strcpy(nom,gtk_entry_get_text(GTK_ENTRY(input)));

input1=lookup_widget(objet_graphique,"entry2");
output1=lookup_widget(objet_graphique,"Age");
strcpy(age,gtk_entry_get_text(GTK_ENTRY(input1)));

input2=lookup_widget(objet_graphique,"entry3");
output2=lookup_widget(objet_graphique,"Domaine");
strcpy(domaine,gtk_entry_get_text(GTK_ENTRY(input2)));

input3=lookup_widget(objet_graphique,"entry4");
output3=lookup_widget(objet_graphique,"Tel");
strcpy(tel,gtk_entry_get_text(GTK_ENTRY(input3)));

input4=lookup_widget(objet_graphique,"entry5");
output4=lookup_widget(objet_graphique,"Experience");
strcpy(exp,gtk_entry_get_text(GTK_ENTRY(input4)));

input5=lookup_widget(objet_graphique,"entry6");
output5=lookup_widget(objet_graphique,"Formation");
strcpy(forma,gtk_entry_get_text(GTK_ENTRY(input5)));


void coor(nom,nom1,age,age1,domaine,domaine1,tel,tel1,exp,exp1,forma,forma1);
gtk_label_set_text(GTK_LABEL(output),nom);
gtk_label_set_text(GTK_LABEL(output1),age);
gtk_label_set_text(GTK_LABEL(output2),domaine);
gtk_label_set_text(GTK_LABEL(output3),tel);
gtk_label_set_text(GTK_LABEL(output4),exp);
gtk_label_set_text(GTK_LABEL(output5),forma);


}


void
on_ok_clicked (GtkButton       *objet_graphique ,  gpointer         user_data)
{
GtkWidget *input1, *input2,*input3,*input4,*input5,*input6,*input7,*input8,*input9,*input10;


med m;

GtkWidget *Ajouter_fiche;


input1=lookup_widget(objet_graphique,"entry1");
strcpy(m.nom_med,gtk_entry_get_text(GTK_ENTRY(input1)));
input2=lookup_widget(objet_graphique,"entry2");
strcpy(m.age_med,gtk_entry_get_text(GTK_ENTRY(input2)));
input3=lookup_widget(objet_graphique,"entry3");
strcpy(m.domaine_med,gtk_entry_get_text(GTK_ENTRY(input3)));
input4=lookup_widget(objet_graphique,"entry4");
strcpy(m.tel_med,gtk_entry_get_text(GTK_ENTRY(input4)));
input5=lookup_widget(objet_graphique,"entry5");
strcpy(m.exp_med,gtk_entry_get_text(GTK_ENTRY(input5)));
input6=lookup_widget(objet_graphique,"entry6");
strcpy(m.forma_med,gtk_entry_get_text(GTK_ENTRY(input6)));


cmed (m);

GtkWidget *coordonner;
coordonner=create_coordonner();
gtk_widget_show(coordonner);
gtk_widget_hide(GTK_WIDGET(lookup_widget(objet_graphique,"modifier_coor")));


}


void
on_affii_clicked  (GtkButton       *objet,  gpointer         user_data)
{
med m;
GtkWidget *output1m, *output2m,*output3m,*output4m,*output5m,*output6m;


output1m=lookup_widget(objet,"entrynom");
output2m=lookup_widget(objet,"entryage");
output3m=lookup_widget(objet,"entrydomaine");
output4m=lookup_widget(objet,"entrytel");
output5m=lookup_widget(objet,"entryexperience");
output6m=lookup_widget(objet,"entryformation");
int x=1;
FILE *f;
f=fopen("/home/yasser/saisir/ok.txt","r");
if (f!=NULL)

{

while (fscanf(f,"%s %s %s %s %s %s \n",m.nom_med,m.age_med,m.domaine_med,m.tel_med,m.exp_med,m.forma_med)!=EOF)
{
if (x==1)
{
gtk_entry_set_text (GTK_ENTRY (output1m), m.nom_med);
gtk_entry_set_text (GTK_ENTRY (output2m), m.age_med);
gtk_entry_set_text (GTK_ENTRY (output3m), m.domaine_med);
gtk_entry_set_text (GTK_ENTRY (output4m), m.tel_med);
gtk_entry_set_text (GTK_ENTRY (output5m), m.exp_med);
gtk_entry_set_text (GTK_ENTRY (output6m), m.forma_med);

}
}
}
fclose(f);}





void
on_supprimer_dispo_clicked (GtkButton       *widget, gpointer         user_data)
{
char Num[30];
GtkWidget *input1;
GtkWidget *supprime_despo;
supprime_despo=lookup_widget(widget,"supprime_despo");
input1=lookup_widget(widget,"entry7");
strcpy(Num,gtk_entry_get_text(GTK_ENTRY(input1)));
sup_dispo(Num);


}


void
on_retour_despo_clicked (GtkButton       *widget, gpointer         user_data)
{
GtkWidget *desponibilite;
desponibilite=create_desponibilite();
gtk_widget_show(desponibilite);
gtk_widget_hide(GTK_WIDGET(lookup_widget(widget,"rdv")));

}



void
on_rou_clicked  (GtkButton       *widget,  gpointer         user_data)
{
GtkWidget *medecin;
medecin=create_medecin();
gtk_widget_show(medecin);
gtk_widget_hide(GTK_WIDGET(lookup_widget(widget,"fiche_medicale")));

}


void
on_retou_clicked (GtkButton       *widget,     gpointer         user_data)
{GtkWidget *medecin;
medecin=create_medecin();
gtk_widget_show(medecin);
gtk_widget_hide(GTK_WIDGET(lookup_widget(widget,"desponibilite")));

}

