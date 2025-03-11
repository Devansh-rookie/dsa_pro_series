class Solution {
public:
    int numberOfSubstrings(string s) {
        // similar to yesterday we have to have ans += n - right; as we have atleast there its aneasy part of the previous question. as there we had atleastk - atleastk+1
        // and for vowels we have a map
        unordered_map<char, int> m;
        int left = 0;
        int ans = 0;
        int n = s.length();
        // 2 parts of for loop one is the increase right other is the decrease left
        for(int right = 0;right < n;right++){
            m[s[right]]++;
            while(m.size() == 3){
                ans += n - right;
                m[s[left]]--;
                if(m[s[left]] == 0){
                    m.erase(s[left]);
                }
                left++;
            }
        }
        return ans;
    }
};
