#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "ajout.h"
#include "ajou.h"
#include "verifl.h"
#include <string.h>


void
on_button1_clicked                     (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkWidget *window1;
GtkWidget *window2;
window1=lookup_widget(objet,"window1");
gtk_widget_destroy(window1);
window2=create_window2();

gtk_widget_show(window2);
GtkWidget *treeview2;
treeview2=lookup_widget(window2,"treeview2");
afficher1(treeview2);
}


void
on_button2_clicked                     (GtkWidget      *objet,
                                        gpointer         user_data)
{GtkWidget *window1;
GtkWidget *window5;
window1=lookup_widget(objet,"window1");
gtk_widget_destroy(window1);
window5=create_window5();
gtk_widget_show(window5);

}


void
on_button3_clicked                     (GtkWidget      *objet,
                                        gpointer         user_data)
{GtkWidget *window1;
GtkWidget *window4;
window1=lookup_widget(objet,"window1");
gtk_widget_destroy(window1);
window4=create_window4();
gtk_widget_show(window4);

}


void
on_button5_clicked                     (GtkWidget      *objet,
                                        gpointer         user_data)
{GtkWidget *window3;
GtkWidget *window5;
window3=lookup_widget(objet,"window3");
gtk_widget_destroy(window3);
window5=create_window5();
gtk_widget_show(window5);

}





void
on_button6_clicked                     (GtkWidget      *objet,
                                        gpointer         user_data)
{GtkWidget *window3;
GtkWidget *window7;
window3=lookup_widget(objet,"window3");
gtk_widget_destroy(window3);
window7=create_window7();
gtk_widget_show(window7);

}


void
on_button7_clicked                     (GtkWidget      *objet,
                                        gpointer         user_data)
{GtkWidget *window3;
GtkWidget *window6;
window3=lookup_widget(objet,"window3");
gtk_widget_destroy(window3);
window6=create_window6();
gtk_widget_show(window6);

}


void
on_button9_clicked                     (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{
date d;
GtkWidget *jour;
GtkWidget *mois;
GtkWidget *annee;
GtkWidget *heure;
int num;
GtkWidget *window5;
GtkWidget *output;
jour=lookup_widget(objet_graphique,"jour");
mois=lookup_widget(objet_graphique,"mois");
annee=lookup_widget(objet_graphique,"annee");
heure=lookup_widget(objet_graphique,"heure");
num=lookup_widget(objet_graphique,"num");
output=lookup_widget(objet_graphique,"label63");
d.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (jour));
d.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (mois));
d.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (annee));
d.heure=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (heure));
d.num=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (num));

if (verif(d.num)==0)
ajoute(d);
else gtk_label_set_text(GTK_LABEL(output),"num existe déja");


}



void
on_button10_clicked                    (GtkWidget      *objet,
                                        gpointer         user_data)
{ int num=0;
GtkWidget *window5;
GtkWidget *window3;
GtkWidget *treeview1;
window5=lookup_widget(objet,"window5");

gtk_widget_destroy(window5);
window3=lookup_widget(objet,"window3");
window3=create_window3();
gtk_widget_show(window3);
treeview1=lookup_widget(window3,"treeview1");
afficher(treeview1);

}


void
on_button11_clicked                    (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{GtkWidget *window6;
GtkWidget *num1;
int x;
num1=lookup_widget(objet_graphique,"num1");
num1=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (num1));
supprim(num1);
}


void
on_button12_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *jour1;
GtkWidget *mois1;
GtkWidget *annee1;
GtkWidget *heure1;
GtkWidget *num1;



jour1=lookup_widget(objet_graphique,"jour1");
mois1=lookup_widget(objet_graphique,"mois1");
annee1=lookup_widget(objet_graphique,"annee1");
heure1=lookup_widget(objet_graphique,"heure1");
num1=lookup_widget(objet_graphique,"num1");
 
jour1=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (jour1));
mois1=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (mois1));
annee1=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (annee1));
heure1=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (heure1));
num1=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (num1));
modif(num1,heure1,jour1,mois1,annee1);

}


void
on_button13_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{GtkWidget *window3;
GtkWidget *window5;
window3=lookup_widget(objet,"window3");
gtk_widget_destroy(window3);
window5=create_window5();
gtk_widget_show(window5);


}


void
on_button14_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{GtkWidget *window1;
GtkWidget *window4;
window4=lookup_widget(objet,"window4");
gtk_widget_destroy(window4);
window1=create_window1();
gtk_widget_show(window1);

}


void
on_button15_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{GtkWidget *window1;
GtkWidget *window5;
window5=lookup_widget(objet,"window5");
gtk_widget_destroy(window5);
window1=create_window1();
gtk_widget_show(window1);

}


void
on_button16_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{GtkWidget *window3;
GtkWidget *window6;
GtkWidget *treeview1;
window6=lookup_widget(objet,"window6");
gtk_widget_destroy(window6);
window3=create_window3();
gtk_widget_show(window3);
treeview1=lookup_widget(window3,"treeview1");
afficher(treeview1);

}


void
on_button17_clicked                    (GtkWidget *objet,
                                        gpointer         user_data)
{GtkWidget *window7;
GtkWidget *window3;
GtkWidget *treeview1;
window7=lookup_widget(objet,"window7");
gtk_widget_destroy(window7);
window3=create_window3();
gtk_widget_show(window3);
treeview1=lookup_widget(window3,"treeview1");
afficher(treeview1);

}


void
on_button19_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{GtkWidget *window11;
GtkWidget *window8;
window8=lookup_widget(objet,"window8");
gtk_widget_destroy(window8);
window11=create_window11();
gtk_widget_show(window11);

}


void
on_button20_clicked                    (GtkWidget *objet,
                                        gpointer         user_data)
{GtkWidget *window10;
GtkWidget *window8;
window8=lookup_widget(objet,"window8");
gtk_widget_destroy(window8);
window10=create_window10();
gtk_widget_show(window10);

}


void
on_button21_clicked                    (GtkWidget *objet,
                                        gpointer         user_data)
{GtkWidget *window4;
GtkWidget *window8;
window8=lookup_widget(objet,"window8");
gtk_widget_destroy(window8);
window4=create_window4();
gtk_widget_show(window4);

}


void
on_button18_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{GtkWidget *window4;
GtkWidget *window8;
GtkWidget *treeview2;
window4=lookup_widget(objet_graphique,"window4");
gtk_widget_destroy(window4);
window8=lookup_widget(objet_graphique,"window8");
window8=create_window8();
gtk_widget_show(window8);
treeview2=lookup_widget(window8,"treeview2");
afficherr(treeview2);
}


void
on_button8_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{dispo d;
GtkWidget *jour;
GtkWidget *mois;
GtkWidget *annee;
GtkWidget *de;
GtkWidget *a;
GtkWidget *num;
GtkWidget *window5;
GtkWidget *output;

jour=lookup_widget(objet_graphique,"jour3");
mois=lookup_widget(objet_graphique,"mois3");
annee=lookup_widget(objet_graphique,"annee3");
de=lookup_widget(objet_graphique,"de");
num=lookup_widget(objet_graphique,"num3");
a=lookup_widget(objet_graphique,"a");
output=lookup_widget(objet_graphique,"label62");
 
d.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (jour));
d.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (mois));
d.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (annee));
d.de=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (de));
d.num=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (num));
d.a=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (a));
if (verif(d.num)==0)
ajouter(d);
else gtk_label_set_text(GTK_LABEL(output),"num existe déja");

}


void
on_button22_clicked                    (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{GtkWidget *window6;
GtkWidget *num1;

num1=lookup_widget(objet_graphique,"num3");
num1=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (num1));
supprime(num1);

}


void
on_button23_activate                   (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button24_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{GtkWidget *window11;
GtkWidget *window8;
GtkWidget *treeview2;
window11=lookup_widget(objet,"window11");
gtk_widget_destroy(window11);
window8=create_window8();
gtk_widget_show(window8);
treeview2=lookup_widget(window8,"treeview2");
afficherr(treeview2);

}


void
on_button23_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{GtkWidget *jour1;
GtkWidget *mois1;
GtkWidget *annee1;
GtkWidget *de1;
GtkWidget *a1;
GtkWidget *num1;
int jour2,mois2,annee2,de2,a2,num2;


jour1=lookup_widget(objet_graphique,"jour4");
mois1=lookup_widget(objet_graphique,"mois4");
annee1=lookup_widget(objet_graphique,"annee4");
de1=lookup_widget(objet_graphique,"de4");
a1=lookup_widget(objet_graphique,"a4");
num1=lookup_widget(objet_graphique,"num4");
 
jour2=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (jour1));
mois2=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (mois1));
annee2=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (annee1));
de2=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (de1));
a2=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (a1));
num2=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (num1));
modife(num2,de2,a2,jour2,mois2,annee2);

}


void
on_button25_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{GtkWidget *window1;
GtkWidget *window2;
GtkWidget *treeview2;
window2=lookup_widget(objet,"window2");
gtk_widget_destroy(window2);
window1=create_window1();
gtk_widget_show(window1);

}


void
on_button26_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{GtkWidget *window10;
GtkWidget *window8;
GtkWidget *treeview2;
window10=lookup_widget(objet,"window10");
gtk_widget_destroy(window10);
window8=create_window8();
gtk_widget_show(window8);
treeview2=lookup_widget(window8,"treeview2");
afficherr(treeview2);
}




void
on_valider105_clicked                    (GtkWidget       *valider105,
                                        gpointer         user_data)

{
GtkWidget *input1,*input2;
GtkWidget *output; 
char logi[20]; 
char passwor[20]; 

GtkWidget *window12; 
GtkWidget *window1; 
window1 = create_window1 ();
input1=lookup_widget(valider105,"entry1"); 
input2=lookup_widget(valider105,"entry2"); 
output=lookup_widget(valider105,"label200"); 
strcpy(logi,gtk_entry_get_text(GTK_ENTRY(input1))); 
strcpy(passwor,gtk_entry_get_text(GTK_ENTRY(input2)));
int x=verifier(logi,passwor);
if (x==-1) 
{ 
gtk_label_set_text(GTK_LABEL(output),"error d'ithentification");
 }
else 
{ gtk_widget_hide(GTK_WIDGET(lookup_widget(valider105,"window12"))); gtk_widget_show(window1); }
}


void
on_button501_clicked                   (GtkWidget       *button501,
                                        gpointer         user_data)
{
GtkWidget *window12;
GtkWidget *window1;
window12=create_window12();
gtk_widget_show(window12);
gtk_widget_hide(GTK_WIDGET(lookup_widget(button501,"window1")));
}

