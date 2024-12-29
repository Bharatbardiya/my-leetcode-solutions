class Cmp{
    public:
    bool operator()(vector<int> &a, vector<int> &b){
        int val1 = a[0]*a[0]+a[1]*a[1], val2 = b[0]*b[0]+b[1]*b[1];
        if(val1>val2) return true;
        return false;
    }
};
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>, vector<vector<int>>, Cmp>pq;

        for(auto v : points){
            pq.push({v[0], v[1]});
        }
        vector<vector<int>>ans;
        while(pq.size()>0){
            vector<int>v = pq.top(); pq.pop();
            ans.push_back(v);
            if(ans.size()==k) break;
        }
        return ans;
    }
};