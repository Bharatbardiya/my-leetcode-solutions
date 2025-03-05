class Solution {
public:
    long long coloredCells(int n) {
        long long ans = 1, diff = 0;
        for(int i = 1; i<n; i++){
            diff += 4;
            ans += diff;
        }
        return ans;
    }
};