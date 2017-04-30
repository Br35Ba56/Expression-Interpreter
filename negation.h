class Negation: public SubExpression
{
public:
    Negation(Expression* left):
        SubExpression(left)
    {
    }
    double evaluate()
    {
       return !(left->evaluate());
    }
};
