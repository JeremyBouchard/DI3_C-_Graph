#include "TraitementGraphe.h"

CGraphe & CTraitementGraphe::TGRInversionGraphe(CGraphe & GRAParam){
	CArc ** ppARCTmp;
	CSommet * pSOMTmp;
	unsigned int uiNbArcTmp;
	unsigned int uiBoucle;
	unsigned int uiNbSommet = GRAParam.GRALireNbSommet();
	CGraphe * GRAInverse;
	
	try{
		GRAInverse = new CGraphe(GRAParam);
	}catch(std::bad_alloc){
		throw CException(ERREUR_ALLOCATION_MEMOIRE_OBJET);
	}

	for (uiBoucle=0; uiBoucle<uiNbSommet; uiBoucle++){
		try{
			pSOMTmp=GRAInverse->GRALireTabSommet()[uiBoucle];
			ppARCTmp=pSOMTmp->SOMLireArcEntrant();
			uiNbArcTmp=pSOMTmp->SOMLireNbArcEntrant();
			pSOMTmp->SOMModifierArcEntrant(pSOMTmp->SOMLireArcSortant(),pSOMTmp->SOMLireNbArcSortant());
			pSOMTmp->SOMModifierArcSortant(ppARCTmp,uiNbArcTmp);
		}catch(CException e){
			throw e;
		}
	}

	return *GRAInverse;
}

int* CTraitementGraphe::TGRBellmanFord (CGraphe & GRAParam, int iSource, int* piDistance){
		
	//CSommet* SOMSource = GRAParam.GRATrouverSommet(iSource);
	
	unsigned int uiNbSommet=GRAParam.GRALireNbSommet();
	//unsigned int uiNbArc=GRAParam.GRANombreARC();
	CSommet** TabSommet = GRAParam.GRALireTabSommet();

	unsigned int uiBoucleSuiteSommet, uiBoucleSommet, uiBoucleArc; //TODO :enlever le =0
	int * P = new int[uiNbSommet];
	bool bPoidsInchange;
	int longueur;

	unsigned int uiIndiceSommet = GRAParam.GRATrouverIndiceSommet(iSource);
	
	
	for (uiBoucleSommet=0 ; uiBoucleSommet < uiNbSommet; uiBoucleSommet++){
		piDistance[uiBoucleSommet]=INT_MAX;
		P[uiBoucleSommet]=0;
	}
	
	piDistance[uiIndiceSommet]=0;
	P[uiIndiceSommet]=0;

	for(uiBoucleSuiteSommet=1 ; uiBoucleSuiteSommet< uiNbSommet-1; uiBoucleSuiteSommet++){
		bPoidsInchange=true;

		for (uiBoucleSommet=0 ; uiBoucleSommet< uiNbSommet; uiBoucleSommet++){

			if (P[uiBoucleSommet]=uiBoucleSuiteSommet-1){ //Si utilisé au tour precedent

				for (uiBoucleArc; uiBoucleArc<TabSommet[uiBoucleSommet]->SOMLireNbArcSortant() ; uiBoucleArc++){
					longueur = piDistance[uiBoucleSommet] + TabSommet[uiBoucleSommet]->SOMLireArcSortant()[uiBoucleArc]->ARCLirePoids();

					if (longueur < piDistance[
				}

			}

		}




	}



}
