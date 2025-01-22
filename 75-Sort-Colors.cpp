class Solution {
public:

    void  quickSort (vector<int> & nums , int l , int r){
        if (l>=r)
            return ; 
        int pi = partitionWork(nums,l,r);
        quickSort(nums , l , pi-1) ;
        quickSort(nums, pi +1 , r);

    }

    int partitionWork (vector<int> & nums , int l , int r ){

        int idx = l ; 
        for(int i = idx ; i<r ; i++){
            if(nums[r] > nums[i]){
                swap(nums[idx] , nums[i]);
                idx++;
            }
        }
    swap(nums[idx],nums[r]);
    return idx;


    }
    void sortColors(vector<int>& nums) {

        quickSort(nums,0,nums.size()-1);
        
    }
};