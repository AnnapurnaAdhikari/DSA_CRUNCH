class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int>ele;
        for(int x: nums){
            if(ele.find(x) != ele.end()) return true;
            ele.insert(x);
        }
        return false;
    }
};