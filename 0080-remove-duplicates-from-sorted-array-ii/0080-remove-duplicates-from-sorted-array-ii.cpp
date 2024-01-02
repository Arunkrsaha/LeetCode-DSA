class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n= nums.size();
        if(n<2)
        {
            return n;
        }
        int i = 2;
        for(int j=2;j<n;j++)
        {
            if(nums[i-2]!=nums[j])
            {
                nums[i]=nums[j];
                i++;
            }
        }
        return i;
    }
};