class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n= nums.size();
        if(n<=1)
        {
            return n;
        }
        int i=0;
        int j=1;
        while(j<n)
        {
            if(nums[i]==nums[j])
            {
                j++;
            }
            else
            {
                i=i+1;
                nums[i]=nums[j++];
            }
        }
        return i+1;
    }
};