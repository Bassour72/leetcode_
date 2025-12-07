#include <iostream>
#include <vector>
#include <string>
#include <unistd.h>
using namespace std;
class Solution 
{
private:
    bool _isStringContDigits(string &s)
    {
        for (size_t i = 0; i < s.size(); i++)
        {
            if (!isdigit(s[i])) return false;
        }
        return true;
    }
    bool isValidOctet(const string &s) 
    {
        if (s.empty() || s.size() > 3) 
            return false;
        if (s.size() > 1 && s[0] == '0') 
            return false;
        int val = atoi(s.c_str());
        return val >= 0 && val <= 255;
    }

    
    void _restoreIpAddressesBacktrack(vector<string> &results, const string &s, string temp = "", int pos = 0, int count_octet = 0) 
    {
        if (count_octet == 4 && pos == (int) s.size()) 
        {
            results.push_back(temp);
            return;
        }
        if (count_octet >= 4 || pos >= (int)s.size())    
        {
            std :: cout <<"\n ===== | " <<  pos << " | " << temp << std::endl;
            return ;//exit(1);
        };

        for (int len = 1; len <= 3 && pos + len <= (int)s.size(); ++len) 
        {
            std :: cout <<"pos = "<<  pos << "|" << count_octet << std::endl;
            std::cout <<"len = "<<  len << std::endl;
            string part = s.substr(pos, len);
            std::cout <<"== "<<  part << std::endl;
            if (isValidOctet(part)) 
            {
                   std::cout <<"=> | "<<  part << std::endl;
                string nextTemp = temp;
                if (!nextTemp.empty()) 
                    nextTemp += ".";
                nextTemp += part;
             
                _restoreIpAddressesBacktrack(results, s, nextTemp, pos + len, count_octet + 1);
            }
        }
    }
   
public:
    vector<string> _restoreIpAddresses(string s) 
    {
        vector<string> vstring;
        _restoreIpAddressesBacktrack(vstring , s);
        return vstring;
    }
    vector<string> restoreIpAddresses(string s) 
    {
        vector<string> vstring;
        if (s.empty() || s.length() > 12 || s.length() < 4 || !_isStringContDigits(s)) return (vstring);
         std::cout << "Here \n";
        return _restoreIpAddresses(s);
    }

};
int main(void)
{
    Solution so;
    vector<string> vstring= so.restoreIpAddresses("16154512");
     std::cout << "\nHere \n";
    for (size_t i = 0; i < vstring.size(); i++)
    {
       std :: cout << vstring[i] << std::endl;
    }
    // std::cout << so._isValidAddress("123456789012") << std::endl;
    // std::cout << so._isValidAddress("255.255.11.1350") << std::endl;
    // std::cout << so._isValidAddress("123456789012") << std::endl;
    // std::cout << so._isValidAddress("123456789012") << std::endl;
    // std::cout << so._isValidAddress("123456789012") << std::endl;
    // std::cout << so._isValidAddress("255.255.111.35") << std::endl;

   
    return 0;
}
