#ifndef _PASTE_H
#define _PASTE_H

#include "..\Actions\Action.h"
#include "..\ApplicationManager.h"
#include "..\Components\Component.h"
#include "..\Components\Connection.h"

class Paste : public Action
{
private:
	int Sx, Sy;
	int Cx, Cy;
	//int x1, y1, x2, y2;
public:
	Paste(ApplicationManager* pApp);
	virtual ~Paste(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual bool Execute();

	virtual void Undo();
	virtual void Redo();


};
#endif