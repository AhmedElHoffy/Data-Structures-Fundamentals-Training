#include "ExpressionEval_PostFix.h"

bool isOperator(char c) {
	if (c == '*' || c == '/' || c == '+' || c == '-') {
		return true;
	}
	else {
		return false;
	}
}

int PerformOperation(int op1, int op2, char oper) {
	int ans;

	switch (oper) {

	case '+': {
		ans = op1 + op2;
		break;
	}
	case '-': {
		ans = op1 - op2;
		break;
	}
	case '/': {
		ans = op1 / op2;
		break;
	}
	case '*': {
		ans = op1 * op2;
		break;
	}
			return ans;
	}

}
