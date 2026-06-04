class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l=0;
        int r= 1;
        int max = 0;
        while (r < prices.size()) {
            int diff = prices[r] - prices[l];
            if (diff > max)
                max = diff;
            if (diff < 0) {
                l = r;
            }
            r++;
        }

        return max;
        
    }
};
