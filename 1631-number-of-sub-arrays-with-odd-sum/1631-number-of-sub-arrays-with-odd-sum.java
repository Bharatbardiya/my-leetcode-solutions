class Solution {
    public int numOfSubarrays(int[] arr) {
        int odds = 0, evens = 1;
        int sum = 0, ans = 0, mod = (int)1e9+7;
        for(int val : arr){
            sum += val;
            if(sum%2==0){
                ans += odds;
                ans %= mod;
                evens++;
            }
            else{
                ans += evens;
                ans %= mod;
                odds++;
            }
        }
        return ans;
    }
}