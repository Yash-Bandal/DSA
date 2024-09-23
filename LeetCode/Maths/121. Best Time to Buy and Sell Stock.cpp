class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minI= prices[0];
        int cost=0;
        int profit = INT_MIN;  //- inf
        for(int i = 0 ; i < prices.size() ; i++){
            cost = prices[i] - minI;
            profit = max(cost,profit);
            minI=min(minI,prices[i]);
        }
        return profit;
        
    }
};
