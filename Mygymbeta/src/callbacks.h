#include "verifier.h"

#include <gtk/gtk.h>


gchar *name;
personne p; 
Admin a;
Adherent b;
Coach c;
Medecin m;
Kine k;


void
on_connexion_ac_clicked                (GtkWidget       *button,
                                        gpointer         user_data);

void
on_bouttonconnexion_clicked            (GtkWidget       *widget,
                                        gpointer         user_data);

gboolean
on_connexion_ac_destroy_event          (GtkWidget       *widget,
                                        GdkEvent        *event,
                                        gpointer         user_data);

void
on_connexion_ac_destroy                (GtkWidget       *object,
                                        gpointer         user_data);

void
on_buttonajoutpersonne_clicked         (GtkWidget       *widget,
                                        gpointer         user_data);

void
on_buttonajoutadmin_clicked            (GtkWidget       *widget,
                                        gpointer         user_data);

void
on_buttonadminretour_clicked           (GtkWidget       *widget,
                                        gpointer         user_data);

void
on_gererprofileadherent_clicked        (GtkWidget      *widget,
                                        gpointer         user_data);

void
on_buttonmodifierprofil_clicked        (GtkWidget       *widget,
                                        gpointer         user_data);

void
on_buttonenregistrermodification_clicked
                                        (GtkWidget       *widget,
                                        gpointer         user_data);


void
on_treeviewevenementadherent_row_activated
                                        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_treeviewcoachadherent_row_activated (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_treeviewstaffmedicaladherent_row_activated
                                        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_sinscriraucours_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_sedeconnecteradherent_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttondeconnexionadmin_clicked      (GtkButton       *button,
                                        gpointer         user_data);

void
on_modifierpresentation_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeviewevenementadmin_row_activated
                                        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_ajouterevenement_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonajouterboutique_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeviewlistecoachadmin_row_activated
                                        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_treeviewlistestaffmedicaladmin_row_activated
                                        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_treeviewlisteadherentadmin_row_activated
                                        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_buttonlisterdvmedecin_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttondeconnexioncoach_clicked      (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonlistecourscoach_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeviewlisteadherentcoach_row_activated
                                        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_treeviewlisteadherentkine_row_activated
                                        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_buttondeconnexionkine_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonretourcreeevenement_clicked   (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonenregisterevenement_clicked   (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonretouracreeitem_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonenregisteritem_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonmodifprofilcoach_clicked      (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonmodifprofilmedecin_clicked    (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonmodifprofilkine_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonenregistermodifcoach_clicked  (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonenregistermodifmedecin_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonenregistermodifkine_clicked   (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonmodiffichemedical_clicked     (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonenregistermodiffichemedical_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeviewadherentcours_row_activated (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_treeviewrdvmedecinadherent_row_activated
                                        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_treeviewrdvkineadherent_row_activated
                                        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_treeviewcourscoach_row_activated    (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_ajoutercours_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeviewrdvmedecin_row_activated    (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_buttonajouterrdvmedecin_clicked     (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeviewrdvkine_row_activated       (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_buttonajouterrdvkine_clicked        (GtkWidget       *widget,
                                        gpointer         user_data);

void
on_buttonenregistercours_clicked       (GtkWidget       *widget,
                                        gpointer         user_data);

void
on_buttonretourajoutercours_clicked    (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonretourrdvmedecin_clicked      (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonretourrdvkine_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonrenregistrerrdvkine_clicked   (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeviewcourspouradherent_row_activated
                                        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_buttoninscriptioncours_clicked      (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonsupprimercours_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeviewcoursdeadherent_row_activated
                                        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_treeviewdisponibilitepouradherent_row_activated
                                        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_buttonprendrerdv_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonprofiladmin_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonmodifierprofiladmin_clicked   (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonenregistermodifadmin_clicked  (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonprofilcoach_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonprofilmedecin_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonprofilkine_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonconfirmer_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonannuler_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonsuppretionadherent_clicked    (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonannuleradherent_clicked       (GtkButton       *button,
                                        gpointer         user_data);
