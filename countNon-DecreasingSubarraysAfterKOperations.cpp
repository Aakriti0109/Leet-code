class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int LOG = 1;

        while ((1 << LOG) <= n) LOG++;

        vector<int> nge(n, n);
        stack<int> st;

        // Step 1: Find Next Greater Element
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] <= nums[i]) {
                st.pop();
            }

            if (!st.empty()) {
                nge[i] = st.top();
            }

            st.push(i);
        }

        // Prefix sum
        vector<long long> pref(n + 1, 0);

        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + nums[i];
        }

        // Step 2: Binary lifting tables
        vector<vector<int>> jump(LOG, vector<int>(n + 1, n));
        vector<vector<long long>> cost(LOG, vector<long long>(n + 1, 0));

        for (int i = 0; i < n; i++) {
            jump[0][i] = nge[i];

            int end = nge[i] - 1;

            cost[0][i] =
                1LL * nums[i] * (end - i + 1)
                - (pref[end + 1] - pref[i]);
        }

        for (int j = 1; j < LOG; j++) {
            for (int i = 0; i < n; i++) {
                int mid = jump[j - 1][i];

                jump[j][i] = jump[j - 1][mid];

                cost[j][i] =
                    cost[j - 1][i] + cost[j - 1][mid];
            }
        }

        // Step 3: Calculate cost of subarray [l, r]
        auto getCost = [&](int l, int r) -> long long {
            long long ans = 0;
            int p = l;

            for (int j = LOG - 1; j >= 0; j--) {
                if (p <= r && jump[j][p] <= r + 1) {
                    ans += cost[j][p];
                    p = jump[j][p];
                }
            }

            if (p <= r) {
                ans += 1LL * nums[p] * (r - p + 1)
                     - (pref[r + 1] - pref[p]);
            }

            return ans;
        };

        // Step 4: Sliding Window
        long long ans = 0;
        int l = 0;

        for (int r = 0; r < n; r++) {
            while (l <= r && getCost(l, r) > k) {
                l++;
            }

            ans += r - l + 1;
        }

        return ans;
    }
};
