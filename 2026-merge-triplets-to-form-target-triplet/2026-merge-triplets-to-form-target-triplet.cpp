class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int x1 = 0, x2 = 0, x3 = 0;
        for(auto v : triplets){
            if(v[0]<=target[0] and v[1]<=target[1] and v[2]<=target[2]){
                x1 = max(x1, v[0]); x2 = max(x2, v[1]);
                x3 = max(x3, v[2]);
            }
        }
        return (x1==target[0] and x2==target[1] and x3==target[2]);
    }
};