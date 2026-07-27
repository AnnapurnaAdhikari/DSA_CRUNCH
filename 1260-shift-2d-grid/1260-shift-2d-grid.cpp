class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        //approach 1: brute force approach
        // int m = grid.size();
        // int n = grid[0].size(), temp;
        // if(n==1 && m == 1) return grid;
        // for(int i = 0; i < k; i++){
        //     for(int r = m-1; r >= 0; r--){
        //         for(int c = n-1; c >= 0; c--){
        //             if(c==n-1 && r == m-1) {
        //                 temp = grid[0][0];
        //                 grid[0][0] = grid[r][c];
        //                 }
        //             else if(c == n-1 && r < m - 1) grid[r+1][0] = grid[r][c];
        //             else grid[r][c+1] = grid[r][c];
        //         }
        //     }
        //     if(n>1)grid[0][1] = temp;
        //     else grid[1][0] = temp;
        // }

        // return grid;


        //approach2

        //  int m = grid.size();
        // int n = grid[0].size();

        // k %= (m * n);

        // while (k--) {

        //     int temp = grid[m - 1][n - 1];

        //     for (int r = m - 1; r >= 0; r--) {

        //         for (int c = n - 1; c >= 0; c--) {

        //             if (c == 0) {
        //                 if (r > 0)
        //                     grid[r][0] = grid[r - 1][n - 1];
        //             }
        //             else {
        //                 grid[r][c] = grid[r][c - 1];
        //             }
        //         }
        //     }

        //     grid[0][0] = temp;
        // }

        // return grid;

        //Approach3
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> ans(m, vector<int>(n));

        int total = m * n;
        k %= total;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                int idx = i * n + j;
                int newIdx = (idx + k) % total;

                ans[newIdx / n][newIdx % n] = grid[i][j];
            }
        }

        return ans;
    }
};