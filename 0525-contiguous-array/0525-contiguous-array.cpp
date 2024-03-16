class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> mp;
        int sum = 0;
        int max_length = 0;
        
        for(int i=0;i<nums.size();i++)
        {
            sum += nums[i]==0?-1:1;
            
            if(sum == 0)
            {
                if(max_length < i+1)  max_length = i+1;
            }
            else if(mp.find(sum) != mp.end())
            {
                if(max_length < i-mp[sum])  max_length = i-mp[sum];
            }
            else
            {
                mp[sum] = i;
            }
        }
        return max_length;
    }
};