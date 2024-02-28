class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> umap;
        
        for(int i=0;i<nums.size();i++)
        {
            if(umap.find(nums[i])==umap.end())
            {
                umap[nums[i]]=i;
            }
            else if(umap.find(nums[i])!=umap.end() && abs(i-umap[nums[i]])>k)
            {
                umap[nums[i]]=i;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};