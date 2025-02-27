class Cmp{
    public:
    bool operator()(pair<int,int>&pr1, pair<int,int>&pr2){
        if(pr1.first==pr2.first) return pr1.second<pr2.second;
        return pr1.first<pr2.first;
    }
};
bool cmp(pair<int,int>&pr1, pair<int,int>&pr2){
    if(pr1.first==pr2.first) return pr1.second>pr2.second;
    return pr1.first<pr2.first;
}

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>>vpr;
        int n = profits.size();
        for(int i = 0; i<n; i++){
            vpr.push_back({capital[i], profits[i]});
        }
        sort(vpr.begin(), vpr.end(), cmp);

        priority_queue<int>pq;
        
        int lastInd = 0, ans = 0, lastCapital = 0;
        while(lastInd<n and k>0){
            while(lastInd<n and vpr[lastInd].first<=w){
                pq.push(vpr[lastInd].second);
                lastInd++;
            }
            if(pq.size()==0) break;
            // cout<<pq.top().first<<","<<pq.top().second<<"),";
            // ans += (pq.top().first);
            w += (pq.top());
            // lastCapital = pq.top().second;
            pq.pop();
            k--;
        }
        while(k>0 and pq.size()>0){
            // cout<<pq.top().first<<","<<pq.top().second<<"),";
            // ans += (pq.top().first);
            w += (pq.top());
            // lastCapital = pq.top().second;
            pq.pop(); 
            k--;
        }
        return w;
    }
};