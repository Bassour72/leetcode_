#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <vector>

// class Solution {
// public:
//     static std::string longestCommonPrefix(std::vector<std::string>& strs) 
//     {
//         if (strs.empty()) 
//             return "";
//         std::string str = "";

//         size_t i = 0;       
//         bool is = false;
//         for (size_t j = 0; j < strs[i].length(); j++)
//         {
//             i = 1;
//             char c = strs[0][j];
//             is = true;
            
//             for (; i < strs.size(); i++)
//             {
//                 if (c != strs[i][j])
//                 {
//                     is = false;
//                     break;
//                 }
//             }
//             if (is)
//                 str += c;
//             else
//                 break;
//             i -= 1;
//         }
        
//         return (str);
//     }
// };
class Solution {
public:
   static  std::string longestCommonPrefix(std::vector<std::string>& strs) 
    {
        if (strs.empty()) 
            return "";

        for (int i = 0; i < (int)strs[0].size(); ++i) 
        {
            for (int a = 1; a < (int)strs.size(); ++a) 
            {
                if (i >= (int)strs[a].size() or strs[a][i] != strs[0][i]) 
                    return strs[0].substr(0, i);
            }
        }
        return strs[0];
    }
};
int main(void)
{           //             |     |     |      |
    std::string arr1[] = {"bat","bang","bank","band"};
    std::string arr2[] = {"dance","dag","danger","damage"};
    std::string arr3[] = {"neet","feet"};
    std::string arr4[] = {"flower","flow","flight"};
    std::string arr5[] = {"dog","racecar","car"};


    std::vector<std::string> vec1;
    vec1.insert(vec1.end(), arr1, arr1 + 4);

    std::vector<std::string> vec2;
    vec2.insert(vec2.end(), arr2, arr2 + 4);

    std::vector<std::string> vec3;
    vec3.insert(vec3.end(), arr3, arr3 + 2);


    std::vector<std::string> vec4;
    vec4.insert(vec4.end(), arr4, arr4 + 3);

    std::vector<std::string> vec5;
    vec5.insert(vec5.end(), arr5, arr5 + 3);

    std::cout << Solution::longestCommonPrefix(vec1) << "\n";
    std::cout << Solution::longestCommonPrefix(vec2) << "\n";
    std::cout << Solution::longestCommonPrefix(vec3) << "\n";
    std::cout << Solution::longestCommonPrefix(vec4) << "\n";
    std::cout << Solution::longestCommonPrefix(vec5) << "\n";

    return 0;
}
