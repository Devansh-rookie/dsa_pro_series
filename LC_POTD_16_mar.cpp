using ll = long long;

class Solution {
public:
    bool check(vector<int> &ranks, int cars, ll mid){
        // t = r*n^2
        // root(t / r) = n, n is the number of cars, use the nuber of cars sumation like what is the max number of cars GIF that can be done here sumation over all as parallel processing, fo rthe mid amount of time.
        // suma cars is more than cars then true else false
        ll temp_cars = 0;
        for(int i = 0;i < ranks.size();i++){
            temp_cars += (ll)sqrt(mid / ranks[i]);
            if(temp_cars >= cars) return true;
        }
        return false;
    }

    long long repairCars(vector<int>& ranks, int cars) {
        ll low = *min_element(ranks.begin(), ranks.end());
        ll high = *max_element(ranks.begin(), ranks.end())*1LL*cars*cars;
        sort(ranks.begin(), ranks.end());
        ll ans = 0;
        ll mid;
        while(low <= high){
            mid = low + (high - low)/2;
            if(check(ranks, cars, mid)){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
};
