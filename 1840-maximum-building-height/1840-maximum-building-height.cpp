// class Solution {
// public:
//     int maxBuilding(int n, vector<vector<int>>& restrictions) {
//         unordered_map<int, int>res;
//         for(const auto& v: restrictions){
//             res[v[0]] = v[1];
//         }
//         vector<int>hts(n, 0);
//         hts[0] = 0;
//         for(int i = 1; i < n; i++){
//             if(res.count(i+1)){
//                 int hts_max = res[i+1];
//                 while(hts_max >= 0){
//                     if((abs(hts_max - hts[i-1]) == 1) || hts_max - hts[i-1] == 0) {
//                         if(res.count(i+2)){
//                             hts[i] = res[i+2]+1; break;
//                         }
//                         else{hts[i] = hts_max; break;}
//                     }
//                     hts_max--;
//                 }
//             }
//             else{
//                 hts[i] = hts[i-1] + 1;
//             }
//         }
//         for(int x: hts) cout<<x<<" ";
//         auto it = *max_element(hts.begin(), hts.end());
//         return it;

//     }
// };



class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        restrictions.push_back({1, 0});
        
        restrictions.push_back({n, n - 1});

        sort(restrictions.begin(), restrictions.end());

        int m = restrictions.size();

        for (int i = 1; i < m; i++) {
            int dist = restrictions[i][0] - restrictions[i - 1][0];

            restrictions[i][1] = min(
                restrictions[i][1],
                restrictions[i - 1][1] + dist
            );
        }

        for (int i = m - 2; i >= 0; i--) {
            int dist = restrictions[i + 1][0] - restrictions[i][0];

            restrictions[i][1] = min(
                restrictions[i][1],
                restrictions[i + 1][1] + dist
            );
        }

        long long ans = 0;

        for (int i = 1; i < m; i++) {
            long long x1 = restrictions[i - 1][0];
            long long h1 = restrictions[i - 1][1];

            long long x2 = restrictions[i][0];
            long long h2 = restrictions[i][1];

            long long dist = x2 - x1;

            long long peak =
                max(h1, h2) +
                (dist - llabs(h1 - h2)) / 2;

            ans = max(ans, peak);
        }

        return (int)ans;
    }
};