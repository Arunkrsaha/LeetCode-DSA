class Solution {
public:
    string longestPalindrome(string str) {
        int n = str.length();
        int dp[n][n];
        int maxLength=1;
        int start = 0;
        int end = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
            {
                dp[i][j] = 0;
            }
        }
        for(int i=0;i<n;i++)
        {
            dp[i][i] = 1;
        }
        for(int i=0;i<n;i++)
        {
            if(str[i]==str[i+1])
            {
                dp[i][i+1] = 1;
                if(maxLength<2)
                {
                start = i;
                end = i+1;
                maxLength = 2;
                }
            }
        }
        for(int i=2;i<n;i++){
            for(int j=0,k=i;j<n-i,k<n;j++,k++){
                if(str[j]==str[k] && dp[j+1][k-1]==1)
                {
                    dp[j][k] = 1;
                    if(maxLength<abs(k-j+1))
                    {
                    start = j;
                    end = k;
                    maxLength = max(maxLength,abs(k-j+1));
                    }
                }
            }
        }
        return str.substr(start,end-start+1);
    }
};