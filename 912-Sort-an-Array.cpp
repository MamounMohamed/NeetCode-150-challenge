class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        vector<int> heap(nums.size() + 1, -1e9);
        int n = heap.size() - 1;
        int sz = 0;
        for (int i = 0; i < nums.size(); i++) {
            int idx = sz + 1;
            heap[idx] = nums[i];
            while (idx / 2 && heap[idx] > heap[idx / 2]) {
                swap(heap[idx], heap[idx / 2]);
                idx /= 2;
            }
            sz++;
        }

        while (sz) {
            swap(heap[1], heap[sz]);
            int idx = 1;
            while (2 * idx < sz) {
                int left = 2 * idx, right = 2 * idx + 1;
                if (right < sz && heap[right] > heap[left] &&
                    heap[right] > heap[idx]) {
                    swap(heap[right], heap[idx]);
                    idx = right;
                } else if (left < sz && heap[left] > heap[idx]) {
                    swap(heap[left], heap[idx]);
                    idx = left;
                }
                else{
                    break;
                }
            }

            sz--;
        }
        return vector<int>(heap.begin() + 1, heap.end());
    }
};