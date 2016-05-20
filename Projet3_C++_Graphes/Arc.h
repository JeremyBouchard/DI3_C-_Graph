#ifndef CARC_H
#define CARC_H
class CArc
{
private :
	int uiARCDestination;

public:
	CArc(int uiDestination);
	CArc(CArc & ARCParam);
	~CArc(void);

	int ARCLireDestination(){return uiARCDestination;}
};

#endif