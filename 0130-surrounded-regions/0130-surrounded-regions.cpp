class Solution {
private:
    void dfs(int row, int col, vector<vector<int>> &vis, 
    vector<vector<char>> &board, int delrow[], int delcol[]) {
        vis[row][col] = 1; 
        int n = board.size();
        int m = board[0].size();
        
        // check for top, right, bottom, left 
        for(int i = 0;i<4;i++) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i]; 
            // check for valid coordinates and unvisited Os
            if(nrow >=0 && nrow <n && ncol >= 0 && ncol < m 
            && !vis[nrow][ncol] && board[nrow][ncol] == 'O') {
                dfs(nrow, ncol, vis, board, delrow, delcol); 
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int n= board.size();
        int m= board[0].size();
        
        vector<vector<int>> vis(n, vector<int>(m,0));
        int delrow[]= {-1,0,1,0};
        int delcol[]= {0,1,0,-1};
        for(int i=0;i<m;i++)
        {
            if(board[0][i]=='O' && !vis[0][i])
            {
                dfs(0,i,vis,board,delrow,delcol);
            }
            if(board[n-1][i]=='O' && !vis[n-1][i])
            {
                dfs(n-1,i,vis,board,delrow,delcol);
            }
        }
        
        for(int i=0;i<n;i++)
        {
            if(board[i][0]=='O' && !vis[i][0])
            {
                dfs(i,0,vis,board,delrow,delcol);
            }
            if(board[i][m-1]=='O' && !vis[i][m-1])
            {
                dfs(i,m-1,vis,board,delrow,delcol);
            }
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]=='O' && !vis[i][j])
                {
                    board[i][j]='X';
                }
            }
        }
    }
};