class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        unordered_map<int, vector<int>> bucket;
        int maxKey = INT_MIN;
        int count = 0;
        
        for(int i = 0; i < nums.size(); i++){
            for(int j = 0; j < nums[i].size(); j++){
                bucket[i+j].push_back(nums[i][j]);
                maxKey = max(maxKey, i+j);
                count++;
            }
        }
        
        vector<int> ans(count);
        int idx = 0;
        
        for(int i = 0; i <= maxKey; i++){
            for(int j = bucket[i].size()-1; j >= 0; j--){
                ans[idx++] = bucket[i][j];
            }
        }
        
        return ans;
    }
};