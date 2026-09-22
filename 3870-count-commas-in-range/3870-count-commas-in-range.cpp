class Solution {
public:
    int countCommas(int n) {
        int tCommas = 0;
        if(to_string(n).size() >= 4) tCommas = (n-1000) + 1;
        return tCommas;
        // return( n % 10) + 1;

    }
};