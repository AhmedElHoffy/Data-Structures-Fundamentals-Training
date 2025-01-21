#include "AreBalancedParantheses.h"
#include <stack>

bool arePair(char first, char second) {
	if ((first == '(' && second == ')') || (first == '{' && second == '}') || (first == '[' && second == ']')) {
		return true;
	}
	else {
		return false;
	}

}

bool areBalancedParantheses(string Exp) {
	stack<char> S;
	for (int i = 0; i < Exp.length(); i++) {
		if (Exp[i] == '(' || Exp[i] == '[' || Exp[i] == '{') {
			S.push(Exp[i]);
		}
		else if (Exp[i] == '}' || Exp[i] == ')' || Exp[i] == '}') {
			if (S.empty() || !arePair(S.top(), Exp[i])) {
				return false;
			}
			else {
				S.pop();
			}
		}
	}

	return S.empty();
}

