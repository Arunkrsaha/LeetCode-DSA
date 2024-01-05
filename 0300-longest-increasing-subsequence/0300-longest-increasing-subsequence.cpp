class Solution {
public:
    int n;
    int t[2501][2501];
    int solve(int curr, int prev, vector<int> &nums)
    {
        if(curr>=n)
        {
            return 0;
        }
        if(prev != -1 && t[curr][prev] != -1)
        {
            return t[curr][prev];
        }
        int take=0;
        if(prev==-1 || nums[curr]>nums[prev])
        {
            take= 1+solve(curr+1,curr, nums);
        }
        int skip= solve(curr+1, prev, nums);
        if(prev!=-1)
            t[curr][prev]=max(take, skip);
        
        return max(take, skip);
    }
    int lengthOfLIS(vector<int>& nums) {
        n=nums.size();
        memset(t,-1,sizeof(t));
        return solve(0,-1, nums);
    }
};