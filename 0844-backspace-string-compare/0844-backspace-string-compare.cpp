class Solution {
public:
    string cleanString(string &s) {
        vector<char> v;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != '#') {
                v.push_back(s[i]);
            }     else {
                if (!v.empty()) {
                    v.pop_back();
                }
            }
        }
        return string(v.begin(), v.end());
    }
    bool backspaceCompare(string s, string t) {
        return cleanString(s) == cleanString(t);
    }
};