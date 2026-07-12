class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        queue<pair<int,int>> q;

        int fresh = 0;

        int rows = grid.size();
        int cols = grid[0].size();

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){

                if(grid[i][j]==2)
                    q.push({i,j});

                else if(grid[i][j]==1)
                    fresh++;
            }
        }

        if(fresh==0)
            return 0;

        int minutes=0;

        int dr[4]={-1,1,0,0};
        int dc[4]={0,0,-1,1};

        while(!q.empty() && fresh){

            int size=q.size();

            while(size--){

                auto cell=q.front();
                q.pop();

                int r=cell.first;
                int c=cell.second;

                for(int k=0;k<4;k++){

                    int nr=r+dr[k];
                    int nc=c+dc[k];

                    if(nr>=0 && nr<rows &&
                       nc>=0 && nc<cols &&
                       grid[nr][nc]==1){

                        grid[nr][nc]=2;

                        fresh--;

                        q.push({nr,nc});
                    }
                }
            }

            minutes++;
        }

        return fresh==0 ? minutes : -1;
    }
};