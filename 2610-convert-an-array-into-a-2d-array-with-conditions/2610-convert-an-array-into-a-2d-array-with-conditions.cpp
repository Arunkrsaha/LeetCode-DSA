class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> ans;
        unordered_map<int, int> mp;
        
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        
        int height=0;
        for(auto it: mp)
        {
            if(it.second>=height)
            {
                height= it.second;
            }
        }
        for(int i=0;i<height;i++)
        {
            vector<int> temp;
            for(auto &it: mp)
            {
                if(it.second > 0)
                {
                    it.second--;
                    temp.push_back(it.first);
                    
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};