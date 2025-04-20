class Solution {
public:
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
        vector<int>ans;
        for(auto q : queries){
            vector<int>p1, p2;
            int ai = q[0], bi = q[1];
            while(ai>=1){
                p1.push_back(ai); ai/=2;
            }
            while(bi>=1){
                p2.push_back(bi); bi/=2;
            }
            // for(auto x : p1) cout<<x<<",";
            // cout<<endl;
            // for(auto x : p2) cout<<x<<",";
            int ind1 = 0, ind2 = 0;
            int n1 = p1.size(), n2 = p2.size();
            while(ind1<n1 and ind2<n2){
                if(p1[ind1]==p2[ind2]) break;
                if(p1[ind1]>p2[ind2]) ind1++;
                else ind2++;
            }
            // cout<<"ind1 = "<<ind1<<", ind2 = "<<ind2<<endl;
            ans.push_back(ind1+ind2+1);
        }
        return ans;
    }
};