#include <vector>
#include <iostream>
using namespace std;


class Solution 
{
public:
    string interpret(string command) 
    {
       size_t  i = 0;
        while (i < command.length())
        {
            if (command[i] == '(' && command[i + 1] == ')')
            {
                command.erase(i, 2);
                command.insert(i, "o");
            }
            else
                i++;
        }
        i = 0;
        while (i < command.length())
        {
            if (command[i] == '(' || command[i] == ')')
            {
                command.erase(i, 1); 
            }
            else
                i++;
        }
        return (command);
    }
};

int main(void)
{
    Solution s;

    cout << s.interpret("G()()()()(al)") << endl;
    cout << s.interpret("G()(al)") << endl;
    cout << s.interpret("(al)G(al)()()G") << endl;
    cout << s.interpret("G()()()()(al)") << endl;
}