
#include "Sommet.h"


CSommet::CSommet(int uiNumero){
	uiSOMNumero=uiNumero;
	uiSOMNbArcEntrant=0;
	uiSOMNbArcSortant=0;
	//Mise a NULL explicite des pointeurs sur les arcs
	ppARCSOMEntrant=NULL; 
	ppARCSOMSortant=NULL;
}

CSommet::CSommet(CSommet & SOMParam){
	unsigned int uiBoucle;
	uiSOMNumero=SOMParam.uiSOMNumero;


	if (SOMParam.uiSOMNbArcEntrant>0){//Traitement inutile si aucun sommet Entrant dans le sommet parametre
		ppARCSOMEntrant=(CArc**)malloc(SOMParam.uiSOMNbArcEntrant*sizeof(CArc*));//allocation dynamique d'un tableau de pointeur pour les arcs entrant
		if (ppARCSOMEntrant ==NULL)throw CException(ERREUR_ALLOCATION_MEMOIRE_SIMPLE);

		for (uiBoucle=0; uiBoucle<SOMParam.uiSOMNbArcEntrant;uiBoucle++){//Pour chaque sommet entrant du sommet parametre
			try{
				ppARCSOMEntrant[uiBoucle]= new CArc(*SOMParam.ppARCSOMEntrant[uiBoucle]);//Creation du nouvelle arc par constructeur de recopie
			}catch(const std::bad_alloc){
				throw CException(ERREUR_ALLOCATION_MEMOIRE_OBJET);
			}
		}
	}
	else
		ppARCSOMEntrant=NULL;//Initialisation explicite a NULL si aucun arc entrant

	uiSOMNbArcEntrant=SOMParam.uiSOMNbArcEntrant;

	if (SOMParam.uiSOMNbArcSortant>0){
		ppARCSOMSortant=(CArc**)malloc(SOMParam.uiSOMNbArcSortant*sizeof(CArc*));//allocation dynamique d'un tableau de pointeur pour les arcs sortant
		if (ppARCSOMSortant ==NULL)throw CException(ERREUR_ALLOCATION_MEMOIRE_SIMPLE);

		for (uiBoucle=0; uiBoucle<SOMParam.uiSOMNbArcSortant;uiBoucle++){//Pour chaque sommet sortant du sommet parametre
			try{
				ppARCSOMSortant[uiBoucle]= new CArc(*SOMParam.ppARCSOMSortant[uiBoucle]);//Creation du nouvelle arc par constructeur de recopie
			}catch(std::bad_alloc){
				throw CException(ERREUR_ALLOCATION_MEMOIRE_OBJET);
			}
		}
	}
	else
		ppARCSOMSortant=NULL;//Initialisation explicite a NULL si aucun arc sortant

	uiSOMNbArcSortant=SOMParam.uiSOMNbArcSortant;
}

CSommet::~CSommet(void)
{
	unsigned int uiBoucleArc;

	for (uiBoucleArc=0; uiBoucleArc<uiSOMNbArcEntrant;uiBoucleArc++){//Desalocation de chaque arc entrant
		delete(ppARCSOMEntrant[uiBoucleArc]);
	}

	for (uiBoucleArc=0; uiBoucleArc<uiSOMNbArcSortant;uiBoucleArc++){//Desalocation de chaque arc sortant
		delete(ppARCSOMSortant[uiBoucleArc]);
	}

	//Desalocation des tableau de pointeur
	free(ppARCSOMEntrant);
	free(ppARCSOMSortant);
}

void CSommet::SOMModifierArcEntrant(CArc** ppARCParam, unsigned int uiNbArc){
	ppARCSOMEntrant=ppARCParam;
	uiSOMNbArcEntrant=uiNbArc;
}

void CSommet::SOMModifierArcSortant(CArc** ppARCParam, unsigned int uiNbArc){
	ppARCSOMSortant=ppARCParam;
	uiSOMNbArcSortant=uiNbArc;
}

void CSommet::SOMAjouterArcEntrant(int uiDestination, float fPoids){
	CArc* ARCNouvelArc ;

	try{
		ARCNouvelArc = new CArc(uiDestination, fPoids);
	}catch(std::bad_alloc){
		throw CException(ERREUR_ALLOCATION_MEMOIRE_OBJET);
	}

	SOMAjouterArcEntrant(*ARCNouvelArc); //Appel à une version surchargee prenant en parametre le nouvel ARC 
}

void CSommet::SOMAjouterArcEntrant(CArc & ARCParam){
	CArc ** ARCTmp; //Tampon realloc

	if(SOMTrouverArcEntrant(ARCParam.ARCLireDestination()) != NULL){//Vrai s'il existe deja un ARC entrant avec cette destination (pointeur retourné non null)
		throw CException(ARC_DEJA_EXISTANT);
	}

	ARCTmp=(CArc**)realloc(ppARCSOMEntrant,(uiSOMNbArcEntrant+1)*sizeof(CArc*));//
	if(ARCTmp == NULL) throw CException(ERREUR_ALLOCATION_MEMOIRE_SIMPLE);
	ppARCSOMEntrant=ARCTmp;

	ppARCSOMEntrant[uiSOMNbArcEntrant]=&ARCParam;
	uiSOMNbArcEntrant++;

}

void CSommet::SOMAjouterArcSortant(int uiDestination, float fPoids){
	CArc* pARCNouvelArc;

	try{
		pARCNouvelArc = new CArc(uiDestination,fPoids);
	}catch(std::bad_alloc){
		throw CException(ERREUR_ALLOCATION_MEMOIRE_OBJET);
	}

	SOMAjouterArcSortant(*pARCNouvelArc); //Appel a une version surchargee prenant en parametre le nouvel ARC 

}

void CSommet::SOMAjouterArcSortant(CArc & ARCParam){

	CArc ** ARCTmp; //Tampon realloc
	if(SOMTrouverArcSortant(ARCParam.ARCLireDestination()) != NULL){//Vrai s'il existe deja un ARC sortant avec cette destination (pointeur retourné non null)
		throw CException(ARC_DEJA_EXISTANT);
	}

	ARCTmp=(CArc**)realloc(ppARCSOMSortant,(uiSOMNbArcSortant+1)*sizeof(CArc*));
	if(ARCTmp == NULL) throw CException(ERREUR_ALLOCATION_MEMOIRE_SIMPLE);
	ppARCSOMSortant=ARCTmp;

	ppARCSOMSortant[uiSOMNbArcSortant]=&ARCParam;//Ajout du nouvelle arc en fin de tableau
	uiSOMNbArcSortant++;
}


void CSommet::SOMSupprimerArcEntrant(int uiDestination){

	SOMSupprimerArcEntrant(*SOMTrouverArcEntrant(uiDestination));
}

void CSommet::SOMSupprimerArcEntrant(CArc & ARCParam){
	bool bDeplacer=false;
	unsigned int uiBoucle;

	for(uiBoucle=0;uiBoucle<uiSOMNbArcEntrant;uiBoucle++){
		if(ppARCSOMEntrant[uiBoucle] == &ARCParam){
			delete &ARCParam;
			bDeplacer=true;
		}

		if(bDeplacer && uiBoucle<uiSOMNbArcEntrant-1){
			ppARCSOMEntrant[uiBoucle]=ppARCSOMEntrant[uiBoucle+1];//"Deplacement" de l'element suivant a la place de l'element courant par copie du pointeur
		}
	}
	if(!bDeplacer)throw CException(ARC_INEXISTANT);

	uiSOMNbArcEntrant--;//Décrémentation utile pour le realloc
	ppARCSOMEntrant=(CArc**)realloc(ppARCSOMEntrant,uiSOMNbArcEntrant*sizeof(CArc*));//Diminution de la taille du tableau de pointeur
}

void CSommet::SOMSupprimerArcSortant(CArc & ARCParam){
	bool bDeplacer=false;
	unsigned int uiBoucle;

	for(uiBoucle=0;uiBoucle<uiSOMNbArcSortant;uiBoucle++){
		if(ppARCSOMSortant[uiBoucle] == &ARCParam){
			delete &ARCParam;
			bDeplacer=true;
		}

		if(bDeplacer && uiBoucle<uiSOMNbArcSortant-1){
			ppARCSOMSortant[uiBoucle]=ppARCSOMSortant[uiBoucle+1];//"Deplacement" de l'element suivant a la place de l'element courant par copie du pointeur
		}
	}
	if(!bDeplacer)throw CException(ARC_INEXISTANT);

	uiSOMNbArcSortant--;//Décrémentation utile pour le realloc
	ppARCSOMSortant=(CArc**)realloc(ppARCSOMSortant,uiSOMNbArcSortant*sizeof(CArc*));//Diminution de la taille du tableau de pointeur
}

void CSommet::SOMSupprimerArcSortant(int uiDestination){
	unsigned int uiBoucle;
	bool bDeplacer=false;

	CArc * pARCASupprimer = SOMTrouverArcSortant(uiDestination);

	if(pARCASupprimer != NULL){

		delete pARCASupprimer;

		for(uiBoucle=0;uiBoucle<uiSOMNbArcSortant-1;uiBoucle++){
			if(ppARCSOMSortant[uiBoucle] == NULL || bDeplacer){
				ppARCSOMSortant[uiBoucle]=ppARCSOMSortant[uiBoucle+1];//"Deplacement" de l'element suivant a la place de l'element courant par copie du pointeur
				bDeplacer=true;
			}
		}
		uiSOMNbArcSortant--;//Décrémentation utile pour le realloc
		ppARCSOMSortant=(CArc**)realloc(ppARCSOMSortant,uiSOMNbArcSortant*sizeof(CArc*));//Diminution de la taille du tableau de pointeur

	}else{
		throw CException(ARC_INEXISTANT);
	}
	
}

CArc * CSommet::SOMTrouverArcEntrant(int uiDestination){
	CArc * pArc1;
	unsigned int uiBoucle;

	for (uiBoucle=0;uiBoucle<uiSOMNbArcEntrant;uiBoucle++){ //Faire pointer ppArc1 sur l'arc s'il existe
		pArc1=ppARCSOMEntrant[uiBoucle];
		if (pArc1->ARCLireDestination()==uiDestination){
			return pArc1;
		}
	}
	return NULL;
}

int CSommet::SOMTrouverIndiceArcEntrant(int uiDestination){
	unsigned int uiBoucle;

	for (uiBoucle=0;uiBoucle<uiSOMNbArcEntrant;uiBoucle++){ 
		
		if (ppARCSOMEntrant[uiBoucle]->ARCLireDestination()== uiDestination){
			return uiBoucle;
		}
	}
	return -1;

}

CArc * CSommet::SOMTrouverArcSortant(int uiDestination){
	CArc * pArc1;
	unsigned int uiBoucle;

	for (uiBoucle=0;uiBoucle<uiSOMNbArcSortant;uiBoucle++){ //Faire pointer ppArc1 sur l'arc s'il existe
		pArc1=ppARCSOMSortant[uiBoucle];
		if (pArc1->ARCLireDestination()==uiDestination){
			return pArc1;
		}
	}
	return NULL;
}

int CSommet::SOMTrouverIndiceArcSortant(int uiDestination){
	unsigned int uiBoucle;

	for (uiBoucle=0;uiBoucle<uiSOMNbArcEntrant;uiBoucle++){ 
		
		if (ppARCSOMSortant[uiBoucle]->ARCLireDestination()== uiDestination){
			return uiBoucle;
		}
	}
	return -1;

}

CSommet & CSommet::operator= (CSommet& SOMParam){
	unsigned int uiBoucleArc;

	for (uiBoucleArc=0; uiBoucleArc<uiSOMNbArcEntrant;uiBoucleArc++){//Desalocation de chaque arc entrant
		delete(ppARCSOMEntrant[uiBoucleArc]);
	}

	for (uiBoucleArc=0; uiBoucleArc<uiSOMNbArcSortant;uiBoucleArc++){//Desalocation de chaque arc sortant
		delete(ppARCSOMSortant[uiBoucleArc]);
	}

	//Desalocation des tableau de pointeur
	free(ppARCSOMEntrant);
	free(ppARCSOMSortant);

	unsigned int uiBoucle;
	uiSOMNumero=SOMParam.uiSOMNumero;


	if (SOMParam.uiSOMNbArcEntrant>0){//Traitement inutile si aucun sommet Entrant dans le sommet parametre
		ppARCSOMEntrant=(CArc**)malloc(SOMParam.uiSOMNbArcEntrant*sizeof(CArc*));//allocation dynamique d'un tableau de pointeur pour les arcs entrant
		if (ppARCSOMEntrant ==NULL)throw CException(ERREUR_ALLOCATION_MEMOIRE_SIMPLE);

		for (uiBoucle=0; uiBoucle<SOMParam.uiSOMNbArcEntrant;uiBoucle++){//Pour chaque sommet entrant du sommet parametre
			try{
				ppARCSOMEntrant[uiBoucle]= new CArc(*SOMParam.ppARCSOMEntrant[uiBoucle]);//Creation du nouvelle arc par constructeur de recopie
			}catch(const std::bad_alloc){
				throw CException(ERREUR_ALLOCATION_MEMOIRE_OBJET);
			}
		}
	}
	else
		ppARCSOMEntrant=NULL;//Initialisation explicite a NULL si aucun arc entrant

	uiSOMNbArcEntrant=SOMParam.uiSOMNbArcEntrant;

	if (SOMParam.uiSOMNbArcSortant>0){
		ppARCSOMSortant=(CArc**)malloc(SOMParam.uiSOMNbArcSortant*sizeof(CArc*));//allocation dynamique d'un tableau de pointeur pour les arcs sortant
		if (ppARCSOMSortant ==NULL)throw CException(ERREUR_ALLOCATION_MEMOIRE_SIMPLE);

		for (uiBoucle=0; uiBoucle<SOMParam.uiSOMNbArcSortant;uiBoucle++){//Pour chaque sommet sortant du sommet parametre
			try{
				ppARCSOMSortant[uiBoucle]= new CArc(*SOMParam.ppARCSOMSortant[uiBoucle]);//Creation du nouvelle arc par constructeur de recopie
			}catch(std::bad_alloc){
				throw CException(ERREUR_ALLOCATION_MEMOIRE_OBJET);
			}
		}
	}
	else
		ppARCSOMSortant=NULL;//Initialisation explicite a NULL si aucun arc sortant

	uiSOMNbArcSortant=SOMParam.uiSOMNbArcSortant;

	return *this;
}