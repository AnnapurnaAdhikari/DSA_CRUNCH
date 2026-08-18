class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int>missing = {};
        int n = nums.size();
        map<int, int>freq;
        sort(nums.begin(), nums.end());
        if(nums[n-1] - nums[0]+1 == n) return {};
        for(int i = nums[0]; i <= nums[n-1]; i++){
           freq[i] = 0;
        }
        for(int x: nums)freq[x]++;
        for(const auto& it: freq){
            if(it.second == 0) missing.push_back(it.first);
        }
        return missing;
    }
};