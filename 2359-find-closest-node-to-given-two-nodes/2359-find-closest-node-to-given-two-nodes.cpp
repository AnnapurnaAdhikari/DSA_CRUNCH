class Solution {
public:

    void dfs(int node, int d, vector<int>& edges, vector<int>& dist){
       if(node == -1 || dist[node] != -1) return;
       dist[node] = d;
       dfs(edges[node], d+1, edges, dist);
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int dist = 0;
        int n = edges.size();
        // vector<bool> isVisited(n);
        vector<int> dist1(n,-1);
        vector<int> dist2(n,-1);
        dfs(node1, 0 , edges, dist1);
        dfs(node2, 0, edges, dist2);
        int ans =-1;
        int best = INT_MAX;
        for(int i = 0; i < n; i++){
            if(dist1[i] == -1 || dist2[i] == -1) continue;
            int mx = max(dist1[i], dist2[i]);
            if(mx < best){
                best=mx;
                ans=i;
            }
        }
        return ans;
        

    }
};