#include "InfixPostfixConvert.h"
#include "ExpressionEval_PostFix.h"
#include<stack>
// Infix to Postfix Conversion Functions
bool IsOperand(char c) {
	if ((c >= '0' && c <= '9')) {
		return true;
	}
	else {
		return false;
	}
}

int GetOperatorWeight(char op) {
	int weight = -1; //initialize the operator weight
	switch (op) {
	case '+':
	case '-':
		weight = 1;
		break;
	case'*':
	case'/':
		weight = 2;
		break;
	}
	return weight;
}

bool IsHigherPrecendence(char operator1, char operator2) {

	int op1Weight = GetOperatorWeight(operator1);
	int op2Weight = GetOperatorWeight(operator2);

	return op1Weight > op2Weight ? true : false;

}
// function to convert infix expression to postfix
string InfixPostfixConvert(string Exp) {
	stack<char>SChar;
	string  postfix = "";

	for (int i = 0; i < Exp.length(); i++) {
		//scan

		if (Exp[i] == ' ' || Exp[i] == ',') {
			continue;

		}
		else if (isOperator(Exp[i])) {
			while (!SChar.empty() && SChar.top() != '(' && IsHigherPrecendence(SChar.top(), Exp[i]))
			{
				postfix += SChar.top();
				SChar.pop();
			}
			SChar.push(Exp[i]);

		}
		else if (IsOperand(Exp[i])) {
			postfix += Exp[i];

		}
		else if (Exp[i] == '(') {
			SChar.push(Exp[i]);

		}
		else if (Exp[i] == ')') {
			while (!SChar.empty() && SChar.top() != '(') {
				postfix += SChar.top();
				SChar.pop();
			}
			SChar.pop(); // pop out the opening Parentheses '('
		}

	}
	while (!SChar.empty()) {
		postfix += SChar.top();
		SChar.pop();
	}
	return postfix;
}
