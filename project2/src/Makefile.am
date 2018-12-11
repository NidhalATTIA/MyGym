## Process this file with automake to produce Makefile.in

INCLUDES = \
	-DPACKAGE_DATA_DIR=\""$(datadir)"\" \
	-DPACKAGE_LOCALE_DIR=\""$(prefix)/$(DATADIRNAME)/locale"\" \
	@PACKAGE_CFLAGS@

bin_PROGRAMS = project2

project2_SOURCES = \
	main.c \
	support.c support.h \
	interface.c interface.h \
	callbacks.c callbacks.h \
        verifier.c verifier.h \
        personne.c personne.h \
        ajout.c    ajout.h \
        supprimer.c supprimer.h \
        modifier.c modifier.h \
        coordonner.c coordonner.h \
        ok.c      ok.h \
        suppdispo.c  suppdispo.h

project2_LDADD = @PACKAGE_LIBS@ $(INTLLIBS)

