class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        string &s = strs[0], ans = s;
        int mn = s.size();
        for (int i = 1; i < strs.size(); i++) {
            for (int j = 0; j < min(s.size(), strs[i].size()); j++) {
                if (s[j] != strs[i][j]) {
                    if (j < mn) {
                        mn = j;
                        ans = strs[i].substr(0, j);
                    }
                    break;
                }
            }
            if (strs[i].size() < mn) {
                mn = strs[i].size();
                ans = strs[i];
            }
        }
        return ans;
    }
};