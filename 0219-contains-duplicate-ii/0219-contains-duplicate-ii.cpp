class Solution {
public:
    // bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
    //     // // sort(nums.begin(), nums.end());
    //     // for(int i = 0; i < nums.size(); i++){
    //     //     for(int  j = i+1; j < nums.size(); j++){
    //     //         if(nums[i] == nums[j] && abs(i-j) <= k) return true;
    //     //     }
    //     // }
    //     // return false;

    // }
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> lastIndex;

        for (int i = 0; i < nums.size(); i++) {
            if (lastIndex.find(nums[i]) != lastIndex.end()) {
                if (i - lastIndex[nums[i]] <= k)
                    return true;
            }

            lastIndex[nums[i]] = i;
        }

        return false;
    }
};