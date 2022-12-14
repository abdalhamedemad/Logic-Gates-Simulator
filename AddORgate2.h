#ifndef _ADD_OR_GATE_H
#define _ADD_OR_GATE_H

#include "Actions/Action.h"
#include "OR2.h"

class AddORgate2 : public Action
{
private:
	//Parameters for rectangular area to be occupied by the gate
	int Cx, Cy;	//Center point of the gate
	int x1, y1, x2, y2;	//Two corners of the rectangluar area
	bool loaded;
public:
	AddORgate2(ApplicationManager* pApp);
	AddORgate2(ApplicationManager *pApp ,bool l ,int cx ,int cy);
	virtual ~AddORgate2(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual bool Execute();

	virtual void Undo();
	virtual void Redo();


};

#endif