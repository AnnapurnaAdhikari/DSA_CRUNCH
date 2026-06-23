class Solution {
public:
    void dfs(int source, vector<vector<int>>& adj, vector<bool>& isVisited, bool &foundValidPath, int destination){
        isVisited[source] = true;
        if (source == destination) {
            foundValidPath = true;
                return;
        }
        for(int neigh: adj[source]){
            if(!isVisited[neigh]){
                if(neigh == destination) {foundValidPath = true; return;}
                dfs(neigh, adj, isVisited, foundValidPath, destination);
            }
        }
    } 
    vector<vector<int>> buildAdjList(int n, vector<vector<int>>& edges){
        vector<vector<int>> adj(n);
        for(auto& edge: edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return adj;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<bool> isVisited(n, false);
        bool foundValidPath = false;
        vector<vector<int>> adj(n);
        adj = buildAdjList(n, edges);
        
            if(!isVisited[source]){
                dfs(source, adj, isVisited, foundValidPath, destination);
            }
        if(foundValidPath) return true;
        return false;
    }
};