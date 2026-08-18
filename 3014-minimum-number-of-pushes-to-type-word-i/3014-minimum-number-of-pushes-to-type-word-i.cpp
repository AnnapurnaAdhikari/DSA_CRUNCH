class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        int cost = 0;
        if(n <= 8) return n;
        int push = n/8;
        int rem = n%8;
        for(int i = 1; i<= push; i++) cost += i*8;
        cost += (push+1)*rem;
        return cost;
    }
};