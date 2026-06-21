class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int money = 0;
        int max_ice = 0;
        for(int cost: costs){
            if(money < coins && cost <= coins-money ){
                money += cost;
                max_ice++;
            }
        }
        return max_ice;
        
    }
};