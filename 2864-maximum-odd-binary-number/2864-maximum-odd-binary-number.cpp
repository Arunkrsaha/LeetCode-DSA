class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n= s.size();
        int count1=0;
        int count0=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='1')
            {
                count1++;
            }
            else
            {
                count0++;
            }
        }
        string ans="";
        for(int i=0;i<n-1;i++)
        {
            if(i<count1-1)
            {
                ans+='1';
            }
            else
            {
                ans+='0';
            }
        }
        ans+='1';
        return ans;
    }
};