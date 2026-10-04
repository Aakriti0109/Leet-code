class Solution {
    public int smallestNumber(int n, int t) {
        
    while (true) {
        int no = n;
        int prod =1;
        while (no>0){
            int digit = no%10;
            prod*=digit;
            no/=10;
        }
        if(prod%t==0) return n;
        n++;
    }
    }
}
