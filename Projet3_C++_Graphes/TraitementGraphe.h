#ifndef CTRAITEMENTGRAPHE_H
#define CTRAITEMENTGRAPHE_H

#include "Graphe.h"
#include "Sommet.h"
#include "Arc.h"
#include "Exception.h"

#define CYCLE_ABSORBANT 9

class CTraitementGraphe
{
public:
	CGraphe & TGRInversionGraphe(CGraphe & GRAParam);
	float* TGRBellmanFord (CGraphe & GRAParam, int SOMSource);
};

#endif