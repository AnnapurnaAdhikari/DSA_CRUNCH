class Solution {
public:
    static constexpr int MOD = 1000000007;
    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;
        vector<int> dp(m, 1);

        for (int i = 2; i <= n; i++) {
            reverse(dp.begin(), dp.end());
            int sum = 0;
            for (auto& d : dp)
                sum = (sum + exchange(d, sum)) % MOD;
        }

        return ((accumulate(dp.begin(), dp.end(), 0LL) % MOD) << 1) % MOD;
    }
};

// class Solution {
// public:
//     int zigZagArrays(int n, int l, int r) {
//         int k = r - l + 1;
//         const int MOD = 1e9 + 7;

//         // Length 1 arrays
//         if (n == 1)
//             return k;

//         vector<vector<long long>> dp(k + 1,
//                                      vector<long long>(2, 0));

//         // Length 2 initialization
//         for (int v = 1; v <= k; v++) {
//             dp[v][0] = k - v; // previous element > v
//             dp[v][1] = v - 1; // previous element < v
//         }

//         // Build lengths 3 to n
//         for (int i = 3; i <= n; i++) {
//             vector<vector<long long>> nextDp(
//                 k + 1,
//                 vector<long long>(2, 0)
//             );

//             long long runSum0 = 0;

//             // Compute increasing states
//             for (int v = 1; v <= k; v++) {
//                 nextDp[v][1] = runSum0;
//                 runSum0 = (runSum0 + dp[v][0]) % MOD;
//             }

//             long long runSum1 = 0;

//             // Compute decreasing states
//             for (int v = k; v >= 1; v--) {
//                 nextDp[v][0] = runSum1;
//                 runSum1 = (runSum1 + dp[v][1]) % MOD;
//             }

//             dp = move(nextDp);
//         }

//         long long total = 0;

//         for (int v = 1; v <= k; v++) {
//             total = (total + dp[v][0]) % MOD;
//             total = (total + dp[v][1]) % MOD;
//         }

//         return (int)total;
//     }
// };