class SubExpression: public Expression
{
public:
    SubExpression(Expression* left);
    SubExpression(Expression* left, Expression* right);
    SubExpression(Expression* left, Expression* middle, Expression* right);
    static Expression* parse();
protected: 
    Expression* left;
    Expression* middle;
    Expression* right;
};