#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <vector>

class Solution 
{
    static void floodFill(std::vector<std::vector<int> > & image, int sr, int sc, int color, int t) 
    {
        if (image.size() <= sr || image[sr].size() <= sc  || sr < 0 || sc < 0 || image[sr][sc] != t)
            return ;
          if (image[sr][sc] == color )
            return ;
        image[sr][sc] = color;
        floodFill(image, sr, sc + 1, color, t);
        floodFill(image, sr, sc -1 , color, t); 
        floodFill(image, sr + 1, sc, color, t); 
        floodFill(image, sr - 1, sc, color, t); 
    }
public:
    static std::vector<std::vector<int> > floodFill(std::vector<std::vector<int> >& image, int sr, int sc, int color) 
    {
        floodFill(image, sr, sc, color,image[sr][sc]);
       return (image);
    }
};
int main(void)
{
    //Input: image = [[0,0,0],[0,0,0]], sr = 0, sc = 0, color = 0

// Output: [[0,0,0],[0,0,0]]


    int arr[]={1,1,1};
    int arr1[]={1,1,0};
    int arr2[]={1,0,1};
    int sr = 1, sc = 1, color = 2;

    // int arr[]={0,0,0};
    // int arr1[]={0,0,0};
    // int arr2[]={0,0,0};
    // int sr = 0, sc = 0, color = 0 ;
    std::vector<int> img1(arr, arr + (sizeof(arr) / sizeof(arr[0])));
    std::vector<int> img2(arr1, arr1 + (sizeof(arr1) / sizeof(arr1[0])));
    std::vector<int> img3(arr2, arr2 + (sizeof(arr2) / sizeof(arr2[0])));

    std::vector<std::vector<int> >image;
    image.push_back(img1);
    image.push_back(img2);
    image.push_back(img3);

	Solution::floodFill(image,sr, sc, color);
	// std::cout << Solution::floodFill("aa", "*a") << "\n";

    for (size_t i = 0; i < image.size(); i++)
    {
        for (size_t j = 0; j < image[i].size(); j++)
        {
            std :: cout << image[i][j] << " ";
        }
            std :: cout << "\n";
        
    }
    

	return 0;
}

