class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {

        multiset<int>st;
        int i = 0, j = 0, n = nums.size();
        long long ans = 0;

        while(j<n){
            if(st.size()>0){
                auto it0 = st.begin(), it1 = --st.end();
                if(*it1-*it0 > 2){
                    st.erase(st.find(nums[i]));
                    i++;
                }
                else{
                    ans+=st.size();
                    st.insert(nums[j]);
                    j++;
                }
            }
            else{
                st.insert(nums[j]);
                j++;
            }
        }

        while(i<n){
            auto it0 = st.begin(), it1 = --st.end();
            if(*it1-*it0 <= 2){
                ans+=st.size();
                break;
            }
            else{
                st.erase(st.find(nums[i]));
                i++;
            }
        }
        return ans;
    }
};