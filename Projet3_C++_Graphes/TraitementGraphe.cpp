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

float* CTraitementGraphe::TGRBellmanFord (CGraphe & GRAParam, int iSource){
	
	unsigned int uiNbSommet=GRAParam.GRALireNbSommet();
	unsigned int uiIndiceSommet = GRAParam.GRATrouverIndiceSommet(iSource);
	CSommet** TabSommet = GRAParam.GRALireTabSommet();

	unsigned int uiBoucleSuiteSommet, uiBoucleSommet, uiBoucleArc; 

	int * P = new int[uiNbSommet];
	float * piDistance = new float[uiNbSommet];

	bool bPoidsInchange;
	float longueur;
	int iDestination;
	unsigned iIndiceDestination;
	
	for (uiBoucleSommet=0 ; uiBoucleSommet < uiNbSommet; uiBoucleSommet++){
		piDistance[uiBoucleSommet]=FLT_MAX;
		P[uiBoucleSommet]=-1;
	}
	piDistance[uiIndiceSommet]=0;
	P[uiIndiceSommet]=0;


	for(uiBoucleSuiteSommet=1 ; uiBoucleSuiteSommet < uiNbSommet; uiBoucleSuiteSommet++){
		bPoidsInchange=true;

		for (uiBoucleSommet=0 ; uiBoucleSommet < uiNbSommet; uiBoucleSommet++){

			if (P[uiBoucleSommet] == uiBoucleSuiteSommet-1){ 

				for (uiBoucleArc=0; uiBoucleArc < TabSommet[uiBoucleSommet]->SOMLireNbArcSortant() ; uiBoucleArc++){
					
					longueur = piDistance[uiBoucleSommet] + TabSommet[uiBoucleSommet]->SOMLireArcSortant()[uiBoucleArc]->ARCLirePoids();
					iDestination = TabSommet[uiBoucleSommet]->SOMLireArcSortant()[uiBoucleArc]->ARCLireDestination();
					iIndiceDestination = GRAParam.GRATrouverIndiceSommet(iDestination);

					if (longueur < piDistance[iIndiceDestination] ){
						piDistance[iIndiceDestination]=longueur;
						bPoidsInchange=false;
						P[iIndiceDestination]=uiBoucleSuiteSommet;
					}		
				}
			}
		}
		if(bPoidsInchange){
			break;
		}
	}

	for (uiBoucleSommet=0 ; uiBoucleSommet < uiNbSommet; uiBoucleSommet++){
		for (uiBoucleArc=0; uiBoucleArc < TabSommet[uiBoucleSommet]->SOMLireNbArcSortant() ; uiBoucleArc++){
		
			longueur = TabSommet[uiBoucleSommet]->SOMLireArcSortant()[uiBoucleArc]->ARCLirePoids();
			iDestination = TabSommet[uiBoucleSommet]->SOMLireArcSortant()[uiBoucleArc]->ARCLireDestination();
			iIndiceDestination = GRAParam.GRATrouverIndiceSommet(iDestination);

			if (piDistance[uiBoucleSommet] + longueur < piDistance[iIndiceDestination] ){
				throw CException(CYCLE_ABSORBANT);
			}
		}
	}

	return piDistance;
}
