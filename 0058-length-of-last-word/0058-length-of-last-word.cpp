class Solution {
public:
    int lengthOfLastWord(string s) {
        int last= s.length()-1;
        int count=0;
        for(int i=last;i>=0;i--)
        {
            if(s[i] != ' ')
            {
                count++;
            }
            else if(count>0 && s[i]==' ')
            {
                break;
            }
        }
        return count;
    }
};