# Expression-Interpreter
c++ project for Programming Languages Class.

This program reads in the arithmetic expression and encodes the expression as a binary tree. After the expression has been read in, the variable assignments are read in and the variables, and their values are placed into the symbol table.  Finally the expression is evaluated recursively.

Part of the program was written but only an incomplete version for evaluating mathematical expressions.
My efforts extended this program to support reading a .txt file of expressions, and support for relational, logical, and conditional expression operators defined by the below Backus-Naur form grammer.

```
<program> -> <exp> , <assigns> ; 
<exp> -> ( <exp> <op> <exp> ) | '(' <exp> ':' <exp> '?' <exp> ')' |
'(' <exp> '!' ') | <literal> | <variable>
<assigns> -> <assigns> , <assign>
<assign> -> <variable> = <literal>
<op> -> '+' | '-' | '*' | '/' | '>' | '<' | '=' | '&' | '|'
```
-In the conditional expression operator, the symbols are reversed and the third
 operand represents the condition. The first operand is the value when true and
 the second the value when false
 
-The logical operators use single symbols not
 double, for example the and operator is & not &&
 
-The negation operator ! is a postfix operator, not a prefix one

-There are only three relational operators not the usual six and the operator
 for equality is = not ==

Examples of valid statements, nested expressions are supported using Recursive Decent Parsing: 
```
Math examples:
(((4*b)/(3+7)) + (a-4)), b = 5, a = 6;
Boolean examples
((a<b) | (b=a)), a = 4, b = 5;
Ternary examples:
(((6*1) : (6+1) ? (3 = 4)) : (6+6) ? (a = b)),a=3, b =3;
(((6*1) : (6+1) ? (3 = 3)) : ((6*1) : (6+1) ? ((3 < 4)!)) ? (a = b)),a=2, b = 3;
```
