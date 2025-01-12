class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int count = 0;
        while(target>1 and maxDoubles>0){
            if(target%2==0 and maxDoubles>0){
                target/=2;
                maxDoubles--;
            }
            else target--;
            count++;
        }
        return count+target-1;
        // 19 -> 10011
    }
};