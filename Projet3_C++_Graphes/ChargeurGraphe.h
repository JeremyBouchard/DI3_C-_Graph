#ifndef CCHARGEURGRAPHE_H
#define CCHARGEURGRAPHE_H

#include "Graphe.h"
#include "Parseur.h"
#include <string.h>
#include <stdlib.h>

class CChargeurGraphe{

public:
	CChargeurGraphe();
	CGraphe * CGRLireFichier(char * pcChemin);

};

#endif
