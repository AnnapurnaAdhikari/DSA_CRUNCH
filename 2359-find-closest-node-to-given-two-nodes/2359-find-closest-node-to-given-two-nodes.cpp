class Solution {
public:

//approach2
    vector<int> getDist(vector<int>& edges, int start)
    {
        int n = edges.size();

        vector<int> dist(n, -1);

        int curr = start;
        int d = 0;

        while (curr != -1 && dist[curr] == -1)
        {
            dist[curr] = d++;
            curr = edges[curr];
        }

        return dist;
    }

    int closestMeetingNode(vector<int>& edges,
                           int node1,
                           int node2)
    {
        vector<int> d1 = getDist(edges, node1);
        vector<int> d2 = getDist(edges, node2);

        int ans = -1;
        int best = INT_MAX;

        for (int i = 0; i < edges.size(); i++)
        {
            if (d1[i] == -1 || d2[i] == -1)
                continue;

            int mx = max(d1[i], d2[i]);

            if (mx < best)
            {
                best = mx;
                ans = i;
            }
        }

        return ans;
    }
    // approach 1
    // void dfs(int node, int d, vector<int>& edges, vector<int>& dist){
    //    if(node == -1 || dist[node] != -1) return;
    //    dist[node] = d;
    //    dfs(edges[node], d+1, edges, dist);
    // }
    // int closestMeetingNode(vector<int>& edges, int node1, int node2) {
    //     int dist = 0;
    //     int n = edges.size();
    //     // vector<bool> isVisited(n);
    //     vector<int> dist1(n,-1);
    //     vector<int> dist2(n,-1);
    //     dfs(node1, 0 , edges, dist1);
    //     dfs(node2, 0, edges, dist2);
    //     int ans =-1;
    //     int best = INT_MAX;
    //     for(int i = 0; i < n; i++){
    //         if(dist1[i] == -1 || dist2[i] == -1) continue;
    //         int mx = max(dist1[i], dist2[i]);
    //         if(mx < best){
    //             best=mx;
    //             ans=i;
    //         }
    //     }
    //     return ans;
        

    // }
};