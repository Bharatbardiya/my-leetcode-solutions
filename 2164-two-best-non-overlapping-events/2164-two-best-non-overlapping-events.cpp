class Solution {
public:
    void printMatrix(vector<vector<int>>&arr){
        cout<<"[";
        for(auto v : arr){
            cout<<"[";
            for(auto x : v) cout<<x<<",";
            cout<<"],";
        }
        cout<<"]\n";
    }
    int BinaryS(vector<vector<int>>&arr, int val){
        int ans = 0;
        int i = 0, j = arr.size()-1;
        while(i<=j){
            int mid = (i+j)/2;
            if(arr[mid][0]>val){
                ans = arr[mid][3];
                j = mid-1;
            }
            else{
                i = mid+1;
            }
        }
        return ans;
    }
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        int n = events.size();
        int cur = 0;
        for(int i = n-1; i>=0; i--){
            cur = max(events[i][2], cur);
            events[i].push_back(cur);
        }
        int ans = 0;
        for(auto v : events){
            int val = v[2];
            int end = v[1];
            val+=BinaryS(events, end);
            ans = max(ans, val);
        }
        return ans;
    }
};