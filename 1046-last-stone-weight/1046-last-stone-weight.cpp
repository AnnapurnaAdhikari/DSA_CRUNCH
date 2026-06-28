class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        //O(n log n)
        // priority_queue<int> pq;

        // for(int s: stones) pq.push(s);

        // while(pq.size() > 1){
        //     int y = pq.top();
        //     pq.pop();
        //     int x = pq.top();
        //     pq.pop();

        //     if(y != x) pq.push(y-x);
        // }
        // return pq.empty()? 0: pq.top();

        // O(n² log n)
        while (stones.size() > 1) {
            sort(stones.begin(), stones.end());

            int y = stones.back(); stones.pop_back();
            int x = stones.back(); stones.pop_back();

            if (y != x)
                stones.push_back(y - x);
        }
        return stones.empty() ? 0 : stones[0];
    }
};