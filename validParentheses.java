import java.util.Scanner;

class solution {
    
    public static boolean validParentheses(String s){

        while(true){
            if(s.contains("()")){
                s=s.replace("()", "");
            }
            else if(s.contains("[]")){
                s=s.replace("[]", "");     
            } 
              else{
                return s.isEmpty();
              }
            
        }
    }
}
public class validParentheses {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the parentheses string: ");
        String s = sc.nextLine();
        boolean result = solution.validParentheses(s);
        System.out.println("this parentheses is " + result);
    }
}


