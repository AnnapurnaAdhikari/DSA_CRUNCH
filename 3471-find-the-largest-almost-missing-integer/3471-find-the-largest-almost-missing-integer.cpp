class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int, int>freq;
        int n = nums.size();
        for(int i = 0; i < n; i++) freq[nums[i]]++;
            if(n == k ) return *max_element(nums.begin(), nums.end());
            if(k==1) {
                sort(nums.begin(), nums.end(), greater<int>());
                for(int x: nums){
                    if(freq[x] == 1) return x;
                }
            }
            if(freq[nums[0]] == 1 && freq[nums[n-1]]==1) return max(nums[0], nums[n-1]);
            else if(freq[nums[0]]==1) return nums[0];
            else if(freq[nums[n-1]]==1) return nums[n-1];
        return -1;
    }
};