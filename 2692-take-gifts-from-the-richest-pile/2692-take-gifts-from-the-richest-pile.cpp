class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int>pq;

        for(auto x : gifts) pq.push(x);
        
        for(int i = 0; i<k and pq.size()>0; i++){
            int x = pq.top();
            pq.pop();
            if(x>0) pq.push(sqrt(x));
        }
        long long ans = 0;
        while(pq.size()>0){
            ans += pq.top();
            pq.pop();
        }
        return ans;
    }
};