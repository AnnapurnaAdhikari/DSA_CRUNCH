class Solution {
public:
    int maxProduct(int n) {
        string strn = to_string(n);
        vector<int> digs;
        for(char ch: strn){
            digs.push_back(ch-'0');
        }
        sort(digs.rbegin(), digs.rend());
        return digs[0]*digs[1];
    }
};