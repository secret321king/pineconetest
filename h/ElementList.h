#pragma once

#include "Element.h"
#include <list>
#include <vector>

using std::list;
using std::vector;
using std::unique_ptr;

#include "OperatorElement.h"

#include "ActionTable.h"

class ElementList: public Element
{
public:
	
	ElementList(ElementData dataIn, StackFrame * frame);
	
	~ElementList() {clear();}
	
	string getReadableName() {return "element list";}
	
	//Identifier * makeIdentifier(string name) {return table.makeIdentifier(name);}
	
	Type getReturnType();
	
	void structureByOperators();
	
	ActionPtr resolveActions();
	ActionPtr resolveActions(ActionTablePtr table) {return resolveActions();}
	
	void absorbForOperators(vector<OperatorType> operators);
	
	void printToString(string& in, int depth);
	using Element::printToString;
	
	void appendElement(ElementPtr in);
	
	ActionTablePtr getActionTable() {return table;}
	
	ElementData::Type getElemType() {return ElementData::SCOPE;}
	
	void* execute();
	
	void clear();
	
private:
	
	list<ElementPtr> elems;
	
	ActionTablePtr table;
};

