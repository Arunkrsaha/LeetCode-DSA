class Solution {
public:
    bool check(string s, string t) {
        unordered_map<char, char> umap;
        
        for(int i=0;i<s.size();i++)
        {
            if(umap.find(s[i]) != umap.end())
            {
                if(umap[s[i]] != t[i]) return false;
            }
            else
            {
                umap[s[i]]=t[i];
            }
        }
        return true;
    }
    
    bool isIsomorphic(string s, string t) {
        int n1= s.size();
        int n2= t.size();
        if(n1!=n2)
        {
            return false;
        }
        return check(s,t) && check(t,s);
    }
};