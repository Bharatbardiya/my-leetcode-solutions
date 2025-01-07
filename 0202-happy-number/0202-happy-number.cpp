class Solution {
public:
    int calculateValue(int x){
        int ans = 0;
        while(x>0){
            int rem = x%10;
            ans += (rem*rem);
            x = x/10;
        }
        return ans;
    }
    bool isHappy(int n) {
        //2, 4, 16, 37, 58, 25+64=98, 81+64=145, 1+16+25=42, 20, 4,
        int t1 = n, t2 = n;
        do{
            t1 = calculateValue(t1);
            t2 = calculateValue(calculateValue(t2));
            if(t1==1 or t2==1) break;
            else if(t1==t2) return false;
            
        }while(true);

        return true;
    }
};