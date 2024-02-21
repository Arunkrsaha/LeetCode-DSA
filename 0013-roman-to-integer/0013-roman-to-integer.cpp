class Solution {
public:
    int romanToInt(string s) {
        int n= s.length();
        map<char, int> roman;
        roman.insert(make_pair('I',1));
        roman.insert(make_pair('V',5));
        roman.insert(make_pair('X',10));
        roman.insert(make_pair('L',50));
        roman.insert(make_pair('C',100));
        roman.insert(make_pair('D',500));
        roman.insert(make_pair('M',1000));
        int ans=0;
        
        for(int i=0;i<n;)
        {
            if(i==n-1 || roman[s[i]]>=roman[s[i+1]])
            {
                ans+=roman[s[i]];
                i++;
            }
            else
            {
                ans+=(roman[s[i+1]]-roman[s[i]]);
                i+=2;
            }
        }
        return ans;
    }
};