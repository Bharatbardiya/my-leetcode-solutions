class Solution {
public:
    bool isvalid(vector<int>&fq1, vector<int>&fq2){
        for(int i=0; i<100; i++){
            if(fq1[i]>fq2[i]) return false;
        }
        return true;
    }

    string minWindow(string s, string t) {
        unordered_map<char, int>feqt, window;

        int n = s.length();
        int i = 0, j = 0;
        
        for(auto c : t) feqt[c]++;
        int size = 100001, ind = -1;
        int need = feqt.size(), have = 0;

        while(j<n){
            window[s[j]]++;
            if(feqt.count(s[j]) and feqt[s[j]]==window[s[j]]){
                have++;
            }
            while(need==have){
                if((j-i+1)<size){
                    // cout<<i<<","<<j<<endl;
                    size = j-i+1; ind = i;
                }
                window[s[i]]--;
                if(feqt.count(s[i]) and feqt[s[i]] > window[s[i]]){
                    have--;
                }
                i++;
            }
            j++;
        }
        if(ind==-1) return "";
        return s.substr(ind, size);
    }
};