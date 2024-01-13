class Solution {
public:
    int minSteps(string s, string t) {
        int cnt[26] = {0}, ans = 0;
        for (char c : s) cnt[c - 'a']++;
        for (char c : t) cnt[c - 'a']--;
        for (int n : cnt) {
            if (n > 0) ans += n;
        }
        return ans;
    }
};