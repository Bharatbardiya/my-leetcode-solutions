class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        set<int, greater<int>>st;
        int ans = 0;
        for(int i = 0; i<arr.size(); i++){
            st.insert(arr[i]);
            if(*st.begin()<=i){
                ans++;
                st.clear();
            }
        }
        return ans;
    }
};