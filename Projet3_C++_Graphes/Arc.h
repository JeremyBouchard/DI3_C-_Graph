#ifndef CARC_H
#define CARC_H
class CArc
{
private :
	int uiARCDestination;
	int iARCPoids;

public:
	CArc(int uiDestination, int iPoids);
	CArc(CArc & ARCParam);
	~CArc(void);

	int ARCLireDestination(){return uiARCDestination;}
	int ARCLirePoids(){return iARCPoids;}
};

#endif