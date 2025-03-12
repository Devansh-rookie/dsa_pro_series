class Solution {
public:
    int lowerBound(vector<int>& nums, int k){
        int low = 0;
        int high = nums.size();
        int mid = 0;

        while(low < high){
            mid = low + (high - low)/2;
            if(nums[mid] <= k){
                low = mid + 1;
            }
            else{
                high = mid;
            }
        }
        return low;
    }

    int upperBound(vector<int>&nums, int k){
        int low = 0;
        int high = nums.size();
        int mid = 0;

        while(low < high){
            mid = low + (high - low)/2;
            if(nums[mid] < k){
                low = mid + 1;
            }
            else{
                high = mid;
            }
        }
        return low;
    }
    int maximumCount(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        // cout << lowerBound(nums, 0) << endl;
        // cout << upperBound(nums, 0);
        ans = max(n - lowerBound(nums, 0), upperBound(nums, 0));
        return ans;
    }
};
