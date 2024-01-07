class Solution {
public:
    bool canJump(vector<int>& nums) {
        // Initially final position is last index
        int destination = nums.size()-1;
        // Start with second last index
        for(int idx = nums.size()-2; idx>=0; idx--)
        {
            // If you can reach the destination then 
            // destination flag is equals to from where we can jump
            if(idx+nums[idx] >= destination)
            {
                destination = idx;
            }
        }
        // if destination at last is 0 then true if not then false
        return destination == 0;
    }
};