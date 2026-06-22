class Solution {
public:

    void dfs(int node, vector<vector<int>>& isConnected, vector<bool>& isVisited){
        isVisited[node] = true;
        for(int j = 0; j < isConnected.size(); j++){
            if(isConnected[node][j] == 1 && !isVisited[j]){
                dfs(j, isConnected, isVisited);
            }
        }

    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int nConnectedComps = 0;
        vector<bool> isVisited(n);

        for(int  i = 0; i  < n; i++){
            if(!isVisited[i]){
                nConnectedComps++;
                dfs(i, isConnected, isVisited);
            }
        }
        return nConnectedComps;
    }
    //brute force, 92/114 test cases passed
    // int findCircleNum(vector<vector<int>>& isConnected) {
    //     set<int> connectedNodes;
    //     int n = isConnected.size();
    //     for(int  i = 0; i < n; i++){
    //         for(int j = 0; j < isConnected[0].size(); j++){
    //             if(isConnected[i][j] == 1 && i != j && i < j) {connectedNodes.insert(i);
    //             connectedNodes.insert(j); }
    //         }
    //     } 
    //     if(connectedNodes.empty()) return n;
    //     int notConnected = n - connectedNodes.size();
    //     return 1 + notConnected;
    // }
};