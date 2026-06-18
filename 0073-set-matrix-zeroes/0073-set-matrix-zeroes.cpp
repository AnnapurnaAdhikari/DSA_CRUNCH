class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        //tc: O(k(mxn))
        // vector<pair<int, int>> zeroIdx;
        // for(int  i = 0; i < matrix.size(); i++){
        //     for(int j = 0; j < matrix[0].size(); j++){
        //         if(matrix[i][j] == 0){
        //             zeroIdx.push_back({i, j});
        //         }

        //     }
        // }
        // for(auto pair: zeroIdx){
        //     int i = pair.first;
        //     int j = pair.second;
        //     for(int x = 0; x < matrix[0].size(); x++) matrix[i][x] = 0;
        //     for(int y = 0; y < matrix.size(); y++) matrix[y][j] = 0;
        // }

        //tc(m+n)
        int const n = matrix.size();
        int const m  = matrix[0].size();
        vector<int> r(n, 0);
        vector<int> c(m, 0);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == 0){
                    r[i] = 1;
                    c[j] = 1;
                }
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(r[i] || c[j]) matrix[i][j] = 0;
            }
        }
    
    }
};