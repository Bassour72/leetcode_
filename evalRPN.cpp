#include <iostream>
#include <vector>
#include <stack>
#include <cctype>
class Solution 
{
    int doOperation(int operand_a, int operand_b, char oper)
    {
        if (oper == '+')
            return (operand_a + operand_b);
        if (oper == '-')
            return (operand_a - operand_b);
        if (oper == '*')
            return (operand_a * operand_b);
        if (oper == '/')
            return (operand_b == 0 ? 0 : operand_a / operand_b);
        return 0;
    }
    int isStringInt(const std::string &intStr)
    {
        return (std::isdigit(intStr[0]) || ((intStr[0] == '-' || intStr[0] == '-' ) && std::isdigit(intStr[1])));
    }
public:
    int evalRPN(std::vector<std::string>& tokens) 
    {
        if (tokens.empty()) return 0;
        std::stack<int> stackRPN;
        int operand_a = 0;
        int operand_b = 0;
        int result = 0;

        for (size_t i = 0; i < tokens.size(); i++)
        {
            
            if (isStringInt(tokens[i]))
            {
                stackRPN.push(std::atoi(tokens[i].c_str()));
                result = stackRPN.top();
            }
            else if (tokens[i][0] == '+' || tokens[i][0] == '-' || tokens[i][0] == '/' || tokens[i][0] == '*')
            {    
               operand_a = stackRPN.top();
               stackRPN.pop();
               operand_b = stackRPN.top();
               stackRPN.pop();
               result = doOperation( operand_b, operand_a, tokens[i][0]);
               stackRPN.push(result);
            }
            else
                std::cout <<  "Error : " << tokens[i][0] << "\n";
        }
       
        return result;
    }
};

int main(void)
{
    Solution so;const char* arr[] = {"2", "1", "+", "3", "*"};
    // Solution so;const char* arr[] = {"1"};
    // Solution so;const char* arr[] = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    // Solution so;const char* arr[] = {"4","13","5","/","+"};
    std::vector<std::string> strv(arr, arr + 5);
    std::cout << "\n" << so.evalRPN(strv);
    return 0;
}
