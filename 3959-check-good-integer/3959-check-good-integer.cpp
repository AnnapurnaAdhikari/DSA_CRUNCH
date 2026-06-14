class Solution {
public:
    bool checkGoodInteger(int n) {
        int digSum = 0, sqSum = 0;
        int nDup = n;
        while(n){
            int dig = n % 10;
            digSum += dig;
            sqSum += dig*dig;
            n = n/10;
        }
        return sqSum - digSum >= 50;
    }
};