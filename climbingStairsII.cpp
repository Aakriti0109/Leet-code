
class Solution {
public:
    long long minCost(int n, vector<int>& costs) {

        vector<long long> dp(n + 1, LLONG_MAX);

        dp[0] = 0;

        for (int i = 1; i <= n; i++) {

            for (int j = 1; j <= 3; j++) {

                if (i - j >= 0 && dp[i - j] != LLONG_MAX) {

                    long long total = dp[i - j] + costs[i - 1] + 1LL * j * j;

                    dp[i] = min(dp[i], total);
                }
            }
        }

        return dp[n];
    }
};
