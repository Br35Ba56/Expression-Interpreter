#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <string.h>
using namespace std;

#include "expression.h"
#include "subexpression.h"
#include "symboltable.h"
#include "parse.h"

SymbolTable symbolTable;

void parseAssignments();

int main()
{
    Expression* expression;
    std::ifstream infile("input.txt");
    std::string line;
    char paren, comma;
    for (std::string line; getline(infile, line);)
    {
        int myArraySize = line.size() +1;
        char myArray[myArraySize];
        strcpy(myArray, line.c_str());
        for (int i = 0; i < myArraySize; i++)
        {
            std::cout << myArray[i];
        }
        for (int i = myArraySize; i >= 0; i--)
        {
            cin.putback(myArray[i]);
        }
        cout << endl;
        cin >> paren;
        expression = SubExpression::parse();
        cin >> comma;
        parseAssignments();
        cout << "Value = " << expression->evaluate() << endl; 
        symbolTable.clear();
    }
    return 0;
}

void parseAssignments()
{
    char assignop, delimiter;
    string variable;
    double value;
    do
    {
        variable = parseName();
        cin >> ws >> assignop >> value >> delimiter;
        symbolTable.insert(variable, value);
    }
    while (delimiter == ',');
}