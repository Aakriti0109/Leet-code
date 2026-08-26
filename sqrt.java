import java.util.Scanner;
class Solution {
    public int mysqrt(int x) {
        if (x == 0) {
            return 0;
        }
        int left = 1, right = x;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (mid > x / mid) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left - 1;
    }
}
public class sqrt {
    public static void main(String[] args) {
        Solution obj = new Solution();
        System.out.println("Enter the number: ");
        Scanner sc = new Scanner(System.in);
        int x = sc.nextInt();
        int answer = obj.mysqrt(x);
        System.out.println("Square root of " + x + " is: " + answer);
    }
}