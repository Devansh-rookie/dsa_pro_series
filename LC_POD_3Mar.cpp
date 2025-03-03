class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        size_t n = nums.size();
        vector<int> ans(n, pivot);
        int k = 0;
        int equals = 0;
        for(size_t i = 0;i < n;i++){
            if(nums[i] < pivot) ans[k++] = nums[i];
            if(nums[i] == pivot) equals++;
        }

        for(size_t i = 0;i < n;i++){
            if(nums[i] > pivot) ans[equals + k++] = nums[i];
        }

        return ans;
    }
};
