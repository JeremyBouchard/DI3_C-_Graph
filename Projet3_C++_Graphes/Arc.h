#ifndef CARC_H
#define CARC_H
class CArc
{
private :
	int uiARCDestination;
	float fARCPoids;

public:
	CArc(int uiDestination, float fPoids);
	CArc(CArc & ARCParam);
	~CArc(void);

	int ARCLireDestination(){return uiARCDestination;}
	float ARCLirePoids(){return fARCPoids;}
};

#endif