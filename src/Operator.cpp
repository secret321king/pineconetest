#include "../h/Operator.h"
#include "../h/ErrorHandler.h"

unordered_map<string, shared_ptr<OperatorBase>> OperatorBase::operators;

Operator opPlus=OperatorBase::create("+", true, true, true);
Operator opMinus=OperatorBase::create("-", true, true, true);
Operator opMultiply=OperatorBase::create("*", true, true, true);
Operator opDivide=OperatorBase::create("/", true, true, true);
Operator opEqual=OperatorBase::create("=", true, true, false);
Operator opGreater=OperatorBase::create(">", true, true, false);
Operator opLess=OperatorBase::create("<", true, true, false);
Operator opColon=OperatorBase::create(":", true, true, false);
Operator opDot=OperatorBase::create(".", true, true, false);
Operator opComma=OperatorBase::create(",", true, true, false);
Operator opIf=OperatorBase::create("?", true, true, false);
Operator opLoop=OperatorBase::create("@", true, true, false);
Operator opOpenPeren=OperatorBase::create("(", false, false, false);
Operator opClosePeren=OperatorBase::create(")", false, false, false);

void getOperators(string text, vector<Operator>& out)
{
	auto i=OperatorBase::operators.find(text);
	
	if (i==OperatorBase::operators.end())
	{
		error.log("unknown operator '" + text + "'", SOURCE_ERROR);
		return;
	}
	else
	{
		out.push_back(i->second);
		return;
	}
	
	/*for (auto i=OperatorBase::operators.begin(); i!=OperatorBase::operators.end(); i++)
	{
		if (text==(*i)->getText())
		{
			out.push_back(*i);
			return;
		}
	}
	
	//in the future, as more operators are found the text string will become shorter and shorter
	if (!text.empty())
		error.log("unknown operator '" + text + "'", SOURCE_ERROR);
		*/
}

