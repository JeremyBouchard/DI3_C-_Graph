
#include "Arc.h"


CArc::CArc(int uiDestination, float fPoids){
	uiARCDestination=uiDestination;
	fARCPoids=fPoids;
}

CArc::CArc(CArc & ARCParam){
	uiARCDestination=ARCParam.uiARCDestination;
	fARCPoids=ARCParam.fARCPoids;
}
CArc::~CArc(void)
{
}

