class Solution {
public:

    void helper(vector<char>&s, int l, int r){
        if( l >= r) return;
        swap(s[l], s[r]);
        helper(s, l+1, r-1);
    }
    void reverseString(vector<char>& s) {
        //approach 1: brute force
        // int i = 0, j = s.size()-1;
        // while(i < j){
        //     swap(s[i], s[j]);
        //     i++; j--;
        // }

        //approach2: using recursion
        helper(s, 0, s.size() - 1);
        
    }
};