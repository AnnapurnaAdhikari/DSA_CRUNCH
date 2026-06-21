class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        // sort(costs.begin(), costs.end());
        // int money = 0;
        // int max_ice = 0;
        // for(int cost: costs){
        //     if(money < coins && cost <= coins-money){
        //         money += cost;
        //         max_ice++;
        //     }
        // }
        // return max_ice;

        //appproach2: counting array
        int maxCost = *max_element(costs.begin(), costs.end());

        vector<int> freq(maxCost + 1, 0);

        for (int cost : costs) {
            freq[cost]++;
        }

        int bars = 0;

        for (int cost = 1; cost <= maxCost; cost++) {
            if (freq[cost] == 0) continue;

            int canBuy = min(freq[cost], coins / cost);

            bars += canBuy;
            coins -= canBuy * cost;

            if (coins < cost) break;
        }

        return bars;
        
    }
};