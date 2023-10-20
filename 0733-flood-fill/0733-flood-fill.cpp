class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int newColor, 
    vector<vector<int>> &ans, int inicolor, int delrow[], int delcol[])
    {
        ans[sr][sc]=newColor;
        int n=image.size();
        int m=image[0].size();
        for(int i=0;i<4;i++)
        {
            int nrow=sr+delrow[i];
            int ncol=sc+delcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && 
            image[nrow][ncol]==inicolor && ans[nrow][ncol]!=newColor)
            {
                dfs(image,nrow,ncol,newColor,ans,inicolor,delrow,delcol);
            }
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int inicolor=image[sr][sc];
        vector<vector<int>> ans=image;
        
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        dfs(image,sr,sc,newColor,ans,inicolor,delrow,delcol);
        return ans;
    }
};