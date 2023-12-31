class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int n= s.length();
        int result = -1;
        vector<int> count(26, -1);
        for(int i=0;i<n;i++)
        {
            char ch=s[i];
            if(count[ch-'a']==-1)
            {
                count[ch-'a']=i;
            }
            else
            {
                result=max(result,(i-count[ch-'a']-1));
            }
        }
        return result;
    }
};