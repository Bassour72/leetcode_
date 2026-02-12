#include <vector>
#include <iostream>
#include <string>
using namespace std;
/*
    Step One:
        First, check if the string is empty or if numRows is less than or equal to three.

    Step Two:
        Calculate the size of the new string,
        then initialize the new string with spaces.

    Step Three:
        Iterate over the original string.
*/
class Solution 
{
public:
    static std::string convert(std::string s, int numRows) 
    {
        if (s.empty() || numRows == 1 || numRows >= (int)s.size())
            return s;

        std::vector<std::string> rows(numRows);

        int currentRow = 0;
        bool goingDown = false; // if going donw & up

        for (int i = 0; i < (int)s.size(); i++)
        {
            rows[currentRow] += s[i];

            if (currentRow == 0 || currentRow == numRows - 1)
                goingDown = !goingDown;

            currentRow += (goingDown )? 1 : -1;
        }
        std::string result;
        for (int i = 0; i < numRows; i++)
            result += rows[i];

        return result;
    }
};


int main(void)
{
   std::string  s = "PAYPALISHIRING";
   std::cout << Solution::convert(s,4) << "\n";

    s = "PAYPALISHIRING";
   std::cout << Solution::convert(s,4) << "\n";

    s = "PAYPALISHIRINGsdeeerfff";
   std::cout << Solution::convert(s,4) << "\n";


    s = "PAYPALISHIRINGaaaaaaaaaeeeeeeeeeeeer";
   std::cout << Solution::convert(s,7) << "\n";

    s = "PAYPALISHIRING";
   std::cout << Solution::convert(s,4) << "\n";

    s = "PAYPALISHIRINjdjhdhdhdhdhdhhG";
   std::cout << Solution::convert(s,6) << "\n";

    s = "PAYPALISHIRING";
   std::cout << Solution::convert(s,4) << "\n";
    return 0;
}
/*
P     I    N
A   L S  I G
Y A   H R
P     I
*/