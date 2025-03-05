using ll = long long;

class Solution {
public:
    ll solve(int n){
        if(n == 1) return 1;
        return 1LL*4*(n-1) + solve(n-1);
    }
    long long coloredCells(int n) {
        // return solve(n);

        return 1LL * 2 * n * (n-1) + 1;
    }
};
