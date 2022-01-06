/* You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k. Find the maximum profit you can achieve. You may complete 
at most k transactions. */


class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (k==0) return 0;
        vector<int> buy(k, INT_MAX), sell(k, 0);
        for (int cur:prices)
        {
            for (int i = 0; i < k; i++)
            {
                buy[i] = min(buy[i], cur - (i-1>=0 ? sell[i-1]:0));
                sell[i] = max(cur-buy[i], sell[i]);
            }
        }
        return sell[k-1];
    }
};
