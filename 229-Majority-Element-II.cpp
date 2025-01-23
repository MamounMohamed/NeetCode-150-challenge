class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> cnt;
        int sz = nums.size() / 3;
        vector<int> ans;
        for (const int& num : nums) {
            cnt[num]++;
        }

        for (unordered_map<int, int>::iterator itr = cnt.begin(); itr != cnt.end(); itr++) {
            if (itr->second > sz) {
                ans.push_back(itr->first);
            }
        }
        return ans;
    }
};