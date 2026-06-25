class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        if(find(nums.begin(), nums.end(), target) == nums.end()) return 0;
        int n = nums.size();
        int tot = 0;
        for(int i = 0; i < n; i++){
            int count = 0; //diff b/w occur of target and non-targets
            for(int j = i; j < n; j++){
                // auto most_frequent_iter = max_element(nums.begin() + i, nums.begin() + j + 1, []
                // (const auto& a, const auto& b){return a.second < b.second;});
                // if(target == *most_frequent_iter) tot++;
                // if(*max_element(nums.begin()+i, nums.begin() + j))
                // if(count(nums.begin()+i, nums.begin()+j+1,target) > (j-i+1)/2) tot++;
                count += (nums[j] == target)? 1:-1;
                if(count > 0) tot++; 

            }
        }
        return tot;
    }
};