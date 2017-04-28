class SubExpression: public Expression
{
public:
    SubExpression(Expression* left, Expression* right);
    SubExpression(Expression* right, Expression* left, Expression* middle);
    static Expression* parse();
protected: 
    Expression* left;
    Expression* right;
    Expression* middle;
};