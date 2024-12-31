class Solution {
public:
    string answerString(string word, int numFriends) {
        int n = word.size();
        if(numFriends==1) return word;
        string ans = "";
        int remlen = numFriends-1;
        int maxlen = n-remlen;

        string curr = "";
        for(int i = 0; i<n; i++){
            int len = min(n,i+maxlen);
            for(int j = i; j<len; j++){
                curr+=(word[j]);
            }
            if(ans<curr) ans = curr;
            curr = "";
        }
        
        return ans;
    }
};