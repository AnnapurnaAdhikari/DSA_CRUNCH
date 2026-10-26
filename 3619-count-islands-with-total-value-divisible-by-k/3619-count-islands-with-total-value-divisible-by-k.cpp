class Solution {
public:
    long long dfs(int i, int j, vector<vector<int>>& grid, int m, int n){
        long long sum = grid[i][j];
        grid[i][j] = 0;
        vector<vector<int>> dirs = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
        for(vector<int> dir: dirs){
            int i_ = i  + dir[0];
            int j_ = j + dir[1];
            if(i_ >= 0 && i_ < m && j_ >= 0 && j_ < n && grid[i_][j_] > 0)sum += dfs(i_, j_, grid, m, n);
        }
        return sum;
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        for(int i = 0; i < m; i++){
            for(int j  = 0; j  < n; j++){
                if(grid[i][j] > 0) {long long sum = dfs(i, j, grid, m , n);
                if(sum % k == 0) count++;}
            }
        }
        return count;
    }
};