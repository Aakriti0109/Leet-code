
class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        
        int minPrice = INT_MAX;
        vector<int> dp(budget + 1, 0);

        for (auto &item : items) {
            minPrice = min(minPrice, item[1]);
        }

        // Minimum-price item can fill the remaining budget
        for (int j = 0; j <= budget; j++) {
            dp[j] = j / minPrice;
        }

        // Process every item type
        for (int i = 0; i < n; i++) {
            int factor = items[i][0];
            int price = items[i][1];

            // Count free copies including the item itself
            int cnt = 0;

            for (int j = 0; j < n; j++) {
                if (items[j][0] % factor == 0) {
                    cnt++;
                }
            }

            // Buy this item at most once for its free-copy benefit
            for (int j = budget; j >= price; j--) {
                dp[j] = max(dp[j],
                            dp[j - price] + cnt);
            }
        }

        return dp[budget];
    }
};
