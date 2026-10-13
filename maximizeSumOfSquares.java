public class maximizeSumOfSquares {
    
}

class Solution {
    public int maxSum(List<Integer> nums, int k) {
        int MOD = 1_000_000_007;
        int n = nums.size();
        long[] bits = new long[32];

        for (int num : nums) {
            for (int b = 0; b < 32; b++) {
                if ((num & (1 << b)) != 0) {
                    bits[b]++;
                }
            }
        }

        long ans = 0;

        for (int i = 0; i < k; i++) {
            long x = 0;

            for (int b = 0; b < 32; b++) {
                if (bits[b] > 0) {
                    x |= (1L << b);
                    bits[b]--;
                }
            }

            ans = (ans + x * x) % MOD;
        }

        return (int) ans;
    }
}