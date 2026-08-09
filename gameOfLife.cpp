#include <iostream>
#include <vector>
#include <string>

using namespace std;
/*
Any live cell with fewer than two live neighbors dies as if caused by under-population.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by over-population.
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
horizontal
diagonal
up
down
left
right
*/
class Solution {
    private:
        static bool _underPopulation(short residx, short residy, vector<vector<int>>& board)
        {
            int countNeighbors = 0;
            if (board[residy][residx] == 1 && ( residx + 1) < board[residy].size() && board[residy][residx + 1] == 1)
                countNeighbors++;
            if (board[residy][residx] == 1 && ( residx  - 1) >= 0 && board[residy][residx - 1] == 1)
                countNeighbors++;
            if (board[residy][residx] == 1 && ( residy + 1) < board.size() && board[residy + 1][residx] == 1)
                countNeighbors++;
            if (board[residy][residx] == 1 && ( residy  - 1) >= 0 && board[residy - 1][residx] == 1)
                countNeighbors++;
            if (board[residy][residx] == 1 && ( residy  - 1) >= 0 && ( residx  - 1) >= 0 && board[residy - 1][residx - 1] == 1)
                countNeighbors++;
            if (board[residy][residx] == 1 && ( residy  - 1) >= 0 && ( residx  + 1) < board[residy].size() && board[residy - 1][residx + 1] == 1)
                countNeighbors++;
            if (board[residy][residx] == 1 && ( residy  + 1) < board.size() && ( residx  - 1) >= 0 && board[residy + 1][residx - 1] == 1)
                countNeighbors++;
            if (board[residy][residx] == 1 && ( residy  + 1) < board[residy].size() && ( residx  + 1) < board[residy].size() && board[residy + 1][residx + 1] == 1)
                countNeighbors++;
            return (countNeighbors >= 2);
        }
        // static bool _down(short residx, short residy, vector<vector<int>>& board)
        // {
        //     short x = 0;
        //     short y = 0;
               
        // }
        // static bool _left(short residx, short residy, vector<vector<int>>& board)
        // {
        //     short x = 0;
        //     short y = 0;
               
        // }
        // static bool _right(short residx, short residy, vector<vector<int>>& board)
        // {
        //     short x = 0;
        //     short y = 0;
               
        // }
        // static bool _horizontal(short residx, short residy, vector<vector<int>>& board)
        // {
        //     short x = 0;
        //     short y = 0;
               
        // }
        // static bool _diagonal(short residx, short residy, vector<vector<int>>& board)
        // {
        //     short x = 0;
        //     short y = 0;
               
        // }

        // static bool _CheckNeighbors(short resid, vector<vector<int>>& board)
        // {
        //     if (board[0]);
        // }
public:
    static void gameOfLife(vector<vector<int>>& board)
    {
        if (_underPopulation(0,0, board))
            std::cout << "Population :-)\n";
        else
            std::cout << "Under Population :-)\n";
    }
};
int main(void)
{
    vector<vector<int>>board= {{1},{0},{1},{0}};

}