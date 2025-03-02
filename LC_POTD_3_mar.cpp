class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        map<int, int> m1;
        map<int, int> m2;
        int n = 0;
        int m = 0;
        n = nums1.size();
        m = nums2.size();
        int mx = nums1[0][0];
        for(int i = 0;i < n;i++){
            mx = max(mx, nums1[i][0]);
            m1[nums1[i][0]] = nums1[i][1];
        }
        for(int i = 0;i < m;i++){
            mx = max(mx, nums2[i][0]);
            m2[nums2[i][0]] = nums2[i][1];
        }

        vector<vector<int>> ans;
        for(int i = 1;i <= mx;i++){
            int val = m1[i] + m2[i];
            if(val) ans.push_back({i, val});
        }
        return ans;
    }
};
