class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, int> charToIndex;
        unordered_map<string, int> wordToIndex;
        
        int n= pattern.length();
        
        stringstream ss(s);
        string token;
        int countTokens=0;
        int i=0;
        
        while(ss>>token)
        {
            countTokens++;
            
            if(i==n || charToIndex[pattern[i]] != wordToIndex[token])
            {
                return false;
            }
            
            charToIndex[pattern[i]]= i+1;
            wordToIndex[token]= i+1;
            i++;
        }
        if(countTokens != n || i!=n)
        {
            return false;
        }
        return true;
    }
};