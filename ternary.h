class Ternary: public SubExpression
{
public:
    Ternary(Expression* left, Expression* middle, Expression* right):
        SubExpression(left, middle, right)
    {
    }
    double evaluate()
    {
       return right->evaluate() ? middle->evaluate() : left->evaluate();
    }
};