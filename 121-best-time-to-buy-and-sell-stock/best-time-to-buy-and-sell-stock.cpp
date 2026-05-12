class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minP=prices[0];
        int maxP=0;
        int n=prices.size();
        for(int i=1;i<n;i++){
            maxP=max(maxP,prices[i]-minP);
            minP=min(minP,prices[i]);
        }
        return maxP;
    }
};