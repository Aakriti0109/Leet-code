class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) {
            return nums[0] == 1 ? 1 : 0;
        }

        int ans = 2;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {

                bool valid = true;

                for (int k = i; k < j; k++) {
                    if (gcd(nums[k], nums[j]) != 1) {
                        valid = false;
                        break;
                    }
                }

                if (!valid) {
                    break;
                }

                ans = max(ans, j - i + 1);
            }
        }

        return ans;
    }
};
