#include "ChargeurGraphe.h"

CChargeurGraphe::CChargeurGraphe(){
;
}


CGraphe * CChargeurGraphe::CGRLireFichier(char * pcChemin){
	CParseur PARParseur(pcChemin);
	CGraphe * GRAResultat = new CGraphe();
	unsigned int NbSommet, NbArc, uiBoucle, NumeroTmp1, NumeroTmp2;
	float iPoids;
	
	PARParseur.PARLireLigne();
	NbSommet=std::atoi(PARParseur.PARLireValeur());

	PARParseur.PARLireLigne();
	NbArc=std::atoi(PARParseur.PARLireValeur());

	PARParseur.PARLireLigne();

	for (uiBoucle=0;uiBoucle<NbSommet;uiBoucle++){
		PARParseur.PARLireLigne();
		NumeroTmp1=std::atoi(PARParseur.PARLireValeur());
		GRAResultat->GRAAjouterSommet(NumeroTmp1);
	}

	PARParseur.PARLireLigne();
	//PARParseur.PARLireLigne();

	for (uiBoucle=0;uiBoucle<NbArc;uiBoucle++){
		PARParseur.PARLireLigne();
		NumeroTmp1=std::atoi(PARParseur.PARLireValeur());
		PARParseur.PARLireLigne();
		NumeroTmp2=std::atoi(PARParseur.PARLireValeur());
		PARParseur.PARLireLigne();
		iPoids=(float)std::atof(PARParseur.PARLireValeur());
		GRAResultat->GRAAjouterArc(NumeroTmp1,NumeroTmp2,iPoids);
	}

	return GRAResultat;
}