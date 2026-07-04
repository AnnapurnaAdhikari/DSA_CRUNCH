class Solution {
public:

    void backtrack(int n, int r, vector<vector<char>>&b, vector<bool>&c, vector<bool>&d1, vector<bool>&d2, vector<vector<string>>&res){
        //base case
        if(r == n){
            vector<string>posSol;
            for(int i = 0; i < n; i++){
                string row ="";
                for(int j = 0; j  < n; j++){
                    row+=b[i][j];
                }
                posSol.push_back(row);
            }
            res.push_back(posSol);
            // posSol.clear(); local variable
            return;
        }

        //recursive case
        //constraint check
        for(int i = 0; i < n; i++){
            if(!c[i] && !(d1[i+r]) && !d2[r-i + n - 1]){ //valid
                b[r][i]='Q';
                c[i] = true; d1[r+i] = true; d2[r-i + n - 1] = true;
                // break;
                //recurse
                backtrack(n, r+1, b , c, d1, d2, res);
                //undo
                b[r][i] = '.';
                c[i] = false; d1[r+i] = false; d2[r-i + n -1] = false;

            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> sols;
        vector<bool>cols(n, false);
        vector<bool>posDiag(2*n - 1, false);
        vector<bool>negDiag(2*n - 1, false);
        vector<vector<char>>board(n, vector<char>(n));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++) board[i][j] = '.';
        }
        backtrack(n, 0, board, cols, posDiag, negDiag, sols);

        return sols;    
        
    }
};