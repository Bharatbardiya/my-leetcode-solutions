class Solution {
public:
    bool divideArray(vector<int>& nums) {
        set<int>st;
        for(auto x : nums){
            if(st.find(x)!=st.end()) st.erase(x);
            else st.insert(x);
        }
        return st.size()==0;
    }
};