class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        // O(n + m) line sweep but I don't know about that 
        // O(n log m) BS I might know how to do that

        // can use all_of(start, end, lambda functions)
        // [](int x){if(x == 0)} kinda checks all
        int n = nums.size();
        int it = 0;
        for(it = 0;it < n;it++){
            if(nums[it]) break;
        }
        if(it == n) return 0;

        // apply binary search on K like what k is feasible kinda like the USACO and CSES problems and then check for the condition each time in the BS Loop that will take O(n) each time and total log k iterations so O(n log k)
        // always check smaller on type shit
        int low = 0;
        int high = queries.size();
        int ans = INT_MAX;
        while(low <= high){
            vector<int> diff(n+1, 0);
            int mid = low + (high - low)/2;
            int k = mid;
            // O(n + k) type here
            for(int i = 0;i < k;i++){
                int l = queries[i][0];
                int r = queries[i][1];
                int v = queries[i][2];
                diff[l] -= v;
                diff[r+1] += v;
            }

            for(int i = 0;i < n;i++){
                diff[i+1] += diff[i];
            }
            bool func = true;
            for(int i = 0;i < n;i++){
                if(diff[i] + nums[i] > 0){
                    func = false;
                    break;
                }
            }

            if(func){
                high = mid - 1;
                ans = mid;
            }
            else{
                low = mid + 1;
            }
        }
        if(ans != INT_MAX) return ans;
        return -1;
    }
};
