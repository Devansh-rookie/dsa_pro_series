class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int> ans(2, 0);
        int val = 0;
        int n = grid.size();
        long long suma = 0;
        long long sum_of_sq = 0;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                suma += grid[i][j];
                sum_of_sq += grid[i][j]*grid[i][j];
            }
        }

        long long actual_suma = 1LL*n*n*(n*n+1)/2;
        long long actual_sq_sum = 1LL*n*n*(2*n*n+1)*(n*n+1)/6;

        // y^2- x^2

        long long y_2_x_2 = actual_sq_sum - sum_of_sq;
        long long y_x = actual_suma - suma;

        long long yplusx = y_2_x_2/(y_x);

        ans[1] = (yplusx + y_x)/2;
        ans[0] = (yplusx - y_x)/2;
        return ans;
    }
};
