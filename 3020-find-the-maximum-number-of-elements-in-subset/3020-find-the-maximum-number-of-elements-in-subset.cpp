// class Solution {
// public:
//     int maximumLength(vector<int>& nums) {
//         // unordered_map<int, int>freq;
//         // for(int num: nums) freq[num]++;
//         // sort(nums.begin(), nums.end());
//         // int power = 2;
//         // int ct = 1;
//         // int maxCt = ct;
//         // for(int i = 0; i < nums.size(); i++){
//         //     // power += 2;
//         //     int n= nums[i];
//         //     if(n == 1 && freq[n]% 2) {
//         //         if(freq[n] > 1) maxCt = freq[n];
//         //         continue;}
//         //     else{

//         //         while(freq[pow(n, power)]){
//         //             if(freq[n] == 2)ct+=2;
//         //             n = pow(n, power);
//         //         }
//         //     }
//         //     maxCt = max(maxCt, ct);
//         //     cout<<maxCt<<" ";
//         //     ct  = 1;
//         // }
//         // return maxCt;


//         //correct code
//         unordered_map<long long, int> freq;

//         for (int x : nums)
//             freq[x]++;

//         int ans = 0;

//         // Handle 1 separately
//         if (freq.count(1)) {
//             if (freq[1] % 2)
//                 ans = max(ans, freq[1]);
//             else
//                 ans = max(ans, freq[1] - 1);
//         }

//         for (auto &[x, cnt] : freq) {
//             if (x == 1) continue;

//             long long cur = x;
//             int len = 0;

//             while (freq.count(cur) && freq[cur] >= 2) {
//                 len += 2;

//                 if (cur > 1000000000LL / cur) break; // avoid overflow
//                 cur *= cur;
//             }

//             if (freq.count(cur))
//                 len++;
//             else
//                 len--;

//             ans = max(ans, len);
//         }

//         return ans;
//     }
// };


class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> cnt;
        for (int num : nums) {
            cnt[num]++;
        }
        int ans = 0;
        // ans is at least the number of occurrences of 1, rounded down to an
        // odd number
        if (cnt[1] % 2 == 0) {
            ans = cnt[1] - 1;
        } else {
            ans = cnt[1];
        }
        cnt.erase(1);
        for (auto& [num, _] : cnt) {
            int res = 0;
            long long x = num;
            for (; cnt.contains(x) && cnt[x] > 1; x *= x) {
                res += 2;
            }
            ans = max(ans, res + (cnt.contains(x) ? 1 : -1));
        }
        return ans;
    }
};