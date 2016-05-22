#ifndef CTRAITEMENTGRAPHE_H
#define CTRAITEMENTGRAPHE_H

#include "Graphe.h"
#include "Sommet.h"
#include "Arc.h"
#include "Exception.h"


class CTraitementGraphe
{
public:
	CGraphe & TGRInversionGraphe(CGraphe & GRAParam);
	int* TGRBellmanFord (CGraphe & GRAParam, int SOMSource, int* iDistance);
};

#endif