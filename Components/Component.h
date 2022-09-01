#ifndef _COMPONENT_H
#define _COMPONENT_H

#include "..\Defs.h"
#include "..\GUI\Output.h"
#include "InputPin.h"
#include "OutputPin.h"
//Base class for classes Gate, Switch, and LED.
class Component
{
private:
protected:
	string m_Label;
	GraphicsInfo m_GfxInfo;	//The parameters required to draw a component
	Center center;
	bool m_Selected;		// Whether this component is selected or not
	bool m_Deleted;			// Deleted or Not
	int m_ConnectedPins;
public:
	
	Component(const GraphicsInfo &r_GfxInfo);
	virtual void Operate() = 0;	//Calculates the output according to the inputs
	virtual void Draw(Output* pOut) = 0;	//for each component to Draw itself
	virtual void Draw(GraphicsInfo, bool ,Output* pOut) = 0;	//for each component to Draw itself
	void SetDeleted(bool);
	void SetSelected(bool);
	void SelectComp();
	bool GetSelected() const;
	bool GetDeleted() const;

	virtual void save(ofstream &file)=0;
	void SetLabel(const string &label);
	string GetLabel();
	virtual int GetOutPinStatus()=0;	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n)=0;	//returns status of Inputpin # n if SWITCH, return -1
	virtual int GetInputs() = 0;
	void SetCenter(int Cx, int Cy);
	virtual void setInputPinStatus(int n, STATUS s)=0;	//set status of Inputpin # n, to be used by connection class.
	GraphicsInfo GetGraphicsInfo() const;
	Center GetCenter() const;
	virtual void Set_noOfConnectedPins(int x);
	virtual int Get_noOfConnectedPins() const;
	virtual int no()=0;
	virtual OutputPin& Get_OutputPin() = 0;
	virtual InputPin* Get_InputPin() = 0;

	virtual void set(bool i1, bool i2);
	Component();	
	
	//Destructor must be virtual
	virtual ~Component();
	
};

#endif
