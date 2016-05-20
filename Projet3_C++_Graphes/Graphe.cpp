#include "Graphe.h"

CGraphe::CGraphe(void)
{
	uiGRANbSommet=0;
	ppSOMGRASommet=NULL;
}

CGraphe::CGraphe(CGraphe &GRAParam)
{
	unsigned int uiBoucle;
	uiGRANbSommet=0;

	if (GRAParam.uiGRANbSommet>0)
	{
		ppSOMGRASommet=(CSommet **)malloc(GRAParam.uiGRANbSommet*sizeof(CSommet *));
		if (ppSOMGRASommet ==NULL)throw CException(ERREUR_ALLOCATION_MEMOIRE_SIMPLE);

		for (uiBoucle=0;uiBoucle<GRAParam.uiGRANbSommet;uiBoucle++)
		{
			try{
				ppSOMGRASommet[uiBoucle]=new CSommet(*GRAParam.ppSOMGRASommet[uiBoucle]);
			}catch(std::bad_alloc){
				throw CException(ERREUR_ALLOCATION_MEMOIRE_OBJET);
			}
		}
	}
	else
		ppSOMGRASommet=NULL;

	uiGRANbSommet=GRAParam.uiGRANbSommet;
}

CGraphe::~CGraphe(void)
{
	unsigned int uiBoucleSommet;

	for (uiBoucleSommet=0; uiBoucleSommet<uiGRANbSommet;uiBoucleSommet++){
		delete(ppSOMGRASommet[uiBoucleSommet]);
	}

	free(ppSOMGRASommet);
}

void CGraphe::GRAModifierTabSommet(CSommet ** ppSOMParam, unsigned int uiNbSommet){
	uiGRANbSommet=uiNbSommet;
	ppSOMGRASommet=ppSOMParam;
}

void CGraphe::GRAAjouterArc(int uiOrigine,int uiDestination)
{
	CSommet * ppSommet1, * ppSommet2;
	unsigned int uiBoucle=0;

	ppSommet1=GRATrouverSommet(uiOrigine);
	ppSommet2=GRATrouverSommet(uiDestination);

	if(ppSommet1==NULL || ppSommet2==NULL) throw CException(SOMMET_INEXISTANT);

	try{
		ppSommet1->SOMAjouterArcSortant(uiDestination);//uidestination=ppSommet2->LireNumero()
		ppSommet2->SOMAjouterArcEntrant(uiOrigine);//uiOrigine=ppSommet1->LireNumero()
	}catch(CException e){
		throw e;
	}
}

void CGraphe::GRAASupprimerArc(int uiOrigine,int uiDestination)
{
	CSommet * ppSommet1, * ppSommet2;
	unsigned int uiBoucle=0;

	ppSommet1=GRATrouverSommet(uiOrigine);
	ppSommet2=GRATrouverSommet(uiDestination);

	if(ppSommet1==NULL || ppSommet2==NULL) throw CException(SOMMET_INEXISTANT);

	try{
		ppSommet1->SOMSupprimerArcSortant(uiDestination);//uidestination=ppSommet2->LireNumero()
		ppSommet2->SOMSupprimerArcEntrant(uiOrigine);//uiOrigine=ppSommet1->LireNumero()
	}catch(CException){
		throw;
	}
}

void CGraphe::GRAAjouterSommet(int uiNumero)
{
	if(GRATrouverSommet(uiNumero) != NULL)throw CException(SOMMET_DEJA_EXISTANT);
	CSommet * SOMNouveauSommet;

	try{
		SOMNouveauSommet=new CSommet(uiNumero);
	}catch(std::bad_alloc){
		throw CException(ERREUR_ALLOCATION_MEMOIRE_OBJET);
	}
	GRAAjouterSommet(*SOMNouveauSommet);
}

void CGraphe::GRAAjouterSommet(CSommet & SOMParam)
{
	CSommet** ppSOMTmp;
	if(GRATrouverSommet(SOMParam.SOMLireNumero()) != NULL)throw CException(SOMMET_DEJA_EXISTANT);

	ppSOMTmp=(CSommet **)realloc(ppSOMGRASommet, (uiGRANbSommet+1)*sizeof(CSommet *));
	if(ppSOMTmp == NULL) throw CException(ERREUR_ALLOCATION_MEMOIRE_SIMPLE);
	ppSOMGRASommet=ppSOMTmp;
	ppSOMGRASommet[uiGRANbSommet]=&SOMParam;
	uiGRANbSommet++;
}

void CGraphe::GRASupprimerSommet(int uiNumero)
{
	GRASupprimerSommet(*GRATrouverSommet(uiNumero));
}

void CGraphe::GRASupprimerSommet(CSommet & SOMParam){
	unsigned int uiBoucle;
	unsigned int uiNbEntrant, uiNbSortant;
	int iNumeroTmp;
	int iNumeroParam = SOMParam.SOMLireNumero();
	bool bDeplacer=false;

	uiNbEntrant=SOMParam.SOMLireNbArcEntrant();
	uiNbSortant=SOMParam.SOMLireNbArcSortant();

	for (uiBoucle=0 ; uiBoucle<uiNbEntrant; uiBoucle++){
		iNumeroTmp=SOMParam.SOMLireArcEntrant()[uiBoucle]->ARCLireDestination();
		GRATrouverSommet(iNumeroTmp)->SOMSupprimerArcSortant(iNumeroParam);
	}

	for (uiBoucle=0 ; uiBoucle<uiNbSortant; uiBoucle++){
		iNumeroTmp=SOMParam.SOMLireArcSortant()[uiBoucle]->ARCLireDestination();
		GRATrouverSommet(iNumeroTmp)->SOMSupprimerArcEntrant(iNumeroParam);
	}


	for(uiBoucle=0;uiBoucle<uiGRANbSommet;uiBoucle++){
		if(ppSOMGRASommet[uiBoucle] == &SOMParam){
			delete &SOMParam;
			bDeplacer=true;
		}
		if(bDeplacer && uiBoucle<uiGRANbSommet-1){
			ppSOMGRASommet[uiBoucle]=ppSOMGRASommet[uiBoucle+1];//"Deplacement" de l'element suivant a la place de l'element courant par copie du pointeur
		}
	}
	if(!bDeplacer)throw CException(SOMMET_INEXISTANT);
	uiGRANbSommet--;//Décrémentation utile pour le realloc
	ppSOMGRASommet=(CSommet**)realloc(ppSOMGRASommet,uiGRANbSommet*sizeof(CArc*));//Diminution de la taille du tableau de pointeur

}

CSommet * CGraphe::GRATrouverSommet( int uiNumero){
	CSommet * pSommet1;
	unsigned int uiBoucle;

	for (uiBoucle=0;uiBoucle<uiGRANbSommet;uiBoucle++){ //Faire pointer ppSommet1 sur le sommet s'il existe
		pSommet1=ppSOMGRASommet[uiBoucle];
		if (pSommet1->SOMLireNumero()==uiNumero){
			return pSommet1;
		}
	}
	return NULL;
}

void CGraphe::GRAAfficher(){

	unsigned int uiBoucleLigne, uiBoucleColonne;
	bool bLigne=false;

	if(uiGRANbSommet!=0){

		std::cout << "Matrice des arcs (source en ligne et destination en colonne) : \n";
		std::cout<< std::setw(13);
		std::cout<<"SRC -> DEST||";
		for(uiBoucleColonne=0; uiBoucleColonne<uiGRANbSommet; uiBoucleColonne++){
			std::cout<< std::setw(11);
			std::cout<<ppSOMGRASommet[uiBoucleColonne]->SOMLireNumero()<<"|";
		}

		std::cout<< std::endl<<"===========||";
		for(uiBoucleColonne=0; uiBoucleColonne<uiGRANbSommet; uiBoucleColonne++){
			std::cout<< std::setw(12);
			std::cout<<"===========|";
		}
		std::cout<<std::endl;
		for(uiBoucleLigne=0; uiBoucleLigne<uiGRANbSommet; uiBoucleLigne++){
			if(!bLigne){
				bLigne=true;
				for(uiBoucleColonne=0; uiBoucleColonne<uiGRANbSommet;uiBoucleColonne++){
					if(uiBoucleColonne ==0){
						std::cout<<std::setw(11);
						std::cout<<ppSOMGRASommet[uiBoucleLigne]->SOMLireNumero()<<"||";
					}
					if(ppSOMGRASommet[uiBoucleLigne]->SOMTrouverArcSortant(ppSOMGRASommet[uiBoucleColonne]->SOMLireNumero()) != NULL){
						std::cout<< std::setw(12);
						std::cout<<"OK|";
					}else{
						std::cout<< std::setw(12);
						std::cout<<"|";
					}
				}
			}else{
				bLigne=false;
				std::cout<< std::setw(12);
				std::cout<<"___________||";
				for(uiBoucleColonne=0; uiBoucleColonne<uiGRANbSommet; uiBoucleColonne++){
					std::cout<< std::setw(12);
					std::cout<<"___________|";
				}
				uiBoucleLigne--;
			}
			std::cout<<std::endl;
		}
		std::cout<<std::endl<<std::endl;
	}else{
		std::cout<<"Le graphe ne contient pas de sommet\n";
	}
}



CGraphe& CGraphe::operator=(CGraphe& GRAParam){
	unsigned int uiBoucle;
	uiGRANbSommet=0;

	for (uiBoucle=0; uiBoucle<uiGRANbSommet;uiBoucle++){
		delete(ppSOMGRASommet[uiBoucle]);
	}
	free(ppSOMGRASommet);

	ppSOMGRASommet=(CSommet **)malloc(GRAParam.uiGRANbSommet*sizeof(CSommet *));
	if (ppSOMGRASommet ==NULL)throw CException(ERREUR_ALLOCATION_MEMOIRE_SIMPLE);

	if (GRAParam.uiGRANbSommet>0)
	{
		for (uiBoucle=0;uiBoucle<GRAParam.uiGRANbSommet;uiBoucle++)
		{
			try{
				ppSOMGRASommet[uiBoucle]=new CSommet(*GRAParam.ppSOMGRASommet[uiBoucle]);
			}catch(std::bad_alloc){
				throw CException(ERREUR_ALLOCATION_MEMOIRE_OBJET);
			}
		}
	}
	else
		ppSOMGRASommet=NULL;

	uiGRANbSommet=GRAParam.uiGRANbSommet;

	return *this;
}
