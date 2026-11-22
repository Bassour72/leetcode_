#include <iostream>


class Solution {
    bool isLeapYear(int year)
    {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }
public:
    int dayOfYear(std::string date) 
    {
        int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        int yearNumber = std::atoi(date.substr(0, 4).c_str());
        int monthNumber = std::atoi(date.substr(5, 2).c_str());
        int dayNumber = std::atoi(date.substr(8, 2).c_str());
        
        if (isLeapYear(yearNumber)) 
            months[1] = 29;
        
        int totalDay = 0;
        for (int i = 0; i < monthNumber - 1; i++)
        {
            totalDay += months[i];
        }

        totalDay += dayNumber;
        return (totalDay);      
    }
};

int main()
{
    Solution so;
    std :: cout<< so.dayOfYear("2004-03-01") <<"\n";
    return 0;
}
