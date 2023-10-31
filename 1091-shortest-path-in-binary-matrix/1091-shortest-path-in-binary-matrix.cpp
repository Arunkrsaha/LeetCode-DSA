class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        // Create a queue for storing cells with their distances from source
        // in the form {dist,{cell coordinates pair}}.
        queue<pair<int, pair<int, int>>> q;
        int n = grid.size();

        // Edge Case: if the source is only the destination.
        if (n == 1 && grid[0][0]==0)
            return 1;
        if(grid[0][0]==1)
            return -1;
        
        // Create a distance matrix with initially all the cells marked as
        // unvisited and the source cell as 0.
        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        dist[0][0] = 1;
        q.push({1, {0, 0}});
        
        // Iterate through the maze by popping the elements out of the queue
        // and pushing whenever a shorter distance to a cell is found.
        while (!q.empty())
        {
            auto it = q.front();
            q.pop();
            int dis = it.first;
            int r = it.second.first;
            int c = it.second.second;

            // Through this loop, we check the 4 direction adjacent nodes
            // for a shorter path to destination.
            for (int delr = -1; delr <= 1; delr++)
            {
                for(int delc = -1; delc <= 1; delc++)
                {
                    int newr = r + delr;
                    int newc = c + delc;

                    // Checking the validity of the cell and updating if dist is shorter.
                    if (newr >= 0 && newr < n && newc >= 0 && newc < n && grid[newr][newc] 
                    == 0 && dis + 1 < dist[newr][newc])
                    {
                        dist[newr][newc] = 1 + dis;

                        // Return the distance until the point when
                        // we encounter the destination cell.
                        if (newr == n-1 &&
                            newc == n-1)
                            return dis + 1;
                        q.push({1 + dis, {newr, newc}});
                    }
                }
            }
        }
        // If no path is found from source to destination.
        return -1;
    }
};