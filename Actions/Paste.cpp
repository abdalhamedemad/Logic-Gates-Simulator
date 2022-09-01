#include "Paste.h"
#include "Select.h"
#include "..\ApplicationManager.h"
#include "../Components/BUFFER.h"
//Paste::Paste(ApplicationManager *pApp):Action(pApp)
//{}
//
//Paste::~Paste(void)
//{}
//
//void Paste::ReadActionParameters()
//{
//	//Get a Pointer to the Input / Output Interfaces
//	Output *pOut = pManager->GetOutput();
//	Input *pIn = pManager->GetInput();
//	//Print Action Message
//	pOut->PrintMsg("Click an empty spot to Paste your Copied item");
//	//Wait for User Input
//	pIn->GetPointClicked(Sx ,Sy);
//
//	//Clear Status Bar
//	pOut->ClearStatusBar();
//}
//void Paste::Execute()
//{
//	//Get Point Selected
//	ReadActionParameters();
//	pManager->PasteComp(Sx, Sy);
//}
//void Paste::Undo()
//{}
//
//void Paste::Redo()
//{}

Paste::Paste(ApplicationManager* pApp) :Action(pApp)
{}

Paste::~Paste(void)
{}

void Paste::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	//Print Action Message
	pOut->PrintMsg("Select a location to Paste");
	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();
}
bool Paste::Execute()
{//Get Point Selected
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	/*int Len = UI.AND2_Width;
	int Width = UI.AND2_Height;
	GraphicsInfo PasteInfo;
	PasteInfo.x1 = Cx - Len / 2;
	PasteInfo.x2 = Cx + Len / 2;
	PasteInfo.y1 = Cy - Width / 2;
	PasteInfo.y2 = Cy + Width / 2;*/
	
	//	pManager->zx()->Draw(pOut);

	//pManager->AddComponent(PasteInfo, pManager->getCopied());
	//pManager->SelectComponent(Cx, Cy);
	//pManager->SetCopiedComp();
	//pManager->DeleteComp();
	//ReadActionParameters();
	pManager->PasteComp(Cx,Cy);
	//BUFFER* pA = new BUFFER(PasteInfo, AND2_FANOUT);
	//pManager->getCopied()->Draw(PasteInfo, pManager->getCopied()->GetSelected(),pOut);
	/*pManager->UpdateInterface();*/
	return false;
}
void Paste::Undo()
{}

void Paste::Redo()
{}