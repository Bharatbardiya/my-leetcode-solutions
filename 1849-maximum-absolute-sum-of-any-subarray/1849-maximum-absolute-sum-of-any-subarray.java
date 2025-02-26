class Solution {
    public int maxAbsoluteSum(int[] nums) {
        int curr1 = 0, curr2 = 0, maxi = 0;
        for(int x : nums){
            curr1 += x;
            curr2 += x;
            if(curr1<0) curr1 = 0;
            else maxi = Math.max(curr1, maxi);

            if(curr2>0) curr2 = 0;
            else maxi = Math.max(-1*curr2, maxi);
        }
        return maxi;
    }
}