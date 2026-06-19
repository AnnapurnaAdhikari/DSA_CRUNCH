class Solution {
public:
    int answer = -1;
    void dfs(int node, vector<int> &edges, vector<bool>&visited, unordered_map<int, int>& dist){
        visited[node] = 1;
        int neigh = edges[node];
        if(neigh != -1 && !visited[neigh]){
            dist[neigh] = dist[node] + 1;
            dfs(neigh, edges, visited, dist);
        }
        else if(neigh != -1 && dist.count(neigh)){
            answer = max(answer, dist[node] - dist[neigh] + 1);
        }
    }


    int longestCycle(vector<int>& edges) {
    //approach 2 using DFS
    int n = edges.size();
    vector<bool> visited(n);
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            unordered_map<int, int> dist;
            dist[i] = 1;
            dfs(i, edges, visited, dist);
        }
        
    }
    return answer;

    //approach 1
    // int n = edges.size();
    // int ans = -1;
    // vector<int> visited(n, 0);

    // for (int i = 0; i < n; i++) {
    //     if (visited[i]) continue;

    //     unordered_map<int, int> path; // node -> step number
    //     int node = i;
    //     int step = 0;

    //     while (node != -1 && !visited[node]) {
    //         visited[node] = 1;
    //         path[node] = step++;

    //         node = edges[node];

    //         // Node repeats in the current traversal
    //         if (node != -1 && path.count(node)) {
    //             ans = max(ans, step - path[node]);
    //             break;
    //         }
    //     }
    // }

    // return ans;

}
};