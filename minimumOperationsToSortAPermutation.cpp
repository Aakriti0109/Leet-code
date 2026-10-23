class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size(), ans = INT_MAX;

        for (int r = 0; r < 2; r++) {
            vector<int> a = nums;
            if (r) reverse(a.begin(), a.end());

            int k = find(a.begin(), a.end(), 0) - a.begin();
            bool ok = true;

            for (int i = 0; i < n; i++) {
                if (a[(k + i) % n] != i) {
                    ok = false;
                    break;
                }
            }

            if (ok) {
                int cost = r ? 1 + min(k, n - k)
                             : min(k, n - k + 2);
                ans = min(ans, cost);
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
