class Solution {
public:
    int minimumRecolors(string s, int k) {
        int maxBlack = 0;
        int n = s.length();
        for(int i = 0;i < k;i++){
            if(s[i] == 'B') maxBlack++;
        }
        int curr = 0;
        curr = maxBlack;
        for(int i = k;i < n;i++){
            if(s[i - k] == 'B'){
                curr--;
            }

            if(s[i] == 'B'){
                curr++;
            }

            maxBlack = max(maxBlack, curr);
        }
        return k - maxBlack;
    }
};
