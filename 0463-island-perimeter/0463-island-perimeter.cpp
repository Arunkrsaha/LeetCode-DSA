class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int answer = 0;
        int x = grid.size(), y = grid[0].size();
        for(int i = 0; i < x ; i++)
        {
            for(int j = 0; j < y; j++)
            {
                if(grid[i][j] == 1)
                {
                    answer += 4;
                    // Upper
                    if(i - 1 >= 0)
                    {
                        if(grid[i-1][j] == 1)
                            answer -= 1;
                    }
                    // Lower
                    if(i + 1 < x)
                    {
                        if(grid[i+1][j] == 1)
                            answer -= 1;
                    }
                    // Left
                    if(j - 1 >= 0)
                    {
                        if(grid[i][j-1] == 1)
                            answer -= 1;
                    }
                    // Right
                    if(j + 1 < y)
                    {
                        if(grid[i][j+1] == 1)
                            answer -= 1;
                    }
                }
                
            }
        }
        
        return answer;
    }
};