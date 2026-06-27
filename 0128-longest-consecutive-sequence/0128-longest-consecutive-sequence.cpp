class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int count = 1;
        int maxCount  = count;
        if(nums.size() <= 1)return nums.size();
        for(int i = 0;i < nums.size() -1; i++){
            if(nums[i] == nums[i+1] -1) {count++; maxCount = max(maxCount, count);}
            else if(nums[i] == nums[i+1] )continue;
            else count = 1;
        }
        return maxCount;
        
    }
};