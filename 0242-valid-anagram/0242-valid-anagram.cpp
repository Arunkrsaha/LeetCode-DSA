class Solution {
public:
    bool isAnagram(string s, string t) {
        int n1 = s.length();
        int n2 = t.length();
        
        if(n1 != n2)
        {
            return false;
        }
        
        unordered_map<char, int> smap;
        
        for(int i=0;i<n1;i++)
        {
            smap[s[i]]++;
        }
        
        for(int i=0;i<n2;i++)
        {
            if(smap[t[i]]<=0)
            {
                return false;
            }
            else
            {
                smap[t[i]]--;
            }
        }
        return true;
    }
};