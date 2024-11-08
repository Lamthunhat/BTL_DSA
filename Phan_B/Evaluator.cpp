#include <bits/stdc++.h>
#include "ExpressionEvaluator.cpp"
using namespace std;

int main()
{
    ExpressionEvaluator evaluator;
    string expression = "(1+2)*(3+4)";	//Khoi tao chuoi trung to

    string postfixExpression = evaluator.infixToPostfix(expression);
    cout << "Bieu thuc hau to: " << postfixExpression << "\n";
    
    int result = evaluator.evaluatePostfix(postfixExpression);
    cout << "Gia tri cua bieu thuc: " << result << "\n";
    return 0;
}

