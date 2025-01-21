// ExpressionEval_PostFix.h
#ifndef EXPRESSIONEVAL_POSTFIX_H
#define EXPRESSIONEVAL_POSTFIX_H

#include <string>
using namespace std;

// Expression Evaluation Functions
bool isOperator(char c);
int PerformOperation(int op1, int op2, char oper);

#endif //EXPRESSIONEVAL_POSTFIX_H