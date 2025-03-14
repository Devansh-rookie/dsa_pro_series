using ll = long long;
class Solution {
public:
    int maximumCandies(vector<int>& nums, long long k) {
        ll low = 1; // also the ans covers the 0 values if nothing is valid

        ll high = *max_element(nums.begin(), nums.end());
        ll mid;
        int n = nums.size();
        if(n == 1) return nums[0]/k;
        ll ans = 0;
        while(low <= high){
            mid = low + (high - low)/2;
            // if(!mid) return 0;
            bool valid = false;
            ll howManyChild = 0;
            // calc how many children can be satisfied if its >= k then valid else invalid
            // for one child 1 pile so, nums[i] / mid, the mid is the max number of candies direct GIF basically.
            for(int i = 0;i < n;i++){
                howManyChild += nums[i]/mid;
            }
            if(howManyChild >= k) valid = true;
            if(valid){
                // this would ive the best valid response always use this ig to reduce errors in BS
                ans = mid;
                low = mid + 1;
            }
            else high = mid - 1;
        }
        return ans;
    }
};
