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


