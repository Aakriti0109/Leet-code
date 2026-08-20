import java.util.HashSet;
import java.util.Set;
import java.util.Scanner;
public class happynumber {
public static void main(String[] args) {
    Solution obj = new Solution();
    System.out.println("Enter the number: ");
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    boolean answer = obj.isHappy(n);
    if(answer){
        System.out.println(n + " is a happy number.");
    }else{
        System.out.println(n + " is not a happy number.");
    }
}
}
class Solution{
       public boolean isHappy(int n){

        Set<Integer> usedIntegers  = new HashSet<>();
         
        while(true){
            //find the sum of squares
            int sum =0;
            while(n>0){
                int digit= n%10;
                sum+=Math.pow(digit,2);
                n/=10;
            }
            if(sum==1){
                return true;
            }
            if(usedIntegers.contains(sum)){
                return false;
            }
            usedIntegers.add(sum);
            n=sum;
        }
    }
}