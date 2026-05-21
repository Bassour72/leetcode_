#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <vector>


class Solution 
{
public:
   static int singleNumber(std::vector<int>& nums) 
    {
        std::set<int> nset;
        int nbr = 0;
        for (size_t i = 0; i < nums.size(); i++)
            nbr =  nbr ^ nums[i];
            
       return (nbr);         
    }
};


int main()
{
    int arr1[] ={7,6,6,7,8};
    int arr2[] ={3,2,3};
    int arr3[] ={4,1,2,1,2};
    std::vector<int> vec1(arr1, arr1 + sizeof(arr1)/sizeof(arr1[0]));
    std::vector<int> vec2(arr2, arr2 + sizeof(arr2)/sizeof(arr2[0]));
    std::vector<int> vec3(arr3, arr3 + sizeof(arr3)/sizeof(arr3[0]));


    std::cout << Solution::singleNumber(vec2) << "\n";
    // std::cout << Solution::singleNumber(vec2) << "\n";
    // std::cout << Solution::singleNumber(vec3) << "\n";



    return 0;
}
