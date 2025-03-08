class Solution {
    public int minimumRecolors(String blocks, int k) {
        int x = Integer.MAX_VALUE, n = blocks.length();
        
        int curr = 0;
        if(blocks.charAt(0)=='W') curr++;
        int i = 0, j = 0;
        while(j<n-1){
            if(j-i+1 == k){
                x = Math.min(x,curr);
                j++;
                if(blocks.charAt(j)=='W') curr++;
                if(blocks.charAt(i)=='W') curr--;
                i++;
            }
            else{
                j++;
                if(blocks.charAt(j)=='W') curr++;
            }
        }
        x = Math.min(x,curr);
        return x;
    }
}