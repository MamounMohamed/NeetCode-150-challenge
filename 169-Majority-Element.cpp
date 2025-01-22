class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> cnt;
        for(const int & num : nums){
            cnt[num]++;
        }
        int mx = 1 , ans = nums[0] ; 
        for(unordered_map<int,int>::iterator itr = cnt.begin() ; itr != cnt.end() ; itr++){
            if(itr->second > mx){
                mx = itr->second;
                ans = itr->first;
            }
        }
        return ans;
    }
};