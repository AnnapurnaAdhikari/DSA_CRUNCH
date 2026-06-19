class Solution {
public:

    int longestCycle(vector<int>& edges) {
    int n = edges.size();
    int ans = -1;

    vector<int> visited(n, 0);

    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;

        unordered_map<int, int> path; // node -> step number
        int node = i;
        int step = 0;

        while (node != -1 && !visited[node]) {
            visited[node] = 1;
            path[node] = step++;

            node = edges[node];

            // Node repeats in the current traversal
            if (node != -1 && path.count(node)) {
                ans = max(ans, step - path[node]);
                break;
            }
        }
    }

    return ans;
}
};