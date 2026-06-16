class Solution {
public:
    string processStr(string s) {
        char STAR = '*', HASH = '#', PER = '%';
        string res = "";
        for(char letter: s){
            if(isalpha(letter)) res.push_back(letter);
            else if(letter == STAR && res.size() > 0) res.pop_back();
            else if(letter == HASH) res += res;
            else if (letter == PER) reverse(res.begin(), res.end());
        }
        return res;
    }
};