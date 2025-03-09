class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& col, int k) {
        vector<int> nw = col;
        col.insert(col.end(), nw.begin(), nw.end());
        int n = col.size();
        int ans = 0;
        int lenn = 0;
        for(int i = 0;i < n/2 + k - 1;i++){
            if(col[i] != col[i+1]){
                lenn++;
            }
            else lenn = 1;
            if(lenn >= k) ans++;
        }
        return ans;
    }
};
