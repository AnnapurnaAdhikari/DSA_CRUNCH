// class Solution {
// public:
//     int countMajoritySubarrays(vector<int>& nums, int target) {
//         // approach 1
//         // if(find(nums.begin(), nums.end(), target) == nums.end()) return 0;
//         // int n = nums.size();
//         // int tot = 0;
//         // for(int i = 0; i < n; i++){
//         //     int count = 0; //diff b/w occur of target and non-targets
//         //     for(int j = i; j < n; j++){
//         //         count += (nums[j] == target)? 1:-1;
//         //         if(count > 0) tot++; 

//         //     }
//         // }
//         // return tot;

//         //approach 2
//         // int n = nums.size();
//         // long long cnt = 0;

//         // for (int i = 0; i < n; i++) {
//         //     if (nums[i] == target) nums[i] = 1;
//         //     else nums[i] = -1;
//         // }

//         // vector<int> pref(n);
//         // pref[0] = nums[0];

//         // for (int i = 1; i < n; i++) {
//         //     pref[i] = pref[i - 1] + nums[i];
//         // }

//         // int shift = n;
//         // vector<int> freq(2 * n + 1, 0);

//         // freq[shift] = 1;

//         // long long valid = 0;
//         // int lastSum = 0;

//         // for (int i = 0; i < n; i++) {
//         //     if (pref[i] > lastSum) {
//         //         valid += freq[lastSum + shift];
//         //     } else {
//         //         valid -= freq[pref[i] + shift];
//         //     }

//         //     cnt += valid;
//         //     freq[pref[i] + shift]++;
//         //     lastSum = pref[i];
//         // }

//         // return cnt;


//          int size = nums.size(), pref = size;

//         vector<int> freq(2 * size + 1);
//         freq[size] = 1;

//         long long less = 0, ans = 0;

//         for (int num : nums) {
//             if (num == target)
//                 less += freq[pref++];
//             else
//                 less -= freq[--pref];

//             ++freq[pref];
//             ans += less;
//         }

//         return ans;
//     }
// };
    
    class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        // represents the occurrence count of prefix sums -n, -(n-1), ..., 0, 1,
        // ..., n, with index offset by n.
        vector<int> pre(n * 2 + 1, 0);
        pre[n] = 1;
        int cnt = n;
        long long ans = 0, presum = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == target) {
                presum += pre[cnt];
                ++cnt;
                ++pre[cnt];
            } else {
                --cnt;
                presum -= pre[cnt];
                ++pre[cnt];
            }
            ans += presum;
        }
        return ans;
    }
};