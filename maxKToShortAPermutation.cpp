class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();
        int ans = (1 << 30) - 1;
        bool sorted = true;

        for (int i = 0; i < n; i++) {
            if (nums[i] != i) {
                ans &= nums[i];
                sorted = false;
            }
        }

        return sorted ? 0 : ans;
    }
};