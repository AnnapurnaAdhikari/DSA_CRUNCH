// 84. Largest Rectangle in Histogram

#include <bits/stdc++.h>
using namespace std;

//Brute Force Approach
int largestRectangleArea0(vector<int>& heights) {
    int n = heights.size();
    int maxAr = 0;
    for(int  i = 0; i < n; i++){
        int h = heights[i];
        int rMost = i + 1, lMost = i;
        while(rMost < n && heights[rMost] >= h) rMost++;
        while(lMost >= 0 && heights[lMost] >= h) lMost--;
        rMost--; lMost++;
        maxAr = max(maxAr, h*(rMost - lMost + 1));
    }
    return maxAr;
}