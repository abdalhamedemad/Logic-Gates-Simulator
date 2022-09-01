#include "../AddConc.h"
#include "../ApplicationManager.h"
#include"../Components/AND2.h"
#include"../GUI/Input.h"
#include"../Components/Component.h"
AddConc::AddConc(ApplicationManager *pApp):Action(pApp)
{
	z = 1;
	loaded = false;
}

AddConc::AddConc(ApplicationManager *pApp ,bool l ,GraphicsInfo LO):Action(pApp)
{
	z = 1; loaded = l; Gload.x1 = LO.x1; Gload.x2 = LO.x2; Gload.y1 = LO.y1; Gload.y2 = LO.y2;
}

AddConc::~AddConc(void)
{
}

void AddConc::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	pOut = pManager->GetOutput();
	pIn = pManager->GetInput();
	if (loaded == false)
	{
		//Print Action Message
		pOut->PrintMsg("Connection: select the source pin");
		pIn->GetPointClicked(x1 ,y1);
		pOut->ClearStatusBar();

		//Clear Status Bar
		pOut->PrintMsg("Connection: select the destination pin");
		pIn->GetPointClicked(x2 ,y2);
		pOut->ClearStatusBar();
	}
	else {
		x1 = Gload.x1; x2 = Gload.x2; y1 = Gload.y1; y2 = Gload.y2;
	}
}

bool AddConc::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();

	//Calculate the rectangle Corners
	//int Len = UI.AND2_Width;
	//int Wdth = UI.AND2_Height;

	GraphicsInfo GInfo; //Gfx info to be used to construct the AND2 gate
	GInfo.x1 = x1;
	GInfo.x2 = x2;
	GInfo.y1 = y1;
	GInfo.y2 = y2;

	Gload.x1 = x1;
	Gload.x2 = x2; //for load connection in addtion to another load after load
	Gload.y1 = y1;
	Gload.y2 = y2;
	GraphicsInfo a;
	a.x1 = 0;
	a.x2 = 0;
	a.y1 = 0;
	a.y2 = 0;


	Component *p1 = 0 ,*p2 = 0;
	if (pManager->c(&GInfo ,p1 ,p2))
	{

		if (!p2->Get_InputPin()[0].GetConnected()&&p2->GetInputs()==1) {
			GInfo.y1 = ( p1->GetGraphicsInfo().y1 + p1->GetGraphicsInfo().y2 ) / 2.0;
			GInfo.x1 = p1->GetGraphicsInfo().x2 - 6;
			GInfo.y2 = p2->GetGraphicsInfo().y1 + 24;
			GInfo.x2 = p2->GetGraphicsInfo().x1 + 6;
			Connection *pA = new Connection(GInfo ,&p1->Get_OutputPin() ,&p2->Get_InputPin()[0] ,p2, Gload);
			p1->Get_OutputPin().ConnectTo(pA ,pManager->GetCompCount());
			/*pA->setSourcePin(pSrcPin);
			pA->setDestPin(DstPin);*/
			pManager->AddComponent(a ,pA);
			pOut->PrintMsg("error abdo ashraf");
			p2->Set_noOfConnectedPins(-1);


		}

		else if (!p2->Get_InputPin()[0].GetConnected())
		{
			GInfo.y1 = ( p1->GetGraphicsInfo().y1 + p1->GetGraphicsInfo().y2 ) / 2.0;
			GInfo.x1 = p1->GetGraphicsInfo().x2 - 6;
			GInfo.y2 = p2->GetGraphicsInfo().y2 - 8;
			GInfo.x2 = p2->GetGraphicsInfo().x1 + 6;
			Connection *pA = new Connection(GInfo ,&p1->Get_OutputPin() ,&p2->Get_InputPin()[0] ,p2,Gload);
			p1->Get_OutputPin().ConnectTo(pA ,pManager->GetCompCount());
			/*pA->setSourcePin(pSrcPin);
			pA->setDestPin(DstPin);*/
			pManager->AddComponent(a ,pA);
			//pOut->PrintMsg("error abdo ashraf");
			z = 0;
			p2->Set_noOfConnectedPins(1);
		}
		else if (!p2->Get_InputPin()[1].GetConnected())
		{
			pOut->PrintMsg("error abdo ashraf");
			GInfo.y1 = ( p1->GetGraphicsInfo().y1 + p1->GetGraphicsInfo().y2 ) / 2.0;
			GInfo.x1 = p1->GetGraphicsInfo().x2 - 6;
			GInfo.y2 = p2->GetGraphicsInfo().y1 + 8;
			GInfo.x2 = p2->GetGraphicsInfo().x1 + 6;
			Connection *pA = new Connection(GInfo ,&p1->Get_OutputPin() ,&p2->Get_InputPin()[1] ,p2,Gload);
			p1->Get_OutputPin().ConnectTo(pA ,pManager->GetCompCount());
			/*pA->setSourcePin(pSrcPin);
			pA->setDestPin(DstPin);*/
			pManager->AddComponent(a ,pA);
			pOut->PrintMsg("error abdo ashraf");
			p2->Set_noOfConnectedPins(-1);
		}
		else if (!p2->Get_InputPin()[2].GetConnected()) {
			GInfo.y1 = ( p1->GetGraphicsInfo().y1 + p1->GetGraphicsInfo().y2 ) / 2.0;
			GInfo.x1 = p1->GetGraphicsInfo().x2 - 6;
			GInfo.y2 = p2->GetGraphicsInfo().y1 + 24;
			GInfo.x2 = p2->GetGraphicsInfo().x1 + 6;
			Connection *pA = new Connection(GInfo ,&p1->Get_OutputPin() ,&p2->Get_InputPin()[2],p2,Gload);
			p1->Get_OutputPin().ConnectTo(pA ,pManager->GetCompCount());
			/*pA->setSourcePin(pSrcPin);
			pA->setDestPin(DstPin);*/
			pManager->AddComponent(a ,pA);

			p2->Set_noOfConnectedPins(2);
		}
		else if (p2->no() == -1) {

			pOut->PrintMsg("the inputs are full of");

		}
	}
	return true;
}
void AddConc::Undo()
{}
void AddConc::Redo()
{}