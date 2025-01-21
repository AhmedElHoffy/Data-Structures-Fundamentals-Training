// INFIXPOSTFIXCONVERT.h
#ifndef INFIXPOSTFIXCONVERT_H
#define INFIXPOSTFIXCONVERT_H

#include <string>
using namespace std;

// Infix to Postfix Conversion Functions
bool IsOperand(char c);

int GetOperatorWeight(char op);

bool IsHigherPrecendence(char operator1, char operator2);

// function to convert infix expression to postfix
string InfixPostfixConvert(string Exp);

#endif // INFIXPOSTFIXCONVERT_H

