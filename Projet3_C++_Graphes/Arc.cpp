
#include "Arc.h"


CArc::CArc(int uiDestination, int iPoids){
	uiARCDestination=uiDestination;
	iARCPoids=iPoids;
}

CArc::CArc(CArc & ARCParam){
	uiARCDestination=ARCParam.uiARCDestination;
	iARCPoids=ARCParam.iARCPoids;
}
CArc::~CArc(void)
{
}

