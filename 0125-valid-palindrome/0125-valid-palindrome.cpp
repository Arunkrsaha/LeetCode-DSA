class Solution {
public:
    bool isPalindrome(string s) {
        string original;
        for(int i=0;i<s.length();i++)
        {
            char ch= s[i];
            if(ch>='A' && ch<='Z')
            {
                ch= (ch-'A')+'a';
                original+=ch;
            }
            else if(ch>='a' && ch<='z')
            {
                original+=ch;
            }
            else if('0' <= ch && ch <= '9')
            {
                original+=ch;
            }
        }
        int n= original.size();
        for(int i=0;i<n/2;i++)
        {
            if(original[i]!=original[n-1-i])
            {
                return false;
            }
        }
        return true;
    }
};