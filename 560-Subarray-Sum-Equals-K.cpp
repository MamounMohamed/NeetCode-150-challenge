class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        const int N = nums.size() + 1 ;
        vector<int> prefixSum (N,0);
        int idx = 1 , ans = 0 ;
        for (const int& num : nums) {
            prefixSum[idx] = num + prefixSum[idx - 1];
            idx++;
        }

        for (int l = 1; l < N; l++) {
            for (int r = l; r < N; r++) {
                int sum = prefixSum[r] - prefixSum[l - 1];
                if (sum == k)
                    ans++;
            }
        }
        return ans;
    }
};