import java.util.Scanner;

class Solution{
    public boolean checkDivisibility(int n){
        int original=n, sum=0, prod=1;
        while(n>0){
            int digit=n%10;
            sum = sum+digit;
            prod = prod*digit;
            n=n/10;
        }
        int value = sum+prod;
        if(original%value==0){
            return true;
        }
        else{
            return false;
    }
    }
}
public class checkDivisibility {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number: ");
        int n = sc.nextInt();
        Solution obj = new Solution(); // Create an instance of the Solution class
        boolean result = obj.checkDivisibility(n); // Call the checkDivisibility method using the instance
        System.out.println("The number is divisible by the sum of sum and product of its digits: " + result);
    }
}
