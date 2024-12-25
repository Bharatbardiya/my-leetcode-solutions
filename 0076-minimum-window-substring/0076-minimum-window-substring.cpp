class Solution {
public:
    bool isvalid(vector<int>&fq1, vector<int>&fq2){
        for(int i=0; i<100; i++){
            if(fq1[i]>fq2[i]) return false;
        }
        return true;
    }

    string minWindow(string s, string t) {
        vector<int>fq1(100), fq2(100);
        int n = s.length();
        int i = 0, j = 0;
        
        for(auto c : t) fq1[c-'A']++;
        int size = 100001, ind = -1;

        while(j<n){
            if(isvalid(fq1,fq2)){
                if(j-i<size){
                    size = j-i;
                    ind = i;
                }
                fq2[s[i]-'A']--;
                i++;
            }
            else{
                fq2[s[j]-'A']++;
                j++;
            }
        }
        while(isvalid(fq1,fq2)){
            if(j-i<size){
                size=j-i;
                ind = i;
            }
            fq2[s[i]-'A']--; i++;
        }
        if(ind==-1) return "";
        return s.substr(ind, size);
    }
};