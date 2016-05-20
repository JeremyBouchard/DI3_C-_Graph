
#include "Arc.h"


CArc::CArc(int uiDestination){
	uiARCDestination=uiDestination;
}

CArc::CArc(CArc & ARCParam){
	uiARCDestination=ARCParam.uiARCDestination;
}
CArc::~CArc(void)
{
}

