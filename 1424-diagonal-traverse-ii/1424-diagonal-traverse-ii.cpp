class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int m = nums.size();
        if(m == 0) return vector<int>();
        vector<vector<int>> tuples;
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < nums[i].size(); j++){
                /*
                first sort by row index + col index, ascending,  
                and then by row index, descending
                */
                tuples.push_back({i+j, -i, nums[i][j]});
            }
        }
        
        sort(tuples.begin(), tuples.end());
        
        vector<int> ans(tuples.size());
        
        for(int i = 0; i < ans.size(); i++){
            ans[i] = tuples[i][2];
        }
        
        return ans;
    }
};