class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        int minsize=1000;
        int count=0;
        string s;
        for(int i=0;i<n;i++)
        {
            if(strs[i].size()<minsize)
            {
                minsize= strs[i].length();
                s=strs[i];
            }
            
        }
        
        for(int i=0;i<minsize;i++)
        {
            char ch=s[i];
            for(int j=0;j<n;j++)
            {
                string temp= strs[j];
                if(temp[i]!=ch)
                {
                    return s.substr(0,count);
                }
            }
            count++;
        }
        return s.substr(0,count);
    }
};