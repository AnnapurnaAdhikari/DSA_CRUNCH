class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> firstIndex;
        firstIndex[0] = -1;

        int prefixSum = 0;

        for (int i = 0; i < nums.size(); i++) {
            prefixSum += nums[i];

            int rem = prefixSum % k;

            if (rem < 0)
                rem += k;

            if (firstIndex.count(rem)) {
                if (i - firstIndex[rem] >= 2)
                    return true;
            } else {
                firstIndex[rem] = i;
            }
        }

        return false;
    }
};