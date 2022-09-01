#ifndef _ADD_Conc_H
#define _ADD_Conc_H

#include "Actions/Action.h"
#include "Components/Connection.h"

class AddConc: public Action
{
private:
	bool x;
	bool z;
	Output *pOut;
	Input *pIn;
	OutputPin *pSrcPin;
	InputPin *DstPin;
	//Parameters for rectangular area to be occupied by the gate
		//Center point of the gate
	int x1 ,y1 ,x2 ,y2;
	bool loaded;
	GraphicsInfo Gload;
	//Two corners of the rectangluar area
public:
	AddConc(ApplicationManager *pApp ,bool l ,GraphicsInfo LO);
	AddConc(ApplicationManager *pApp);
	virtual ~AddConc(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual bool Execute();

	virtual void Undo();
	virtual void Redo();


};

#endif
