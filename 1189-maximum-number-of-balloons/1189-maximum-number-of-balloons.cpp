class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int>charFreq;
        for(char ch: text) {
            if(string("balloon").find(ch) != string::npos) charFreq[ch]++;
        }
        int ans = min({
            charFreq['b'],
            charFreq['a'],
            charFreq['l']/2,
            charFreq['o']/2,
            charFreq['n']     
        });
        return ans;
    }
};