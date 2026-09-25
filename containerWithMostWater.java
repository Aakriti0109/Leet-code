class Solution {
    public int maxArea(int[] height) {
        int maxArea = 0;
        int lp = 0;
        int rp = height.length - 1;
        while(lp<rp){
        int w = rp - lp;
        int ht = Math.min(height[lp], height[rp]);
        int area = w*ht;
        maxArea = Math.max(maxArea, area);
        
        if(height[lp]<height[rp])
        {
                lp++;
        }
        else{
            rp--;
        }
        }
        
        return maxArea;
    }
  
}