#include <iostream>
#include <vector>
using namespace std;


int linearSearch(const vector<int>& arr, int target) 
{
    for (int i = 0; i <= static_cast<int>(arr.size()) / 2; i++) 
    {
        if (arr[i] == target || arr[arr.size() - i - 1] == target) 
        {
            if (arr[arr.size() - i - 1] == target)
                return (arr.size() - i - 1);
            else
                return (i);
        }
    }
    return (-1);
}

int linearSearch(const vector<int>& arr, int target) 
{
    for (int i = 0; i < static_cast<int>(arr.size()); i++) 
    {
        if (arr[i] == target) 
        {
            return (i);
        }
    }
    return (-1);
}

int main() 
{
    vector<int> numbers = {10, 20, 30, 40, 50};
    int target = 30;
    
    int result = linearSearch(numbers, target);
    
    if (result != -1) 
    {
        cout << "Element found at index: " << result << endl;
    } 
    else 
    {
        cout << "Element not found" << endl;
    }
    
    return 0;
}