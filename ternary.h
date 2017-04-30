class Ternary: public SubExpression
{
public:
    Ternary(Expression* left, Expression* middle, Expression* right):
        SubExpression(left, middle, right)
    {
    }
        
    //Reassign operands to match language requirements 
    // '(' <operand> ':' <operand> '?' <operand> ') 
    //where the symbols are reversed and the third operand represents
    //the condition.  The first operand is the value when true and the 
    //second value when false.
    double evaluate()
    {
       return right->evaluate() ? left->evaluate() : middle->evaluate();
    }
};