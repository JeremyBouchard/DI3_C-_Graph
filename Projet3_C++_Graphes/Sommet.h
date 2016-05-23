#ifndef CSOMMET_H
#define CSOMMET_H

#include "Arc.h"
#include "Exception.h"
#include "stdlib.h"
#include <new>


#define ERREUR_ALLOCATION_MEMOIRE_SIMPLE 1
#define ERREUR_ALLOCATION_MEMOIRE_OBJET 2
#define ARC_DEJA_EXISTANT 5
#define ARC_INEXISTANT 6

class CSommet	
{

//Attributes
private :
	int uiSOMNumero;
	unsigned int uiSOMNbArcEntrant;
	unsigned int uiSOMNbArcSortant;
	CArc** ppARCSOMEntrant;
	CArc** ppARCSOMSortant;

//Constructeurs et destructeur
public:
	CSommet(int uiNumero);
	CSommet(CSommet & SOMParam);

	~CSommet(void);

//Methodes
public:
	int SOMLireNumero(){return uiSOMNumero;}
	unsigned int SOMLireNbArcEntrant(){return uiSOMNbArcEntrant;}
	unsigned int SOMLireNbArcSortant(){return uiSOMNbArcSortant;}
	CArc** SOMLireArcEntrant(){return ppARCSOMEntrant;}
	CArc** SOMLireArcSortant(){return ppARCSOMSortant;}
	void SOMModifierArcEntrant(CArc** ppARCParam, unsigned int uiNbArc);
	void SOMModifierArcSortant(CArc** ppARCParam, unsigned int uiNbArc);

	void SOMModifierNumero(int uiNumero){uiSOMNumero=uiNumero;}
	void SOMAjouterArcSortant(int uiDestination, float fPoids);
	void SOMAjouterArcSortant(CArc & ARCParam);
	void SOMAjouterArcEntrant(int uiDestination, float fPoids);
	void SOMAjouterArcEntrant(CArc & ARCParam);
	void SOMSupprimerArcEntrant(int uiDestination);
	void SOMSupprimerArcEntrant(CArc & ARCParam);
	void SOMSupprimerArcSortant(CArc & ARCParam);
	void SOMSupprimerArcSortant(int uiDestination);
	
	CArc * SOMTrouverArcSortant(int uiDestiation);
	//int SOMTrouver
	CArc * SOMTrouverArcEntrant(int uiDestination);

	CSommet & operator= (CSommet& SOMParam);
};

#endif