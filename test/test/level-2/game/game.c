#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    if (argc != 4)
        return (1);
    int h = atoi(argv[1]);
    int w = atoi(argv[2]); 
    int iter = atoi(argv[3]);
    char board[h][w];
    char temp[h][w];
    for (int i = 0; i < h; i++)
    {
        for (int  j = 0; j < w; j++)
        {
            board[i][j]=1;
        }
        
    }
    char c;
    int pen = 0;
    int y = 0;
    int x = 0;
    int pen = 0;
    while (read(0, &c, 1) > 0)
    {
        if (c == 'w' && y  > 0)
            y--;
        else if (c == 's' &&  y < h - 1)
            y++;
        else if (c == 'a' && x > 0)
            x--;
        else if (c == 'd' && x < w -1)
            x++;
        if (c == 'x')
            pen= !pen;
        if (pen)
            board[y][x] = 1;
    }
    for (; iter > 0 ; iter--)
    {
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
               int emp = 0;
               for (int dy = -1; dy <= 1; dy++)
               {
                    for (int dx = -1; dx <= 1; dx++)
                    {
                        if (dy == 0 && dx)
                            continue;
                        int iy = dy + i;
                        int ix = dx + j;
                        if (iy >= 0 && iy < h && ix >= 0 && ix < w)
                        {
                            if (board[iy][ix] == 1)
                                emp++;
                        }
                    }
                    
               }
               
            }
        
        }
        
    }
    
    return 0;
}
