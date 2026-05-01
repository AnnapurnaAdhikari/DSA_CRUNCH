// 84. Largest Rectangle in Histogram (HARD)

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

// Optimal Approach using STACK(MONOTONIC)
int largestRectangleArea1(vector<int>& heights){
    int n = heights.size();
    stack<pair<int, int>> stk; //{idx, ht}
    int maxAr = 0;

    for(int i = 0; i < n; i++){
        int start = i;
        while(!stk.empty() && stk.top().second > heights[i]){
            auto [idx, ht] = stk.top();
            stk.pop();
            maxAr = max(maxAr, ht*(i-idx));
            start = idx;
        }
        stk.push({start, heights[i]});
    }
    while(!stk.empty()){
        auto [idx, ht] = stk.top();
        stk.pop();
        maxAr = max(maxAr, ht*(n-idx));
    }
    return maxAr;
}