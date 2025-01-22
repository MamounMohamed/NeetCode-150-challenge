class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = nums.size() - count(nums.begin(), nums.end(), val);
        int idx = k ;
        for(int i = 0 ; i< k ; i++){
            if(nums[i]==val){
                while(idx<nums.size() && nums[idx] == val){
                    idx++;
                }
                swap(nums[i],nums[idx]);
            }
        }
        return k;
    }
}

;