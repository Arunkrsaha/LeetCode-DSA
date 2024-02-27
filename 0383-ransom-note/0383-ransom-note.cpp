class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> umap;
        for(int i=0;i<magazine.length();i++)
        {
            char ch= magazine[i];
            umap[ch]++;
        }
        for(int i=0;i<ransomNote.size();i++)
        {
            char c = ransomNote[i];
            if(umap.find(c)==umap.end())
            {
                return false;
            }
            else if(umap[c]<=0)
            {
                return false;
            }
            umap[c]--;
        }
        return true;
    }
};