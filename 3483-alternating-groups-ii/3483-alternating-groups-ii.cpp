class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int ind = 0, n = colors.size(), curr = 1;
        for(int i = 0; i<n; i++){
            if(colors[i]==colors[(i+1)%n]) ind = (i+1)%n;
        }
        int i = ind, ans = 0;
        vector<int>arr;

        do{
            if(colors[i]!=colors[(i+1)%n]) curr++;
            else{
                arr.push_back(curr); curr = 1;
            }
            i = (i+1)%n;
        }while(i!=ind);
        if(curr>0) arr.push_back(curr);

        if(curr>=n and arr.size()==1){
            return n;
        }
        for(auto x : arr){
            if(x>=k) ans+=(x-k+1);
            // cout<<x<<",";
        }
        return ans;
    }
};