using ll = long long;

class Solution {
public:
    bool check(map<char, int> &m, int k){
        string vow = "aeiou";
        for(char c: vow){
            if(m[c] < 1) return false;
        }
        return true;
    }
    long long atleastk(string word, int k){
        ll ans = 0;
        unordered_map<char, int> m;
        int n = word.size();
        unordered_set<char> vow;
        int conso = 0;
        vow.insert('a');vow.insert('e');vow.insert('i');vow.insert('o');vow.insert('u');
        int right;
        int left = 0;
        for(right = 0;right < n;right++){
            if(vow.find(word[right]) == vow.end()){
                conso++;
            }
            else{
                m[word[right]]++;
            }

            while(conso >= k && m.size() == 5){
                ans += n - right;
                if(vow.find(word[left]) == vow.end()){
                    conso--;
                }
                else{
                    m[word[left]]--;
                    if(!m[word[left]]) m.erase(word[left]);
                }
                left++;
            }
        }

        return ans;
    }
    long long countOfSubstrings(string word, int k) {
        return atleastk(word, k)-atleastk(word, k+1) ;// k+1 everything including and above k+1 and it is subtracted from atleast k which would include k and above so subtract then k would be left
    }
};
