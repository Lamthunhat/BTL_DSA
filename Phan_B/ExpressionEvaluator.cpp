#include <bits/stdc++.h>
#include "Stack.cpp"
using namespace std;

class ExpressionEvaluator
{
public:
    //Ham kiem tra do uu tien cua cac toan tu
    int precedence(char op)
    {
        if (op == '+' || op == '-') return 1;
        if (op == '*' || op == '/') return 2;
        return 0;
    }

    //Hàm chuyen bieu thuc trung to sang hau to
    string infixToPostfix(string &infix)
    {
        Stack<char> operators;
        string postfix;

        for (char ch : infix)
        {
            //Neu là so hoac chu cai, thêm vào chuoi hau to
            if (isalnum(ch))
            {
                postfix += ch;
            }
            //Neu la dau mo ngoac
            else if (ch == '(')
            {
                operators.push(ch);
            }
            //Neu la dau dong ngoac
            else if (ch == ')')
            {
                while (!operators.empty() && operators.top() != '(')
                {
                    postfix += operators.top();
                    operators.pop();
                }
                operators.pop();    //Loai bo dau '('
            }
            //Neu là toan tu
            else
            {
                while (!operators.empty() && precedence(operators.top()) >= precedence(ch))
                {
                    postfix += operators.top();
                    operators.pop();
                }
                operators.push(ch);
            }
        }
        //Lay các toan tu còn lai ra khoi ngan xep
        while (!operators.empty())
        {
            postfix += operators.top();
            operators.pop();
        }

        return postfix; //Tra ve chuoi hau to
    }

    //Ham tinh gia tri bieu thuc hau to
    int evaluatePostfix(string &postfix)
    {
        Stack<int> values;

        for (char ch : postfix)
        {
            //Neu là so, chuyen thanh so nguyen và day vào ngan xep
            if (isdigit(ch))
            {
                values.push(ch - '0');    //Chuyen ky tu so thanh gia tri so
            }
            //Neu la toan tu, lay hai gia tri tren cung cua ngan xep va thuc hien phep tinh
            else
            {
                int val2 = values.top(); values.pop();
                int val1 = values.top(); values.pop();

                switch (ch)
                {
                    case '+': values.push(val1 + val2);    break;
                    case '-': values.push(val1 - val2);    break;
                    case '*': values.push(val1 * val2);    break;
                    case '/': values.push(val1 / val2);    break;
                }
            }
        }

        return values.top();  //Tra ve gia tri ket qua cuoi cung
    }
};

