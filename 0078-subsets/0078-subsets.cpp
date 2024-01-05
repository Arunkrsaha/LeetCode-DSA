class Solution {
public:
    void generateSubsets(int ind, int n, vector<int> &temp, 
                         vector<vector<int>> &ans, vector<int>& nums)
    {
        if(ind>=n)
        {
            ans.push_back(temp);
            return;
        }
        
        temp.push_back(nums[ind]);
        generateSubsets(ind+1, n, temp, ans, nums);
        temp.pop_back();
        generateSubsets(ind+1, n, temp, ans, nums);
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        int n= nums.size();
        generateSubsets(0,n,temp,ans,nums);
        return ans;
    }
};