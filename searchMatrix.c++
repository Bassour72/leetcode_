#include <iostream>
#include <vector>

class Solution {
public:
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) 
    {
        for (size_t i = 0; i < matrix.size(); i++)
        {
            for (size_t j = 0; j < matrix[i].size(); j++)
            {
                if (matrix[i][j] == target) return (true);
                if (matrix[i][j] > target )
                    break;
            }
            
        }
        return (false);
    }
};