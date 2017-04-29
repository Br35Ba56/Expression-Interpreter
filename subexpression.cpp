#include <iostream>
using namespace std;

#include "expression.h"
#include "subexpression.h"
#include "operand.h"
#include "plus.h"
#include "minus.h"
#include "times.h"
#include "divide.h"
#include "lessthan.h"
#include "equal.h"
#include "and.h"
#include "greaterthan.h"
#include "or.h"
#include "ternary.h"
#include "negation.h"
SubExpression::SubExpression(Expression* left)
{
    this->left = left;
}
SubExpression::SubExpression(Expression* left, Expression* right)
{
    this->left = left;
    this->right = right;
}
SubExpression::SubExpression(Expression* right, Expression* left, Expression* middle)
{
    this->left = left;
    this->middle = middle;
    this->right = right;
}

Expression* SubExpression::parse()
{
    Expression* left;
    Expression* right;
    Expression* middle;
    char operation, paren;
    
    left = Operand::parse();
    cin >> operation;
    if (operation == '!'){
        cin >> paren;
        return new Negation(left);
    }
    
    right = Operand::parse();
    cin >> paren;
    switch (operation)
    {
        case '+':
            return new Plus(left, right);
        case '-':
            return new Minus(left, right);
        case '*':
            return new Times(left, right);
        case '/':
            return new Divide(left, right);
        case '>':
            return new GreaterThan(left, right);
        case '<':
            return new LessThan(left, right);
        case '=':
            return new Equal(left, right);
        case '&':
            return new And(left, right);
        case '|':
            return new Or(left, right);
        case ':':
            //Reassign operands to match language requirements 
            // '(' <operand> ':' <operand> '?' <operand> ') 
            //where the symbols are reversed and the third operand represents
            //the condition.  The first operand is the value when true and the 
            //second value when false.
            middle = right;
            right = Operand::parse();
            cin >> paren;
            return new Ternary(right, middle, left);
    }
    return 0;
}