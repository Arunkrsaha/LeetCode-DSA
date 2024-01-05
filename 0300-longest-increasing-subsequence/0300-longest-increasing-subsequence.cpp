class Solution {
public:
    int solve(vector<int> &ans, vector<int>& nums, int i)
    {
        int size=ans.size();
        for(int j=0;j<size;j++)
        {
            if(ans[j]>=nums[i])
            {
                ans[j]=nums[i];
                return 1;
            }
        }
        return 0;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n= nums.size();
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            if(solve(ans,nums,i)==0)
            {
                ans.push_back(nums[i]);
            }
        }
        return ans.size();
    }
};