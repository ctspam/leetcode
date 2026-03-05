class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minSoFar = prices[0];
        int result = 0;

        for(int i = 1; i < prices.size(); ++i){
            minSoFar = min(minSoFar, prices[i]);
            result = max(result, prices[i] - minSoFar);
        }
        return result;
    }
};