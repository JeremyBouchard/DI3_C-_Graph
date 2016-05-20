#ifndef CGRAPHE_H
#define CGRAPHE_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include "Sommet.h"
#include "Exception.h"
#include <new>          // std::bad_alloc

//Definition des valeurs pour chaque exception

#define ERREUR_ALLOCATION_MEMOIRE_SIMPLE 1
#define ERREUR_ALLOCATION_MEMOIRE_OBJET 2
#define SOMMET_DEJA_EXISTANT 3
#define SOMMET_INEXISTANT 4

class CGraphe
{
private:
	CSommet ** ppSOMGRASommet;
	unsigned int uiGRANbSommet;

public:
	CGraphe();
	CGraphe(CGraphe &GRAParam);
	CGraphe(CSommet** ppSOMSommet, unsigned int uiNbSommet);
	~CGraphe(void);

	void GRAModifierTabSommet(CSommet ** ppSOMParam, unsigned int uiGRANbSommet);
    unsigned int GRALireNbSommet(){return uiGRANbSommet;}
	CSommet ** GRALireTabSommet(){return ppSOMGRASommet;}

	void GRAAjouterArc(int uiOrigine, int uiDestination);
	void GRAAjouterArc(CArc & ARCParam);
	void GRAASupprimerArc(int uiOrigine, int uiDestination);
	void GRAAjouterSommet(int uiNumero);
	void GRAAjouterSommet(CSommet & SOMParam);
	void GRASupprimerSommet(int uiNumero);
	void GRASupprimerSommet(CSommet & SOMParam);

	CSommet* GRATrouverSommet(int uiNumero);
	unsigned int GRANombreARC();

	void GRAAfficher();

	CGraphe& operator= (CGraphe& GRAParam);
};

#endif
