#include "AddXORgate2.h"
#include "ApplicationManager.h"

AddXORgate2::AddXORgate2(ApplicationManager* pApp) :Action(pApp)
{
	loaded = false;
}
AddXORgate2::AddXORgate2(ApplicationManager *pApp ,bool l ,int cx ,int cy) : Action(pApp)
{
	loaded = l;
	Cx = cx; Cy = cy;
}
AddXORgate2::~AddXORgate2(void)
{
}

void AddXORgate2::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	if (loaded == false)
	{
		//Print Action Message
		pOut->PrintMsg("2-Input XOR Gate: Click to add the gate");

		//Wait for User Input
		pIn->GetPointClicked(Cx ,Cy);

		//Clear Status Bar
		pOut->ClearStatusBar();
	}
}

bool AddXORgate2::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();
	Output *pOut = pManager->GetOutput();
	//Calculate the rectangle Corners
	int Len = UI.OR2_Width;
	int Wdth = UI.OR2_Height;

	GraphicsInfo GInfo; //Gfx info to be used to construct the AND2 gate

	GInfo.x1 = Cx - Len / 2;
	GInfo.x2 = Cx + Len / 2;
	GInfo.y1 = Cy - Wdth / 2;
	GInfo.y2 = Cy + Wdth / 2;
	if (pManager->CanDraw(Cx ,Cy)) 
	{
		XOR2 *pA = new XOR2(GInfo ,AND2_FANOUT);
		pManager->AddComponent(GInfo ,pA);
	}
	else
		pOut->PrintMsg("invalid location please tryagain ");

	return true;
}

void AddXORgate2::Undo()
{
	Output *pOut = pManager->GetOutput();

	pManager->SelectComponent(Cx ,Cy);

	pManager->DeleteComp();
}

void AddXORgate2::Redo()
{
	Output *pOut = pManager->GetOutput();
	//	Component *c =pManager->getlastcomp();

	int Len = UI.AND2_Width;
	int Wdth = UI.AND2_Height;

	GraphicsInfo GInfo; //Gfx info to be used to construct the AND2 gate

	GInfo.x1 = Cx - Len / 2;
	GInfo.x2 = Cx + Len / 2;
	GInfo.y1 = Cy - Wdth / 2;
	GInfo.y2 = Cy + Wdth / 2;
	XOR2 *pA = new XOR2(GInfo ,AND2_FANOUT);
	pManager->AddComponent(GInfo ,pA);
	//pManager->AddComponent(GInfo, D);}
}
