class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {

        unordered_map<int,int> freq;

        freq[0] = 1;

        int prefix = 0;
        int ans = 0;

        for(int num : nums){

            prefix += num;

            int rem = ((prefix % k) + k) % k;

            ans += freq[rem];

            freq[rem]++;
        }

        return ans;
    }
};