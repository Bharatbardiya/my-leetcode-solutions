class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int x1 = startPos[0], y1 = startPos[1];
        int x2 = homePos[0], y2 = homePos[1];

        int ans = 0;
        int dir_row = 1, dir_col = 1;
        if(x1>x2) dir_row = -1;
        if(y1>y2) dir_col = -1;

        for(int i = x1; i!=x2; i+=dir_row){
            ans+=rowCosts[i+dir_row];
        }
        for(int j = y1; j!=y2; j+=dir_col){
            ans+=colCosts[j+dir_col];
        }
        return ans;
    }
};