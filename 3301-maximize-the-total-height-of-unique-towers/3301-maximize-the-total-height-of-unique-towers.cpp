class Solution {
public:
    long long maximumTotalSum(vector<int>& maxHt) {
        sort(maxHt.begin(), maxHt.end(), greater<int>());
        long long sum = 0;
        int prev = INT_MAX;
        for(int h: maxHt){
            int curr = min(h, prev-1);
            if(curr == 0)return -1;
            sum+=curr;
            prev = curr;
        }
        return sum;
    }
};