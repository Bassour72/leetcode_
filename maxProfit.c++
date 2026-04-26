#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
/*
class Solution {
public:
    static int maxProfit(std::vector<int>& prices) 
    {
        std::vector<int>::iterator min = std::min_element(prices.begin(), prices.end());
        ++min;
        if (min == prices.end())
        {
            --min;
           min = std::min_element(prices.begin(), min);
        }
        else
            --min;
        std::vector<int>::iterator max = std::max_element(min, prices.end());
        int profit = *max - *min;
        return (profit > 0) ? profit : 0;
    }
};
*/
class Solution {
public:
    static int maxProfit(std::vector<int>& prices) 
    {
      
        int res = 0;
        std::vector<int>::iterator max ;
        std::vector<int>::iterator  it = prices.begin();
        std::set<int> vec;
        for (; it < prices.end(); it++)
        { 
            if (vec.find( *it) == vec.end()) {
                vec.insert(*it);
                max = std::max_element(it, prices.end());
            }
            if (res  < (*max - *it))
                res = *max - *it;
        }
        return (res);
    }
};


int main(void)
{
    int arr1[]= {7,1,5,3,6,4}; // 5 
    // std::vector<int> prices (arr1, arr1 + (sizeof(arr1) / sizeof(arr1[0]))); // 5 

    // int arr2[] = {2,1,2,1,0,1,2}; // 1
    // std::vector<int> prices (arr2, arr2 + (sizeof(arr2) / sizeof(arr2[0]))); // 1


    int arr3[] = {2,4,1}; // 2
    std::vector<int> prices (arr3, arr3 + (sizeof(arr3) / sizeof(arr3[0]))); // 2


    //int arr4[] = {3,2,6,5,0,3}; // 4
    // /std::vector<int> prices ((arr4, arr4 + (sizeof(arr4) / sizeof(arr4[0])))); // 4


   std::cout << Solution::maxProfit(prices) << " === \n";
}