class Solution {
private:
    void dfs(int node,vector<int> adjls[], vector<bool> &vis)
    {
        vis[node]=1;
        for(auto it: adjls[node])
        {
            if(!vis[it])
            {
                dfs(it,adjls,vis);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size(); 
        vector<int> adjls[V];
        
        // To change adjacency matrix to list
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<V;j++)
            {
                if(isConnected[i][j]==1 && i!=j)
                {
                    adjls[i].push_back(j);
                    adjls[j].push_back(i);
                }
            }
        }
        vector<bool> vis(V,false);
        int cnt=0;
        // Travese whole visited vector        
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                cnt++; // Every time when we get not visited element increase count by one 
                dfs(i,adjls,vis);
            }
        }
        return cnt;
    }
};