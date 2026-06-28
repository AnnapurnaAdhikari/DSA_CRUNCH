class Solution {
public:
    vector<int> digs(int n){
        vector<int>d;
        while(n){
            int dig = n% 10;
            d.push_back(dig);
            n /= 10;
        }
        return d;
    }
    int digitFrequencyScore(int n) {
        vector<int>d = digs(n);
        unordered_map<int, int>freq;
        int ans = 0;
        for(int x: d){
           freq[x]++;
        }
        for(auto& it: freq){
            ans+= it.first*it.second;
        }
        return ans;
    }
};