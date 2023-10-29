class Solution {
public:
    int a = 0, e = 1, i = 2, o = 3, u = 4;
    
    int countVowelStrings(int n) {
        
        long long t[5][n+1];
        //t[i][j] = number of strings ending at i vowel habing length j

        for(int vowel = 0; vowel <= 4; vowel++) {
            t[vowel][1] = 1;
        }

        for(int len = 2; len <= n; len++) {
            t[a][len] = t[a][len-1];

            t[e][len] = (t[a][len-1] + t[e][len-1]);

            t[i][len] = (t[a][len-1] + t[e][len-1] + t[i][len-1]);

            t[o][len] = (t[a][len-1] + t[e][len-1] + t[i][len-1] + t[o][len-1]);

            t[u][len] = (t[a][len-1] + t[e][len-1] + t[i][len-1] + t[o][len-1] + t[u][len-1]);
        }

        //t[a][n] + t[e][n] + t[i][n]....
        long long result = 0;
        for(int vowel = 0; vowel <= 4; vowel++) {
            result = (result + t[vowel][n]);
        }
        return result;
    }
};