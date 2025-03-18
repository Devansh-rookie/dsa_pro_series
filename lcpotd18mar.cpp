
class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int left = 0;
        int right = 0;
        int n = nums.size();
        int ans = 1;
        // do bitwise OR to get all the set bits in the numbers till now
        // and then next val should have mask & ele = 0
        // the numbers which have to be remove would be removed since only one number can have the set bit at the same location so if any bit is eual then non 0
        // else this check function can be used to check all bits until its not zero anymore
        // 
        int mask = 0;
        for(;right < n;){
            while(right < n && ((mask & nums[right]) == 0)){
                mask = mask|nums[right];
                right++;
            }
            ans = max(ans, right - left);

            if(left < right){
                mask = mask ^ nums[left];
                left++;
            }
        }
        return ans;
    }
};

