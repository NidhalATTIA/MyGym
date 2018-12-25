#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "verifier.h"
#include "string.h"
GtkWidget *windowconfirmationadherent;
GtkWidget *windowconfirmation;
GtkWidget *widowmodifierprofilkine;
GtkWidget *windowprofilkine;
GtkWidget *windowmodifierprofilmedecin;
GtkWidget *windowprofilmedecin;
GtkWidget *windowmodifierprofilcoach;
GtkWidget *windowprofilcoach;
GtkWidget *windowmodifierprofiladmin;
GtkWidget *affichercourspouradherent; 
GtkWidget *ajoutmembre;
GtkWidget *acceuilnc;
GtkWidget *windowconnexion;
GtkWidget *acceuiladheren;
GtkWidget *acceuiladmin;
GtkWidget *acceuilcoach;
GtkWidget *accueilmedecin;
GtkWidget *ajoutmembre;
GtkWidget *afficherprofilad;
GtkWidget *modifierprofil;
GtkWidget *entreepoids;
GtkWidget *entreetaille;
GtkWidget *entreenumerotel;
GtkWidget *entreeemail;
GtkWidget *labeltestafftree;
GtkWidget *acceuilkine;
GtkWidget *courscoach;
GtkWidget *ajoutercours;
GtkWidget *afficherprofiladmin;
 gchar *cincoach;
 gchar *prenomcoachpourinscrit;
 gchar *nomcoachpourinscrit;
 gchar *prenomkinepourinscrit;
 gchar *nomkinepourinscrit;
 gchar *cincoachpourinscrit;
 gchar *cinkinepourinscrit;
 gchar *datecourspourinscrit;
 gchar *heurecourspourinscrit;
 gchar *typecourspourinscrit;
 gchar *daterdvpourinscrit;
 gchar *heurerdvpourinscrit;
 gchar *typerdvpourinscrit;
 gchar *datercinscrit;
 gchar *heurecinscrit;
 gchar *typecinscrit;
enum{
	CIN,
	COLUMNS

};
enum{
	PRENOM,
	NOM,
	HEURE,
	DATE,
	TYPE,
};
enum{
PRENOMd,
	NOMd,
	HEUREd,
	DATEd,
	TYPEd,



};
enum{
 TYPEA,
 DATEA,
 HEUREA,
};
 
void
on_connexion_ac_clicked                (GtkWidget       *button,
                                        gpointer         user_data)

	{
  windowconnexion = create_windowconnexion();
  gtk_widget_show (windowconnexion);

}


void
on_bouttonconnexion_clicked            (GtkWidget       *widget,
                                        gpointer         user_data)
{ 
   GtkWidget *entreepasswordconnexion;
   GtkWidget *entreepseudoconnexion;

  
	GtkWidget *labelerrconnexion;
	
	char login12[30];char password12[30];char err[30];char role [30];
	labelerrconnexion=lookup_widget(widget,"labelerrconnexion");
	entreepseudoconnexion=lookup_widget(widget,"entreepseudoconnexion");
	entreepasswordconnexion=lookup_widget(widget,"entreepasswordconnexion");
	//role=lookup_widget(widget,"role");
	strcpy(login12,gtk_entry_get_text(GTK_ENTRY(entreepseudoconnexion)));
	strcpy(password12,gtk_entry_get_text(GTK_ENTRY(entreepasswordconnexion)));
	p=verifier(login12,password12);
	strcpy(err,"infos incorrect");
	strcpy(role,"Administrateur");
	gtk_label_set_text(GTK_LABEL(labelerrconnexion),p.prole);
	if (strcmp(p.prole,"Adhérent")==0)
	{

	
	b=chargeradherent(p.pcin);
	acceuiladheren=create_acceuiladheren();
 	gtk_widget_destroy(windowconnexion);
        gtk_widget_show(acceuiladheren);
        GtkWidget *treeviewcoachadherent;
	GtkWidget *treeviewstaffmedicaladherent;
	GtkWidget *treeviewevenementadherent;
treeviewstaffmedicaladherent=lookup_widget(acceuiladheren,"treeviewstaffmedicaladherent");
treeviewcoachadherent=lookup_widget(acceuiladheren,"treeviewcoachadherent");
treeviewevenementadherent=lookup_widget(acceuiladheren,"treeviewevenementadherent");
labeltestafftree=lookup_widget(acceuiladheren,"labeltestafftree");
affichercoachsad(treeviewcoachadherent);
afficherkinesad(treeviewstaffmedicaladherent);
GtkWidget *treeview10;
treeview10 = lookup_widget(acceuiladheren,"treeview10");
afficheradmin(treeview10);
}else if (strcmp(p.prole,"Administrateur")==0){
a=chargeradmin(p.pcin);
acceuiladmin=create_acceuiladmin();
 gtk_widget_destroy(windowconnexion);
  gtk_widget_show(acceuiladmin);
GtkWidget *treeviewlistecoachadmin;
treeviewlistecoachadmin =lookup_widget(acceuiladmin,"treeviewlistecoachadmin");
affichercoachsad(treeviewlistecoachadmin);
GtkWidget *treeviewlistestaffmedicaladmin;
treeviewlistestaffmedicaladmin = lookup_widget(acceuiladmin,"treeviewlistestaffmedicaladmin");
afficherkinesad(treeviewlistestaffmedicaladmin);
GtkWidget *treeviewlisteadherentadmin;
treeviewlisteadherentadmin = lookup_widget(acceuiladmin,"treeviewlisteadherentadmin");
afficheradherent(treeviewlisteadherentadmin);
GtkWidget *treeview19;
treeview19=lookup_widget(acceuiladmin,"treeview19");
  afficheradmin(treeview19);
}else if(strcmp(p.prole,"Coach")==0){
        c=chargercoach(p.pcin);
	acceuilcoach=create_acceuilcoach();
 	gtk_widget_destroy(windowconnexion);
  gtk_widget_show(acceuilcoach);
 GtkWidget *treeview27;
treeview27 = lookup_widget(acceuilcoach,"treeview27");
affichercoachsad(treeview27);
GtkWidget *treeview28;
treeview28 = lookup_widget(acceuilcoach,"treeview28");
afficherkinesad(treeview28);
GtkWidget *treeviewlisteadherentcoach;
treeviewlisteadherentcoach = lookup_widget(acceuilcoach,"treeviewlisteadherentcoach");
afficheradherent(treeviewlisteadherentcoach); 


}else if(strcmp(p.prole,"Médecin")==0){

m=chargermedecin(p.pcin);
accueilmedecin=create_accueilmedecin();
gtk_widget_destroy(windowconnexion);
gtk_widget_show(accueilmedecin);


}else if(strcmp(p.prole,"Kinésithérapeute")==0){
k=chargerkine(p.pcin);
acceuilkine=create_acceuilkine();
gtk_widget_destroy(windowconnexion);
gtk_widget_show(acceuilkine);

}


}




void
on_connexion_ac_destroy                (GtkWidget       *object,
                                        gpointer         user_data)
{
 gtk_widget_destroy(acceuilnc);
 
}


void
on_buttonajoutpersonne_clicked         (GtkWidget       *Widget,
                                        gpointer         user_data)
{
ajoutmembre = create_ajoutmembre();
  gtk_widget_show (ajoutmembre);
}


void
on_buttonajoutadmin_clicked            (GtkWidget       *widget,
                                        gpointer         user_data)
{
GtkWidget *labeltest1;
GtkWidget *ajoutCIN;
GtkWidget *ajoutrenom;
GtkWidget *ajoutnom;
GtkWidget *ajoutpseudo;
GtkWidget *ajoutpassword;
GtkWidget *comboboxrole;
GtkWidget *spinbuttonajoutjour;
GtkWidget *spinbuttonajoutmois;
GtkWidget *spinbuttonajoutannee;
GtkWidget *spinbuttoninscritjour;
GtkWidget *spinbuttoninscritmois;
GtkWidget *spinbuttoninscritanne;
personne inscrit;

char cin[30],nom[30],prenom[30],pseudo[30],role[30],password[30],dateinscrit[30],datenaissance[30];
int journ,moisn,anneen,jouri,moisi,annei;
char journs[30]="",moisns[30]="",anneens[30]="",jouris[30]="",moisis[30]="",anneis[30]="";
ajoutCIN=lookup_widget(widget,"ajoutCIN");
ajoutrenom=lookup_widget(widget,"ajoutrenom");
ajoutnom=lookup_widget(widget,"ajoutnom");
ajoutpseudo=lookup_widget(widget,"ajoutpseudo");
ajoutpassword=lookup_widget(widget,"ajoutpassword");
comboboxrole=lookup_widget(widget,"comboboxrole");
spinbuttonajoutjour=lookup_widget(widget,"spinbuttonajoutjour");
spinbuttonajoutmois=lookup_widget(widget,"spinbuttonajoutmois");
spinbuttonajoutannee=lookup_widget(widget,"spinbuttonajoutannee");
spinbuttoninscritjour=lookup_widget(widget,"spinbuttoninscritjour");
spinbuttoninscritmois=lookup_widget(widget,"spinbuttoninscritmois");
spinbuttoninscritanne=lookup_widget(widget,"spinbuttoninscritanne");
labeltest1=lookup_widget(widget,"labeltest1");

strcpy(inscrit.pcin,gtk_entry_get_text(GTK_ENTRY(ajoutCIN)));
strcpy(inscrit.pprenom,gtk_entry_get_text(GTK_ENTRY(ajoutrenom)));
strcpy(inscrit.pnom,gtk_entry_get_text(GTK_ENTRY(ajoutnom)));
strcpy(inscrit.ppseudo,gtk_entry_get_text(GTK_ENTRY(ajoutpseudo)));
strcpy(inscrit.ppassword,gtk_entry_get_text(GTK_ENTRY(ajoutpassword)));
strcpy(inscrit.prole,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxrole)));

journ=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (spinbuttonajoutjour));
moisn=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (spinbuttonajoutmois));
anneen=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (spinbuttonajoutannee));
jouri=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (spinbuttoninscritjour));
moisi=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (spinbuttoninscritmois));
annei=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (spinbuttoninscritanne));
snprintf(journs,sizeof journs,"%d",journ);
snprintf(moisns,sizeof moisns,"%d",moisn);
snprintf(anneens,sizeof anneens,"%d",anneen);
snprintf(jouris,sizeof jouris,"%d",jouri);
snprintf(moisis,sizeof moisis,"%d",moisi);
snprintf(anneis,sizeof anneis,"%d",annei);
strcpy(inscrit.pdatenaissance,journs);
strcat(inscrit.pdatenaissance,"/");
strcat(inscrit.pdatenaissance,moisns);
strcat(inscrit.pdatenaissance,"/");
strcat(inscrit.pdatenaissance,anneens);
strcpy(inscrit.pdateinscrit,jouris);
strcat(inscrit.pdateinscrit,"/");
strcat(inscrit.pdateinscrit,moisis);
strcat(inscrit.pdateinscrit,"/");
strcat(inscrit.pdateinscrit,anneis);
gtk_label_set_text(GTK_LABEL(labeltest1),inscrit.pdateinscrit);
ajouter_personne(inscrit);

}


void
on_buttonadminretour_clicked           (GtkWidget       *widget,
                                        gpointer         user_data)
{
gtk_widget_destroy (ajoutmembre);
}


void
on_gererprofileadherent_clicked        (GtkWidget       *widget,
                                        gpointer         user_data)
{
afficherprofilad = create_afficherprofilad();
  gtk_widget_show (afficherprofilad);
}


void
on_buttonmodifierprofil_clicked        (GtkWidget       *widget,
                                        gpointer         user_data)
{

gtk_widget_destroy(afficherprofilad);
modifierprofil = create_modifierprofil();
  gtk_widget_show(afficherprofilad);

}


void
on_buttonenregistrermodification_clicked
                                        (GtkWidget       *widget,
                                        gpointer         user_data)
{

entreepoids=lookup_widget(widget,"entreepoids");
entreetaille=lookup_widget(widget,"entreetaille");
entreenumerotel=lookup_widget(widget,"entreenumerotel");
entreeemail=lookup_widget(widget,"entreeemail");
strcpy(b.poids,gtk_entry_get_text(GTK_ENTRY(entreepoids)));
strcpy(b.taille,gtk_entry_get_text(GTK_ENTRY(entreetaille)));
strcpy(b.numerotelad,gtk_entry_get_text(GTK_ENTRY(entreenumerotel)));
strcpy(b.email,gtk_entry_get_text(GTK_ENTRY(entreeemail)));

profile(b);
b=chargeradherent(p.pcin);
gtk_widget_destroy(modifierprofil);
}




void
on_treeviewevenementadherent_row_activated
                                        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter   iter;
  GtkTreeModel *model;

  model = gtk_tree_view_get_model(treeview);

  if (gtk_tree_model_get_iter(model, &iter, path))
  {

    gtk_tree_model_get(model, &iter, CIN, &name, -1);

    g_print ("The row containing the name '%s' has been double-clicked.\n", name);
gtk_label_set_text(GTK_LABEL(labeltestafftree),name);
}
}


void
on_treeviewcoachadherent_row_activated (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter   iter;
  GtkTreeModel *model;

  model = gtk_tree_view_get_model(treeview);

  if (gtk_tree_model_get_iter(model, &iter, path))
  {

    gtk_tree_model_get(model, &iter, CIN, &cincoachpourinscrit, -1);

    g_print ("The row containing the name '%s' has been double-clicked.\n", cincoachpourinscrit);
	
	GtkWidget *treeviewcourspouradherent;
	affichercourspouradherent=create_affichercourspouradherent();
	 gtk_widget_show(affichercourspouradherent);
	treeviewcourspouradherent=lookup_widget(affichercourspouradherent,"treeviewcourspouradherent");
	affichercourspouradgherent(treeviewcourspouradherent,cincoachpourinscrit);
}}


void
on_treeviewstaffmedicaladherent_row_activated
                                        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter   iter;
  GtkTreeModel *model;

  model = gtk_tree_view_get_model(treeview);

  if (gtk_tree_model_get_iter(model, &iter, path))
  {

    gtk_tree_model_get(model, &iter, CIN, &cinkinepourinscrit, -1);

    g_print ("The row containing the name '%s' has been double-clicked.\n",cinkinepourinscrit);
       GtkWidget *afficherdispopouradherent;
       GtkWidget *treeviewdisponibilitepouradherent;
	afficherdispopouradherent=create_afficherdispopouradherent();
	 gtk_widget_show(afficherdispopouradherent);
	treeviewdisponibilitepouradherent=lookup_widget(afficherdispopouradherent,"treeviewdisponibilitepouradherent");
	afficherdispopouradgherent(treeviewdisponibilitepouradherent,cinkinepourinscrit);
}
}

void
on_sinscriraucours_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *treeviewcoursdeadherent;
GtkWidget *affichercours;
affichercours=create_affichercours();
gtk_widget_show(affichercours);
treeviewcoursdeadherent=lookup_widget(affichercours,"treeviewcoursdeadherent");
affichercoursdeadherent(treeviewcoursdeadherent,b.pcin);
}


void
on_sedeconnecteradherent_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{
gtk_widget_destroy(acceuiladheren);
acceuilnc = create_acceuilnc();
  gtk_widget_show(acceuilnc);
}


void
on_buttondeconnexionadmin_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{
gtk_widget_destroy(acceuiladmin);
acceuilnc = create_acceuilnc();
  gtk_widget_show(acceuilnc);
}


void
on_modifierpresentation_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_treeviewevenementadmin_row_activated
                                        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_ajouterevenement_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_buttonajouterboutique_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_treeviewlistecoachadmin_row_activated
                                        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter   iter;
  GtkTreeModel *model;

  model = gtk_tree_view_get_model(treeview);

  if (gtk_tree_model_get_iter(model, &iter, path))
  {

    gtk_tree_model_get(model, &iter, CIN, &cincoach, -1);

    g_print ("The row containing the name '%s' has been double-clicked.\n", cincoach);
    windowconfirmation= create_windowconfirmation();
    gtk_widget_show(windowconfirmation);	
    
}
}

void
on_treeviewlistestaffmedicaladmin_row_activated
                                        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter   iter;
  GtkTreeModel *model;

  model = gtk_tree_view_get_model(treeview);

  if (gtk_tree_model_get_iter(model, &iter, path))
  {

    gtk_tree_model_get(model, &iter, CIN, &cincoach, -1);

    g_print ("The row containing the name '%s' has been double-clicked.\n", cincoach);
    
}
}


void
on_treeviewlisteadherentadmin_row_activated
                                        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter   iter;
  GtkTreeModel *model;

  model = gtk_tree_view_get_model(treeview);

  if (gtk_tree_model_get_iter(model, &iter, path))
  {

    gtk_tree_model_get(model, &iter, CIN, &cincoach, -1);

    g_print ("The row containing the name '%s' has been double-clicked.\n", cincoach);
    windowconfirmationadherent=create_windowconfirmationadherent();
    gtk_widget_show(windowconfirmationadherent);
}
}


void
on_buttonlisterdvmedecin_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_buttondeconnexioncoach_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{
gtk_widget_destroy(acceuilcoach);
acceuilnc = create_acceuilnc();
  gtk_widget_show(acceuilnc);
}


void
on_buttonlistecourscoach_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *treeviewcourscoach;
courscoach = create_courscoach();
gtk_widget_show(courscoach);
treeviewcourscoach=lookup_widget(courscoach,"treeviewcourscoach");
affichercours(treeviewcourscoach,c);
}


void
on_treeviewlisteadherentcoach_row_activated
                                        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter   iter;
  GtkTreeModel *model;

  model = gtk_tree_view_get_model(treeview);

  if (gtk_tree_model_get_iter(model, &iter, path))
  {

    gtk_tree_model_get(model, &iter, CIN, &cincoach, -1);

    g_print ("The row containing the name '%s' has been double-clicked.\n", cincoach);
    
}
}


void
on_treeviewlisteadherentkine_row_activated
                                        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter   iter;
  GtkTreeModel *model;

  model = gtk_tree_view_get_model(treeview);

  if (gtk_tree_model_get_iter(model, &iter, path))
  {

    gtk_tree_model_get(model, &iter, CIN, &cincoach, -1);

    g_print ("The row containing the name '%s' has been double-clicked.\n", cincoach);
    
}
}


void
on_buttondeconnexionkine_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{
gtk_widget_destroy(acceuilkine);
acceuilnc = create_acceuilnc();
  gtk_widget_show(acceuilnc);
}


void
on_buttonretourcreeevenement_clicked   (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_buttonenregisterevenement_clicked   (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_buttonretouracreeitem_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_buttonenregisteritem_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_buttonmodifprofilcoach_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{


windowmodifierprofilcoach = create_windowmodifierprofilcoach();
  gtk_widget_show (windowmodifierprofilcoach);
 gtk_widget_destroy(windowprofilcoach);
}


void
on_buttonmodifprofilmedecin_clicked    (GtkButton       *button,
                                        gpointer         user_data)
{
windowmodifierprofilmedecin = create_windowmodifierprofilmedecin();
  gtk_widget_show (windowmodifierprofilmedecin);
 gtk_widget_destroy(windowprofilmedecin);
}


void
on_buttonmodifprofilkine_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{

widowmodifierprofilkine = create_widowmodifierprofilkine();
  gtk_widget_show (widowmodifierprofilkine);
 gtk_widget_destroy(windowprofilkine);
}


void
on_buttonenregistermodifcoach_clicked  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *entryspecialitecoach;
GtkWidget *entrynumtelcoach;
GtkWidget *entryemailcoach;
entryspecialitecoach=lookup_widget(windowmodifierprofilcoach,"entryspecialitecoach");
entrynumtelcoach=lookup_widget(windowmodifierprofilcoach,"entrynumtelcoach");
entryemailcoach=lookup_widget(windowmodifierprofilcoach,"entryemailcoach");
strcpy(c.cspecialite,gtk_entry_get_text(GTK_ENTRY(entryspecialitecoach)));
strcpy(c.cnumerotel,gtk_entry_get_text(GTK_ENTRY(entrynumtelcoach)));
strcpy(c.cemail,gtk_entry_get_text(GTK_ENTRY(entryemailcoach)));
profileCoach(c);
c=chargercoach(c.ccin);
gtk_widget_destroy(windowmodifierprofilcoach);
}


void
on_buttonenregistermodifmedecin_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *entryspecialitemed;
GtkWidget *entrytelmed;
GtkWidget *entryemailmed;
entryspecialitemed=lookup_widget(windowmodifierprofilmedecin,"entryspecialitemed");
entrytelmed=lookup_widget(windowmodifierprofilmedecin,"entrytelmed");
entryemailmed=lookup_widget(windowmodifierprofilmedecin,"entryemailmed");
strcpy(m.specialite,gtk_entry_get_text(GTK_ENTRY(entryspecialitemed)));
strcpy(m.mtel,gtk_entry_get_text(GTK_ENTRY(entrytelmed)));
strcpy(m.memail,gtk_entry_get_text(GTK_ENTRY(entryemailmed)));
profilemedecin(m);
m=chargermedecin(m.mcin);
gtk_widget_destroy(windowmodifierprofilmedecin);
}


void
on_buttonenregistermodifkine_clicked   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *entryspecialitekine;
GtkWidget *entrytelkine;
GtkWidget *entryemailkine;
entryspecialitekine=lookup_widget(widowmodifierprofilkine,"entryspecialitekine");
entrytelkine=lookup_widget(widowmodifierprofilkine,"entrytelkine");
entryemailkine=lookup_widget(widowmodifierprofilkine,"entryemailkine");
strcpy(k.specialite,gtk_entry_get_text(GTK_ENTRY(entryspecialitekine)));
strcpy(k.dtel,gtk_entry_get_text(GTK_ENTRY(entrytelkine)));
strcpy(k.demail,gtk_entry_get_text(GTK_ENTRY(entryemailkine)));
profileKine(k);
k=chargerkine(k.dcin);
gtk_widget_destroy(widowmodifierprofilkine);
}


void
on_buttonmodiffichemedical_clicked     (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_buttonenregistermodiffichemedical_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_treeviewadherentcours_row_activated (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_treeviewrdvmedecinadherent_row_activated
                                        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_treeviewrdvkineadherent_row_activated
                                        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_treeviewcourscoach_row_activated    (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_ajoutercours_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
ajoutercours = create_ajoutercours();
 gtk_widget_show(ajoutercours);
 gtk_widget_destroy(courscoach);

}


void
on_treeviewrdvmedecin_row_activated    (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_buttonajouterrdvmedecin_clicked     (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_treeviewrdvkine_row_activated       (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_buttonajouterrdvkine_clicked        (GtkWidget       *widget,
                                        gpointer         user_data)
{

}


void
on_buttonenregistercours_clicked       (GtkWidget       *widget,
                                        gpointer         user_data)
{GtkWidget *spinbuttonjourcours;
 GtkWidget *spinbuttonmoiscours;
 GtkWidget *spinbuttonanneecours;
 GtkWidget *comboboxheurecours;
 GtkWidget *comboboxtypecours;
 cours cour;
 spinbuttonjourcours=lookup_widget(widget,"spinbuttonjourcours");
 spinbuttonmoiscours=lookup_widget(widget,"spinbuttonmoiscours");
 spinbuttonanneecours=lookup_widget(widget,"spinbuttonanneecours");
 comboboxheurecours=lookup_widget(widget,"comboboxheurecours");
 comboboxtypecours=lookup_widget(widget,"comboboxtypecours");
 int jour,mois,annee; char jours[10],moiss[10],annees[10];
 jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (spinbuttonjourcours));
 mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (spinbuttonmoiscours));
 annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (spinbuttonanneecours));
 snprintf(jours,sizeof jours,"%d",jour);
 snprintf(moiss,sizeof moiss,"%d",mois);
 snprintf(annees,sizeof annees,"%d",annee);
 strcpy(cour.cincoach,c.ccin);
 strcpy(cour.prenomcoach,c.cprenom);
 strcpy(cour.nomcoach,c.cnom);
 strcpy(cour.date,jours);
 strcat(cour.date,"/");
 strcat(cour.date,moiss);
 strcat(cour.date,"/");
 strcat(cour.date,annees);
 strcpy(cour.horaire,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxheurecours)));
 strcpy(cour.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxtypecours)));
 ajoutercour(c,cour);

}


void
on_buttonretourajoutercours_clicked    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_buttonretourrdvmedecin_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_buttonretourrdvkine_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_buttonrenregistrerrdvkine_clicked   (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_treeviewcourspouradherent_row_activated
                                        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter   iter;
  GtkTreeModel *model;

  model = gtk_tree_view_get_model(treeview);

  if (gtk_tree_model_get_iter(model, &iter, path))
  {

    gtk_tree_model_get(model, &iter, PRENOM, &prenomcoachpourinscrit, NOM, &nomcoachpourinscrit, DATE,&datecourspourinscrit, HEURE,&heurecourspourinscrit,TYPE,&typecourspourinscrit, -1);

    g_print ("The row containing the name %s %s %s %s %s has been double-clicked.\n",prenomcoachpourinscrit,nomcoachpourinscrit,datecourspourinscrit, heurecourspourinscrit,typecourspourinscrit);
	
	GtkWidget *treeviewcourspouradherent;
	treeviewcourspouradherent=lookup_widget(affichercourspouradherent,"treeviewcourspouradherent");

}
}


void
on_buttoninscriptioncours_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{
sinscrireaucour(b,cincoachpourinscrit,datecourspourinscrit,typecourspourinscrit,heurecourspourinscrit);
}




void
on_treeviewcoursdeadherent_row_activated
                                        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

GtkTreeIter   iter;
  GtkTreeModel *model;

  model = gtk_tree_view_get_model(treeview);

  if (gtk_tree_model_get_iter(model, &iter, path))
  {

    gtk_tree_model_get(model, &iter, TYPEA, &typecinscrit, DATEA, &datercinscrit, HEUREA,&heurecinscrit,-1);

    g_print ("The row containing the name %s %s %s has been double-clicked.\n",typecinscrit,datercinscrit,heurecinscrit);
	
	

}
}

void
on_buttonsupprimercours_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{
supprimercours(b.pcin,typecinscrit,datercinscrit,heurecinscrit);
}

void
on_treeviewdisponibilitepouradherent_row_activated
                                        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter   iter;
  GtkTreeModel *model;

  model = gtk_tree_view_get_model(treeview);

  if (gtk_tree_model_get_iter(model, &iter, path))
  {

    gtk_tree_model_get(model, &iter, PRENOMd, &prenomkinepourinscrit, NOMd, &nomkinepourinscrit, DATEd,&daterdvpourinscrit, HEUREd,&heurerdvpourinscrit,TYPEd,&typerdvpourinscrit, -1);

    g_print ("The row containing the name %s %s %s %s %s has been double-clicked.\n",prenomkinepourinscrit,nomkinepourinscrit,daterdvpourinscrit, heurerdvpourinscrit,typerdvpourinscrit);
	
	

}
}


void
on_buttonprendrerdv_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
sinscrireaurdv(b,cinkinepourinscrit,daterdvpourinscrit,typerdvpourinscrit,heurerdvpourinscrit);
}


void
on_buttonprofiladmin_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
afficherprofiladmin = create_afficherprofiladmin();
  gtk_widget_show (afficherprofiladmin);
}


void
on_buttonmodifierprofiladmin_clicked   (GtkButton       *button,
                                        gpointer         user_data)
{
windowmodifierprofiladmin = create_windowmodifierprofiladmin();
  gtk_widget_show (windowmodifierprofiladmin);
 gtk_widget_destroy(afficherprofiladmin);
}


void
on_buttonenregistermodifadmin_clicked  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *entryemailadmin;
GtkWidget *entryteladmin;
entryteladmin=lookup_widget(windowmodifierprofiladmin,"entryteladmin");
entryemailadmin=lookup_widget(windowmodifierprofiladmin,"entryemailadmin");
strcpy(a.atel,gtk_entry_get_text(GTK_ENTRY(entryteladmin)));
strcpy(a.aemail,gtk_entry_get_text(GTK_ENTRY(entryemailadmin)));

profileadmin(a);
a=chargeradmin(a.acin);
gtk_widget_destroy(windowmodifierprofiladmin);
}


void
on_buttonprofilcoach_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
windowprofilcoach = create_windowprofilcoach();
  gtk_widget_show (windowprofilcoach);
}


void
on_buttonprofilmedecin_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
windowprofilmedecin = create_windowprofilmedecin();
  gtk_widget_show (windowprofilmedecin);
}


void
on_buttonprofilkine_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{

windowprofilkine = create_windowprofilkine();
  gtk_widget_show (windowprofilkine);
}


void
on_buttonconfirmer_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
supprimercoach(cincoach);
gtk_widget_destroy(windowconfirmation);
}


void
on_buttonannuler_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
gtk_widget_destroy(windowconfirmation);
}


void
on_buttonsuppretionadherent_clicked    (GtkButton       *button,
                                        gpointer         user_data)
{
supprimeradherent(cincoach);
gtk_widget_destroy(windowconfirmationadherent);
}


void
on_buttonannuleradherent_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{
gtk_widget_destroy(windowconfirmationadherent);
}

