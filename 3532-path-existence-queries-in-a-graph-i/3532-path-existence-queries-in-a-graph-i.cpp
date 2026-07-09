class Solution {
public:

    // bool bfs(int src, int dest, int n, vector<vector<int>>& adj){
    //     vector<bool>isVisited(n, false);
    //     queue<int> q;
    //     q.push(src);
    //     isVisited[src] = true;
    //     while(!q.empty()){
    //         int p = q.front();
    //         q.pop();
    //         if(p == dest) return true;
    //         for(int child: adj[p]){
    //             if(!isVisited[child]) {
    //                 isVisited[child] = true;
    //                 q.push(child);}
    //         }
    //     }
    //     return false;
    // }

    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        //approach1: create graph
        // vector<bool> canReach;
        // vector<vector<int>>adj(n);
        // for(int i = 0; i < n; i++){
        //     for(int j = i + 1; j < n; j++){
        //         if(abs(nums[i] - nums[j]) <= maxDiff){
        //             adj[i].push_back(j);
        //             adj[j].push_back(i);
        //         }
        //     }
        // }
        // for(vector<int> q: queries){
        //      canReach.push_back(bfs(q[0], q[1], n, adj));
        // }
        // return canReach;
        //approach 2x
         vector<int> comp(n, 0);
        int id = 0;

        for (int i = 1; i < n; i++) {
            if (nums[i] - nums[i - 1] > maxDiff)
                id++;
            comp[i] = id;
        }

        vector<bool> ans;

        for (auto &q : queries) {
            ans.push_back(comp[q[0]] == comp[q[1]]);
        }

        return ans;
        
        
    }
};