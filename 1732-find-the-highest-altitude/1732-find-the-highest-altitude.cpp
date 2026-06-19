class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        vector<int> alt(n+1, 0);
        int maxi = 0;

        for(int i = 0; i < n; i++){
            alt[i+1] = alt[i] + gain[i];
            cout<<alt[i+1]<<" ";
            maxi = max(maxi, alt[i+1]);
        }
        // auto maxAlt = max_element(alt.begin(), alt.end());
        // return *maxAlt;
        return maxi;
    }
};