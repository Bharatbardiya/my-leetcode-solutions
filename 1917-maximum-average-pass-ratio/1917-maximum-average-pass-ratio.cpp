#define prdi pair<double,pair<int,int>>
class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int es) {
        priority_queue<prdi>pq;

        for(auto v : classes){
            double pass = v[0], total = v[1];
            double ratio = (pass+1)/(total+1) - pass/total;
            
            pq.push({ratio, {pass, total}});
        }
        while(es>0){
            auto pr = pq.top();
            pq.pop();
            double ratio = pr.first;
            double pass = pr.second.first, total = pr.second.second;
            //cout<<ratio<<","<<pass<<","<<total<<endl;
            pass++;
            total++;
            ratio = (pass+1)/(total+1) - pass/total;
            pq.push({ratio, {pass, total}});
            es--;
        }
        double ans = 0;
        int div = classes.size();
        while(pq.size()>0){
            auto pr = pq.top();
            pq.pop();
            int pass = pr.second.first, total = pr.second.second;
            double ratio = (pass*1.0)/total;
            //cout<<"pass = "<<pass<<", total = "<<total<<"),";
            ans+=ratio;
        }
        return ans/div;
    }
};