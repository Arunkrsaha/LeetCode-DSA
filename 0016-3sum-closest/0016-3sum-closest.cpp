class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int ans;
        int diff=INT_MAX;
        int l,r;
        for(int i=0;i<nums.size()-2;i++)
        {
            if(i>0 && nums[i]==nums[i-1])
            {
                continue;
            }
            l=i+1;
            r=nums.size()-1;
            while(l<r)
            {
                int sum=nums[i]+nums[l]+nums[r];
                if(sum==target)
                {
                    return sum;
                }
                else if(sum>target){
                    r--;
                }
                else
                {
                    l++;
                }  
                if(abs(target-sum) < diff){
                    diff = abs(target-sum);
                    ans = sum;
                }
            }
        }
        return ans;
    }
};