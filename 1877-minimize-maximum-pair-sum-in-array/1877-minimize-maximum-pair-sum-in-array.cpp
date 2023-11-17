class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int mx = 0;
        int l=0,r=nums.size()-1;
        sort(nums.begin(),nums.end());
        
        while(l<r){
            mx = max(mx,nums[l]+nums[r]);
            ++l;
            --r;
        }
        return mx;
    }
};