#include <iostream>
#include <stack>
#include <math.h>
using namespace std;

bool IsDigit(char C)
{
    if (C >= '0' && C <= '9')
        return true;

    return false;
}

bool IsOperator(char C)
{
    if (C == '+' || C == '-' || C == '*' || C == '/' || C == '^')
        return true;

    return false;
}

int Operation(char operation, int operand1, int operand2)
{
    if (operation == '+')
        return operand1 + operand2;

    else if (operation == '-')
        return operand1 - operand2;

    else if (operation == '*')
        return operand1 * operand2;

    else if (operation == '/')
        return operand1 / operand2;

    else if (operation == '^')
        return pow(operand1, operand2);

    else
        cout << "Unexpected Error \n";

    return -1;
}

int calculate_Postfix(string expression)
{
    stack<int> S;
    int len = expression.length();

    for (int i = 0; i < len; i++)
    {
        if (expression[i] == ' ' || expression[i] == ',')
            continue;

        else if (IsOperator(expression[i]))
        {
            int operand2 = S.top();
            S.pop();
            int operand1 = S.top();
            S.pop();

            int result = Operation(expression[i], operand1, operand2);
            S.push(result);
        }
        else if (IsDigit(expression[i]))
        {
            int operand = 0;

            while (i < expression.length() && IsDigit(expression[i]))
            {
                operand = (operand * 10) + (expression[i] - '0');
                i++;
            }

            i--;
            S.push(operand);
        }
    }
    return S.top();
}

int main()
{
    string POST_EXP1 = "5 6 2 + * 12 4 / -";
    string POST_EXP2 = "2 3 ^ 5 2 2 ^ * 12 6 / - +";

    cout << "The answer after calculating the postfix expression is : " << calculate_Postfix(POST_EXP1) << endl;
    cout << "The answer after calculating the postfix expression is : " << calculate_Postfix(POST_EXP2);

    return 0;
}
