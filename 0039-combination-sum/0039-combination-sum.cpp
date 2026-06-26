class Solution {
public:

    void backtrack(vector<int>& cand, int strtIdx, vector<int>& currCombo, int remaining, vector<vector<int>>& res){
        if(remaining == 0) {
            res.push_back(currCombo); return;
        }
        for(int  i =strtIdx; i < cand.size(); i++){
            if(cand[i] > remaining) break;
            currCombo.push_back(cand[i]);
            backtrack(cand, i, currCombo, remaining - cand[i], res);
            currCombo.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int> currCombo;
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, 0, currCombo, target, ans);
        return ans;
    }
};