#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif
#include <gtk/gtk.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "admin.h"

/*---------------------authentification---------------------------*/

void
on_connexion_clicked                   (GtkWidget       *obj,
                                        gpointer         user_data)
{
	GtkWidget *login, *password;
	GtkWidget *output;
	GtkWidget *espaceAdmin;
	GtkWidget *authentification;
	espaceAdmin=create_espaceAdmin();

	int x;
	char login3[30];char Password3[30];

	login=lookup_widget(obj ,"login");
	password=lookup_widget(obj ,"mdp");
	output=lookup_widget(obj ,"erreurmdp");

	//role=lookup_widget(widget,"role");
	strcpy(login3,gtk_entry_get_text(GTK_ENTRY(login)));
	strcpy(Password3,gtk_entry_get_text(GTK_ENTRY(password)));
	x = verifier(login3,Password3);
	if (x==-1)
	{
	gtk_label_set_text(GTK_LABEL(output),"Erreur d'authentification");
	}
	else
	{
	gtk_widget_hide(GTK_WIDGET(lookup_widget(obj,"authentification")));
	gtk_widget_show(espaceAdmin);
	}

}


void
on_quitterapp_clicked                  (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *authentification;
gtk_widget_destroy(authentification);
}


/*--------------------------espaceAdmin-----------------------------*/

void
on_alogout_clicked                     (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *espaceAdmin, *authentification;

espaceAdmin=lookup_widget(obj,"espaceAdmin");

gtk_widget_destroy(espaceAdmin);
authentification=create_authentification();
gtk_widget_show(authentification);
}


void
on_gadherent_clicked                   (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *espaceAdmin, *fgadherent;

espaceAdmin=lookup_widget(obj,"espaceAdmin");

gtk_widget_destroy(espaceAdmin);
fgadherent=create_fgadherent();
gtk_widget_show(fgadherent);
}

void
on_gcoach_clicked                      (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *espaceAdmin, *fgcoach;

espaceAdmin=lookup_widget(obj,"espaceAdmin");

gtk_widget_destroy(espaceAdmin);
fgcoach=create_fgcoach();
gtk_widget_show(fgcoach);
}

void
on_gmedecin_clicked                    (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *espaceAdmin, *fgmed;

espaceAdmin=lookup_widget(obj,"espaceAdmin");

gtk_widget_destroy(espaceAdmin);
fgmed=create_fgmed();
gtk_widget_show(fgmed);
}

void
on_gdiet_clicked                       (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *espaceAdmin, *fgdiet;

espaceAdmin=lookup_widget(obj,"espaceAdmin");

gtk_widget_destroy(espaceAdmin);
fgdiet=create_fgdiet();
gtk_widget_show(fgdiet);
}

void
on_gkine_clicked                       (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *espaceAdmin, *fgkine;

espaceAdmin=lookup_widget(obj,"espaceAdmin");

gtk_widget_destroy(espaceAdmin);
fgkine=create_fgkine();
gtk_widget_show(fgkine);
}


/*-----------------------------fgadherent---------------------------*/

void
on_ajouter_adherent_clicked            (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *fgadherent, *fajouter_adherent;

fgadherent=lookup_widget(obj,"fgadherent");

gtk_widget_destroy(fgadherent);
fajouter_adherent=create_fajouter_adherent();
gtk_widget_show(fajouter_adherent);
}

//fonction afficher_adherent

void
on_afficher_adherent_clicked           (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *fgadherent, *fafficher_adherent, *treeadherent;

fgadherent=lookup_widget(obj,"fgadherent");

gtk_widget_destroy(fgadherent);
fafficher_adherent=lookup_widget(obj,"fafficher_adherent");
fafficher_adherent=create_fafficher_adherent();
gtk_widget_show(fafficher_adherent);
treeadherent=lookup_widget(fafficher_adherent,"treeadherent");

afficher_adherent(treeadherent);
}

void
on_qgadherent_clicked                  (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *fgadherent, *espaceAdmin;

fgadherent=lookup_widget(obj,"fgadherent");

gtk_widget_destroy(fgadherent);
espaceAdmin=create_espaceAdmin();
gtk_widget_show(espaceAdmin);
}

/*-----------------------------fajouter_adherent--------------------*/


//Fonctioner ajouter_adherent

void
on_vajouter_adherent_clicked           (GtkWidget       *obj,
                                        gpointer         user_data)
{
Adherent ad;

GtkWidget *input1, *input2,*input3,*input4,*input5,*input6,*input7,*input8;
GtkWidget *fajouter_adherent;

fajouter_adherent=lookup_widget(obj,"fajouter_adherent");

input1=lookup_widget(obj,"a_nom");
input2=lookup_widget(obj,"a_prenom");
input3=lookup_widget(obj,"a_cin");
input4=lookup_widget(obj,"a_jour");
input5=lookup_widget(obj,"a_mois");
input6=lookup_widget(obj,"a_an");
input7=lookup_widget(obj,"a_mail");
input8=lookup_widget(obj,"a_adresse");

strcpy(ad.a_nom,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(ad.a_prenom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(ad.a_cin,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(ad.a_jour,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(ad.a_mois,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy(ad.a_an,gtk_entry_get_text(GTK_ENTRY(input6)));
strcpy(ad.a_mail,gtk_entry_get_text(GTK_ENTRY(input7)));
strcpy(ad.a_adresse,gtk_entry_get_text(GTK_ENTRY(input8)));

ajouter_adherent(ad);

GtkWidget *fgadherent;

fajouter_adherent=lookup_widget(obj,"fajouter_adherent");

gtk_widget_destroy(fajouter_adherent);
fgadherent=create_fgadherent();
gtk_widget_show(fgadherent);

}


void
on_qajouter_adherent_clicked           (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *fajouter_adherent, *fgadherent;

fajouter_adherent=lookup_widget(obj,"fajouter_adherent");

gtk_widget_destroy(fajouter_adherent);
fgadherent=create_fgadherent();
gtk_widget_show(fgadherent);
}

/*-----------------------------fafficher_adherent--------------------*/

void
on_modifier_adherent_clicked           (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *fafficher_adherent, *fchercher_adherent;

fafficher_adherent=lookup_widget(obj,"fafficher_adherent");

gtk_widget_hide(fafficher_adherent);
fchercher_adherent=create_fchercher_adherent();
gtk_widget_show(fchercher_adherent);
}


void
on_supprimer_adherent_clicked          (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *fafficher_adherent, *fsupprimer_adherent;

fafficher_adherent=lookup_widget(obj,"fafficher_adherent");

gtk_widget_hide(fafficher_adherent);
fsupprimer_adherent=create_fsupprimer_adherent();
gtk_widget_show(fsupprimer_adherent);
}


void
on_qafficher_adherent_clicked          (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *fafficher_adherent, *fgadherent;

fafficher_adherent=lookup_widget(obj,"fafficher_adherent");

gtk_widget_destroy(fafficher_adherent);
fgadherent=create_fgadherent();
gtk_widget_show(fgadherent);
}

/*--------------------------fchercher_adherent-----------------------*/

void
on_vchercher_adherent_clicked          (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *fmodifier_adherent, *fchercher_adherent;
GtkWidget *input1,*output1 , *output2 , *output3,*output4,*output5,*output6, *output7, *output8;
Adherent ad;
char cinn[30];

input1=lookup_widget(obj,"a_chercher");
output1=lookup_widget(obj,"am_nom");
output2=lookup_widget(obj,"am_prenom");
output3=lookup_widget(obj,"am_cin");
output4=lookup_widget(obj,"am_jour");
output5=lookup_widget(obj,"am_mois");
output6=lookup_widget(obj,"am_an");
output7=lookup_widget(obj,"am_mail");
output8=lookup_widget(obj,"am_adresse");

strcpy (cinn,gtk_entry_get_text(GTK_ENTRY(input1)));
FILE *f;
  f=fopen("/home/nidhal/Projects/admin/src/adherent.txt","r"); 
   if (f!=NULL)
   {
    while (fscanf(f,"%s %s %s %s %s %s %s %s \n",ad.a_nom,ad.a_prenom,ad.a_cin,ad.a_jour,ad.a_mois,ad.a_an,ad.a_mail,ad.a_adresse)!=EOF)
    {
   if ((strcmp(ad.a_cin,cinn))==0)
   {   
     fchercher_adherent=lookup_widget(obj,"fchercher_adherent");
	gtk_widget_destroy(fchercher_adherent);
	fmodifier_adherent=create_fmodifier_adherent();
	gtk_widget_show(fmodifier_adherent);

	fprintf(f,"%s %s %s %s %s %s %s %s \n",ad.a_nom,ad.a_prenom,ad.a_cin,ad.a_jour,ad.a_mois,ad.a_an,ad.a_mail,ad.a_adresse)!=EOF;

	strcpy(ad.a_nom,gtk_entry_get_text(GTK_ENTRY(output1)));
	strcpy(ad.a_prenom,gtk_entry_get_text(GTK_ENTRY(output2)));
	strcpy(ad.a_cin,gtk_entry_get_text(GTK_ENTRY(output3)));
	strcpy(ad.a_jour,gtk_entry_get_text(GTK_ENTRY(output4)));
	strcpy(ad.a_mois,gtk_entry_get_text(GTK_ENTRY(output5)));
	strcpy(ad.a_an,gtk_entry_get_text(GTK_ENTRY(output6)));
	strcpy(ad.a_mail,gtk_entry_get_text(GTK_ENTRY(output7)));
	strcpy(ad.a_adresse,gtk_entry_get_text(GTK_ENTRY(output8)));

   }       
   }
   }
     fclose(f);    
}


void
on_qchercher_adherent_clicked          (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *fchercher_adherent, *fgadherent;

fchercher_adherent=lookup_widget(obj,"fchercher_adherent");

gtk_widget_destroy(fchercher_adherent);
fgadherent=create_fgadherent();
gtk_widget_show(fgadherent);
}

/*--------------------------fmodifier_adherent-----------------------*/

void
on_vmodifier_adherent_clicked          (GtkWidget       *obj,
                                        gpointer         user_data)

{/*
Adherent ad;

GtkWidget *input1, *input2,*input3,*input4,*input5,*input6,*input7,*input8;
GtkWidget *fajouter_adherent;

fajouter_adherent=lookup_widget(obj,"fajouter_adherent");

input1=lookup_widget(obj,"am_nom");
input2=lookup_widget(obj,"am_prenom");
input3=lookup_widget(obj,"am_cin");
input4=lookup_widget(obj,"am_jour");
input5=lookup_widget(obj,"am_mois");
input6=lookup_widget(obj,"am_an");
input7=lookup_widget(obj,"am_mail");
input8=lookup_widget(obj,"am_adresse");

strcpy(adm.a_nom,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(adm.a_prenom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(adm.a_cin,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(adm.a_jour,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(adm.a_mois,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy(adm.a_an,gtk_entry_get_text(GTK_ENTRY(input6)));
strcpy(adm.a_mail,gtk_entry_get_text(GTK_ENTRY(input7)));
strcpy(adm.a_adresse,gtk_entry_get_text(GTK_ENTRY(input8)));

modifier_adherent(adm);

GtkWidget *fmodifier_adherent, *fgadherent;
fmodifier_adherent=lookup_widget(obj,"fmodifier_adherent");

gtk_widget_destroy(fmodifier_adherent);
fgadherent=create_fgadherent();
gtk_widget_show(fgadherent);*/
}



void
on_qmodifier_adherent_clicked          (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *fmodifier_adherent, *fgadherent;

fmodifier_adherent=lookup_widget(obj,"fmodifier_adherent");

gtk_widget_destroy(fmodifier_adherent);
fgadherent=create_fgadherent();
gtk_widget_show(fgadherent); 
}

/*--------------------------fsupprimer_adherent-----------------------*/

void
on_vsupprimer_adherent_clicked         (GtkWidget       *obj,
                                        gpointer         user_data)
{
Adherent ad;
char cinn[20];
GtkWidget *fsupprimer_adherent, *fgadherent;
GtkWidget *input1;

fsupprimer_adherent=lookup_widget(obj,"fsupprimer_adherent");

input1=lookup_widget(obj,"s_adherent");
strcpy(cinn,gtk_entry_get_text(GTK_ENTRY(input1)));

supprimer_adherent(cinn);

gtk_widget_destroy(fsupprimer_adherent);
fgadherent=create_fgadherent();
gtk_widget_show(fgadherent);


}


void
on_qsupprimer_adherent_clicked         (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *fsupprimer_adherent, *fgadherent;

fsupprimer_adherent=lookup_widget(obj,"fsupprimer_adherent");

gtk_widget_destroy(fsupprimer_adherent);
fgadherent=create_fgadherent();
gtk_widget_show(fgadherent);
}

/*-------------------------------fgcoach------------------------------*/

void
on_ajouter_coach_clicked               (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *fgcoach, *fajouter_coach;

fgcoach=lookup_widget(obj,"fgcoach");

gtk_widget_destroy(fgcoach);
fajouter_coach=create_fajouter_coach();
gtk_widget_show(fajouter_coach);
}


void
on_afficher_coach_clicked              (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *fgcoach, *fafficher_coach, *treecoach;

fgcoach=lookup_widget(obj,"fgcoach");

gtk_widget_destroy(fgcoach);
fafficher_coach=lookup_widget(obj,"fafficher_coach");
fafficher_coach=create_fafficher_coach();
gtk_widget_show(fafficher_coach);
treecoach=lookup_widget(fafficher_coach,"treecoach");

afficher_coach(treecoach);
}


void
on_qgcoach_clicked                     (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *fgcoach, *espaceAdmin;

fgcoach=lookup_widget(obj,"fgcoach");

gtk_widget_destroy(fgcoach);
espaceAdmin=create_espaceAdmin();
gtk_widget_show(espaceAdmin);
}

/*-----------------------------fajouter_coach---------------------------*/


void
on_vajouter_coach_clicked              (GtkWidget       *obj,
                                        gpointer         user_data)
{
Coach co;

GtkWidget *input1, *input2,*input3,*input4,*input5,*input6,*input7,*input8;
GtkWidget *fajouter_coach;

fajouter_coach=lookup_widget(obj,"fajouter_coach");

input1=lookup_widget(obj,"c_nom");
input2=lookup_widget(obj,"c_prenom");
input3=lookup_widget(obj,"c_cin");
input4=lookup_widget(obj,"c_jour");
input5=lookup_widget(obj,"c_mois");
input6=lookup_widget(obj,"c_an");
input7=lookup_widget(obj,"c_mail");
input8=lookup_widget(obj,"c_adresse");

strcpy(co.c_nom,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(co.c_prenom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(co.c_cin,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(co.c_jour,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(co.c_mois,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy(co.c_an,gtk_entry_get_text(GTK_ENTRY(input6)));
strcpy(co.c_mail,gtk_entry_get_text(GTK_ENTRY(input7)));
strcpy(co.c_adresse,gtk_entry_get_text(GTK_ENTRY(input8)));

ajouter_coach(co);

GtkWidget *fgcoach;

fajouter_coach=lookup_widget(obj,"fajouter_coach");

gtk_widget_destroy(fajouter_coach);
fgcoach=create_fgcoach();
gtk_widget_show(fgcoach);
}


void
on_qajouter_coach_clicked              (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *fajouter_coach, *fgcoach;

fajouter_coach=lookup_widget(obj,"fajouter_coach");

gtk_widget_destroy(fajouter_coach);
fgcoach=create_fgcoach();
gtk_widget_show(fgcoach);
}

/*-----------------------------fgafficher_coach-------------------------*/


void
on_modifier_coach_clicked              (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *fafficher_coach, *fchercher_coach;

fafficher_coach=lookup_widget(obj,"fafficher_coach");

gtk_widget_destroy(fafficher_coach);
fchercher_coach=create_fchercher_coach();
gtk_widget_show(fchercher_coach);
}


void
on_supprimer_coach_clicked             (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *fafficher_coach, *fsupprimer_coach;

fafficher_coach=lookup_widget(obj,"fafficher_coach");

gtk_widget_hide(fafficher_coach);
fsupprimer_coach=create_fsupprimer_coach();
gtk_widget_show(fsupprimer_coach);
}


void
on_qafficher_coach_clicked             (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *fafficher_coach, *fgcoach;

fafficher_coach=lookup_widget(obj,"fafficher_coach");

gtk_widget_destroy(fafficher_coach);
fgcoach=create_fgcoach();
gtk_widget_show(fgcoach);
}

/*-----------------------------fchercher_coach---------------------------*/

void
on_vchercher_coach_clicked             (GtkWidget       *obj,
                                        gpointer         user_data)
{

}


void
on_qchercher_coach_clicked             (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *fchercher_coach, *fgcoach;

fchercher_coach=lookup_widget(obj,"fchercher_coach");

gtk_widget_destroy(fchercher_coach);
fgcoach=create_fgcoach();
gtk_widget_show(fgcoach);
}

/*-----------------------------fmodifier_coach---------------------------*/

void
on_vmodifier_coach_clicked             (GtkWidget       *obj,
                                        gpointer         user_data)
{

}


void
on_qmodifier_coach_clicked             (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *fmodifier_coach, *fgcoach;

fmodifier_coach=lookup_widget(obj,"fmodifier_coach");

gtk_widget_destroy(fmodifier_coach);
fgcoach=create_fgcoach();
gtk_widget_show(fgcoach);
}

/*--------------------------fsupprimer_coach-----------------------*/

void
on_vsupprimer_coach_clicked            (GtkWidget       *obj,
                                        gpointer         user_data)
{
Coach co;
char cinn[20];
GtkWidget *fsupprimer_coach, *fgcoach;
GtkWidget *input1;

fsupprimer_coach=lookup_widget(obj,"fsupprimer_coach");

input1=lookup_widget(obj,"s_coach");
strcpy(cinn,gtk_entry_get_text(GTK_ENTRY(input1)));

supprimer_coach(cinn);

gtk_widget_destroy(fsupprimer_coach);
fgcoach=create_fgcoach();
gtk_widget_show(fgcoach);


}


void
on_qsupprimer_coach_clicked            (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *fsupprimer_coach, *fgcoach;

fsupprimer_coach=lookup_widget(obj,"fsupprimer_coach");

gtk_widget_destroy(fsupprimer_coach);
fgcoach=create_fgcoach();
gtk_widget_show(fgcoach);
}

/*--------------------------------fgmed-------------------------------*/


void
on_ajouter_med_clicked                 (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *fgmed, *fajouter_med;

fgmed=lookup_widget(obj,"fgmed");

gtk_widget_destroy(fgmed);
fajouter_med=create_fajouter_med();
gtk_widget_show(fajouter_med);
}


void
on_afficher_med_clicked                (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *fgmed, *fafficher_med, *treemed;

fgmed=lookup_widget(obj,"fgmed");

gtk_widget_destroy(fgmed);
fafficher_med=lookup_widget(obj,"fafficher_med");
fafficher_med=create_fafficher_med();
gtk_widget_show(fafficher_med);
treemed=lookup_widget(fafficher_med,"treemed");

afficher_medecin(treemed);
}


void
on_qgmed_clicked                       (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *fgmed, *espaceAdmin;

fgmed=lookup_widget(obj,"fgmed");

gtk_widget_destroy(fgmed);
espaceAdmin=create_espaceAdmin();
gtk_widget_show(espaceAdmin);
}

/*-------------------------fajouter_med-------------------------------*/

void
on_vajouter_med_clicked                (GtkWidget       *obj,
                                        gpointer         user_data)
{
Medecin med;

GtkWidget *input1, *input2,*input3,*input4,*input5,*input6,*input7,*input8;
GtkWidget *fajouter_med;

fajouter_med=lookup_widget(obj,"fajouter_med");

input1=lookup_widget(obj,"m_nom");
input2=lookup_widget(obj,"m_prenom");
input3=lookup_widget(obj,"m_cin");
input4=lookup_widget(obj,"m_jour");
input5=lookup_widget(obj,"m_mois");
input6=lookup_widget(obj,"m_an");
input7=lookup_widget(obj,"m_mail");
input8=lookup_widget(obj,"m_adresse");

strcpy(med.m_nom,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(med.m_prenom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(med.m_cin,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(med.m_jour,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(med.m_mois,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy(med.m_an,gtk_entry_get_text(GTK_ENTRY(input6)));
strcpy(med.m_mail,gtk_entry_get_text(GTK_ENTRY(input7)));
strcpy(med.m_adresse,gtk_entry_get_text(GTK_ENTRY(input8)));

ajouter_medecin(med);

GtkWidget *fgmed;

fajouter_med=lookup_widget(obj,"fajouter_med");

gtk_widget_destroy(fajouter_med);
fgmed=create_fgmed();
gtk_widget_show(fgmed);
}


void
on_qajouter_med_clicked                (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *fajouter_med, *fgmed;

fajouter_med=lookup_widget(obj,"fajouter_med");

gtk_widget_destroy(fajouter_med);
fgmed=create_fgmed();
gtk_widget_show(fgmed);
}

/*----------------------------fafficher_med--------------------------*/

void
on_qafficher_med_clicked               (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *fafficher_med, *fgmed;

fafficher_med=lookup_widget(obj,"fafficher_med");

gtk_widget_destroy(fafficher_med);
fgmed=create_fgmed();
gtk_widget_show(fgmed);
}


void
on_supprimer_med_clicked               (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *fafficher_med, *fsupprimer_med;

fafficher_med=lookup_widget(obj,"fafficher_med");

gtk_widget_hide(fafficher_med);
fsupprimer_med=create_fsupprimer_med();
gtk_widget_show(fsupprimer_med);
}


void
on_modifier_med_clicked                (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *fafficher_med, *fchercher_med;

fafficher_med=lookup_widget(obj,"fafficher_med");

gtk_widget_destroy(fafficher_med);
fchercher_med=create_fchercher_med();
gtk_widget_show(fchercher_med);
}

/*---------------------------fchercher_med---------------------------*/

void
on_vchercher_med_clicked               (GtkWidget       *obj,
                                        gpointer         user_data)
{

}


void
on_qchercher_med_clicked               (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *fchercher_med, *fgmed;

fchercher_med=lookup_widget(obj,"fchercher_med");

gtk_widget_destroy(fchercher_med);
fgmed=create_fgmed();
gtk_widget_show(fgmed);
}

/*---------------------------fmodifier_med----------------------------*/


void
on_qmodifier_med_clicked               (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *fmodifier_med, *fgmed;

fmodifier_med=lookup_widget(obj,"fmodifier_med");

gtk_widget_destroy(fmodifier_med);
fgmed=create_fgmed();
gtk_widget_show(fgmed);
}


void
on_vmodifier_med_clicked               (GtkWidget       *obj,
                                        gpointer         user_data)
{

}

/*-----------------------------fsupprimer_med--------------------------*/

void
on_vsupprimer_med_clicked              (GtkWidget       *obj,
                                        gpointer         user_data)
{
Medecin med;
char cinn[20];
GtkWidget *fsupprimer_med, *fgmed;
GtkWidget *input1;

fsupprimer_med=lookup_widget(obj,"fsupprimer_med");

input1=lookup_widget(obj,"s_med");
strcpy(cinn,gtk_entry_get_text(GTK_ENTRY(input1)));

supprimer_medecin(cinn);

gtk_widget_destroy(fsupprimer_med);
fgmed=create_fgmed();
gtk_widget_show(fgmed);


}


void
on_qsupprimer_med_clicked              (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *fsupprimer_med, *fgmed;

fsupprimer_med=lookup_widget(obj,"fsupprimer_med");

gtk_widget_destroy(fsupprimer_med);
fgmed=create_fgmed();
gtk_widget_show(fgmed);
}

/*-----------------------------fgdiet--------------------------------*/



void
on_ajouter_diet_clicked                (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *fgdiet, *fajouter_diet;

fgdiet=lookup_widget(obj,"fgdiet");

gtk_widget_destroy(fgdiet);
fajouter_diet=create_fajouter_diet();
gtk_widget_show(fajouter_diet);
}


void
on_afficher_diet_clicked               (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *fgdiet, *fafficher_diet, *treediet;

fgdiet=lookup_widget(obj,"fgdiet");

gtk_widget_destroy(fgdiet);
fafficher_diet=lookup_widget(obj,"fafficher_diet");
fafficher_diet=create_fafficher_diet();
gtk_widget_show(fafficher_diet);
treediet=lookup_widget(fafficher_diet,"treediet");

afficher_diet(treediet);
}


void
on_qgdiet_clicked                      (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *fgdiet, *espaceAdmin;

fgdiet=lookup_widget(obj,"fgdiet");

gtk_widget_destroy(fgdiet);
espaceAdmin=create_espaceAdmin();
gtk_widget_show(espaceAdmin);
}

/*------------------------fajouter_diet----------------------------*/

void
on_vajouter_diet_clicked               (GtkWidget       *obj,
                                        gpointer         user_data)
{
Diet diet;

GtkWidget *input1, *input2,*input3,*input4,*input5,*input6,*input7,*input8;
GtkWidget *fajouter_diet;

fajouter_diet=lookup_widget(obj,"fajouter_diet");

input1=lookup_widget(obj,"d_nom");
input2=lookup_widget(obj,"d_prenom");
input3=lookup_widget(obj,"d_cin");
input4=lookup_widget(obj,"d_jour");
input5=lookup_widget(obj,"d_mois");
input6=lookup_widget(obj,"d_an");
input7=lookup_widget(obj,"d_mail");
input8=lookup_widget(obj,"d_adresse");

strcpy(diet.d_nom,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(diet.d_prenom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(diet.d_cin,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(diet.d_jour,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(diet.d_mois,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy(diet.d_an,gtk_entry_get_text(GTK_ENTRY(input6)));
strcpy(diet.d_mail,gtk_entry_get_text(GTK_ENTRY(input7)));
strcpy(diet.d_adresse,gtk_entry_get_text(GTK_ENTRY(input8)));

ajouter_diet(diet);

GtkWidget *fgdiet;

fajouter_diet=lookup_widget(obj,"fajouter_diet");

gtk_widget_destroy(fajouter_diet);
fgdiet=create_fgdiet();
gtk_widget_show(fgdiet);
}


void
on_qajouter_diet_clicked               (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *fajouter_diet, *fgdiet;

fajouter_diet=lookup_widget(obj,"fajouter_diet");

gtk_widget_destroy(fajouter_diet);
fgdiet=create_fgdiet();
gtk_widget_show(fgdiet);
}

/*--------------------------fafficher_diet--------------------------*/

void
on_modifier_diet_clicked               (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *fafficher_diet, *fchercher_diet;

fafficher_diet=lookup_widget(obj,"fafficher_diet");

gtk_widget_destroy(fafficher_diet);
fchercher_diet=create_fchercher_diet();
gtk_widget_show(fchercher_diet);
}


void
on_supprimer_diet_clicked              (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *fafficher_diet, *fsupprimer_diet;

fafficher_diet=lookup_widget(obj,"fafficher_diet");

gtk_widget_hide(fafficher_diet);
fsupprimer_diet=create_fsupprimer_diet();
gtk_widget_show(fsupprimer_diet);
}


void
on_qafficher_diet_clicked              (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *fafficher_diet, *fgdiet;

fafficher_diet=lookup_widget(obj,"fafficher_diet");

gtk_widget_destroy(fafficher_diet);
fgdiet=create_fgdiet();
gtk_widget_show(fgdiet);
}

/*------------------------fchercher_diet---------------------------*/

void
on_vchercher_diet_clicked              (GtkWidget       *obj,
                                        gpointer         user_data)
{

}


void
on_qchercher_diet_clicked              (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *fchercher_diet, *fgdiet;

fchercher_diet=lookup_widget(obj,"fchercher_diet");

gtk_widget_destroy(fchercher_diet);
fgdiet=create_fgdiet();
gtk_widget_show(fgdiet);
}

/*-----------------------fmodifier_diet----------------------------*/

void
on_vmodifier_diet_clicked              (GtkWidget       *obj,
                                        gpointer         user_data)
{

}


void
on_qmodifier_diet_clicked              (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *fmodifier_diet, *fgdiet;

fmodifier_diet=lookup_widget(obj,"fmodifier_diet");

gtk_widget_destroy(fmodifier_diet);
fgdiet=create_fgdiet();
gtk_widget_show(fgdiet);
}

/*-----------------------------fsupprimer_diet--------------------------*/

void
on_vsupprimer_diet_clicked             (GtkWidget       *obj,
                                        gpointer         user_data)
{
Diet diet;
char cinn[20];
GtkWidget *fsupprimer_diet, *fgdiet;
GtkWidget *input1;

fsupprimer_diet=lookup_widget(obj,"fsupprimer_diet");

input1=lookup_widget(obj,"s_diet");
strcpy(cinn,gtk_entry_get_text(GTK_ENTRY(input1)));

supprimer_diet(cinn);

gtk_widget_destroy(fsupprimer_diet);
fgdiet=create_fgdiet();
gtk_widget_show(fgdiet);
}


void
on_qsupprimer_diet_clicked             (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *fsupprimer_diet, *fgdiet;

fsupprimer_diet=lookup_widget(obj,"fsupprimer_diet");

gtk_widget_destroy(fsupprimer_diet);
fgdiet=create_fgdiet();
gtk_widget_show(fgdiet);
}

/*-----------------------------fgkine--------------------------------*/

void
on_ajouter_kine_clicked                (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *fgkine, *fajouter_kine;

fgkine=lookup_widget(obj,"fgkine");

gtk_widget_destroy(fgkine);
fajouter_kine=create_fajouter_kine();
gtk_widget_show(fajouter_kine);
}


void
on_afficher_kine_clicked               (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *fgkine, *fafficher_kine, *treekine;

fgkine=lookup_widget(obj,"fgkine");

gtk_widget_destroy(fgkine);
fafficher_kine=lookup_widget(obj,"fafficher_kine");
fafficher_kine=create_fafficher_kine();
gtk_widget_show(fafficher_kine);
treekine=lookup_widget(fafficher_kine,"treekine");

afficher_kine(treekine);
}


void
on_qgkine_clicked                      (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *fgkine, *espaceAdmin;

fgkine=lookup_widget(obj,"fgkine");

gtk_widget_destroy(fgkine);
espaceAdmin=create_espaceAdmin();
gtk_widget_show(espaceAdmin);
}

/*--------------------------fajouter_kine-----------------------------*/

void
on_vajouter_kine_clicked               (GtkWidget       *obj,
                                        gpointer         user_data)
{
Kine kine;

GtkWidget *input1, *input2,*input3,*input4,*input5,*input6,*input7,*input8;
GtkWidget *fajouter_kine;

fajouter_kine=lookup_widget(obj,"fajouter_kine");

input1=lookup_widget(obj,"k_nom");
input2=lookup_widget(obj,"k_prenom");
input3=lookup_widget(obj,"k_cin");
input4=lookup_widget(obj,"k_jour");
input5=lookup_widget(obj,"k_mois");
input6=lookup_widget(obj,"k_an");
input7=lookup_widget(obj,"k_mail");
input8=lookup_widget(obj,"k_adresse");

strcpy(kine.k_nom,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(kine.k_prenom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(kine.k_cin,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(kine.k_jour,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(kine.k_mois,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy(kine.k_an,gtk_entry_get_text(GTK_ENTRY(input6)));
strcpy(kine.k_mail,gtk_entry_get_text(GTK_ENTRY(input7)));
strcpy(kine.k_adresse,gtk_entry_get_text(GTK_ENTRY(input8)));

ajouter_kine(kine);

GtkWidget *fgkine;

fajouter_kine=lookup_widget(obj,"fajouter_kine");

gtk_widget_destroy(fajouter_kine);
fgkine=create_fgkine();
gtk_widget_show(fgkine);
}


void
on_qajouter_kine_clicked               (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *fajouter_kine, *fgkine;

fajouter_kine=lookup_widget(obj,"fajouter_kine");

gtk_widget_destroy(fajouter_kine);
fgkine=create_fgkine();
gtk_widget_show(fgkine);
}

/*-------------------------fafficher_kine----------------------------*/

void
on_modifier_kine_clicked               (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *fafficher_kine, *fchercher_kine;

fafficher_kine=lookup_widget(obj,"fafficher_kine");

gtk_widget_destroy(fafficher_kine);
fchercher_kine=create_fchercher_kine();
gtk_widget_show(fchercher_kine);
}


void
on_supprimer_kine_clicked              (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *fafficher_kine, *fsupprimer_kine;

fafficher_kine=lookup_widget(obj,"fafficher_kine");

gtk_widget_hide(fafficher_kine);
fsupprimer_kine=create_fsupprimer_kine();
gtk_widget_show(fsupprimer_kine);
}


void
on_qafficher_kine_clicked              (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *fafficher_kine, *fgkine;

fafficher_kine=lookup_widget(obj,"fafficher_kine");

gtk_widget_destroy(fafficher_kine);
fgkine=create_fgkine();
gtk_widget_show(fgkine);
}

/*-------------------------fchercher_kine---------------------------*/

void
on_vchercher_kine_clicked              (GtkWidget       *obj,
                                        gpointer         user_data)
{

}


void
on_qchercher_kine_clicked              (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *fchercher_kine, *fgkine;

fchercher_kine=lookup_widget(obj,"fchercher_kine");

gtk_widget_destroy(fchercher_kine);
fgkine=create_fgkine();
gtk_widget_show(fgkine);
}

/*-------------------------fmodifier_kine----------------------------*/

void
on_vmodifier_kine_clicked              (GtkWidget       *obj,
                                        gpointer         user_data)
{

}


void
on_qmodifier_kine_clicked              (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *fmodifier_kine, *fgkine;

fmodifier_kine=lookup_widget(obj,"fmodifier_kine");

gtk_widget_destroy(fmodifier_kine);
fgkine=create_fgkine();
gtk_widget_show(fgkine);
}

/*-----------------------------fsupprimer_kine--------------------------*/

void
on_vsupprimer_kine_clicked             (GtkWidget       *obj,
                                        gpointer         user_data)
{
Kine kine;
char cinn[20];
GtkWidget *fsupprimer_kine, *fgkine;
GtkWidget *input1;

fsupprimer_kine=lookup_widget(obj,"fsupprimer_kine");

input1=lookup_widget(obj,"s_kine");
strcpy(cinn,gtk_entry_get_text(GTK_ENTRY(input1)));

supprimer_kine(cinn);

gtk_widget_destroy(fsupprimer_kine);
fgkine=create_fgkine();
gtk_widget_show(fgkine);
}


void
on_qsupprimer_kine_clicked             (GtkWidget       *obj,
                                        gpointer         user_data)
{
GtkWidget *fsupprimer_kine, *fgkine;

fsupprimer_kine=lookup_widget(obj,"fsupprimer_kine");

gtk_widget_destroy(fsupprimer_kine);
fgkine=create_fgkine();
gtk_widget_show(fgkine);
}



