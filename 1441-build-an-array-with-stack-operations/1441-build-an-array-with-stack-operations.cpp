class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        
        vector<string> ans;
        int i = 1, j = 0;
        while (j < target.size()) {
            while (i != target[j]) {
                ans.push_back("Push");
                ans.push_back("Pop");
                ++i;
            } 
            ans.push_back("Push");
            ++i;
            ++j;
        }
        return ans;
        
    }
};