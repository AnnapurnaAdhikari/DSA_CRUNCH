class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int minOdd = INT_MAX;
        for(int x: nums1){
            if(x % 2) minOdd = min(minOdd, x);
        }
        // for even elements, if there exists an odd no great than it then it is convertible to an odd num
        // if there exists even no. lesser than min odd no present in the array then not possible to make n2
        for(int x: nums1){
            if(x % 2 == 0 && minOdd != INT_MAX && x < minOdd) return false;
        }
        return true;
    }
};