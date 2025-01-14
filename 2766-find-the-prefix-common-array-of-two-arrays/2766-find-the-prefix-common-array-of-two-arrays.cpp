class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_set<int>st1,st2;
        int count = 0, n = A.size();
        vector<int>arr(n);
        for(int i = 0; i<n; i++){
            if(A[i]==B[i]) count++;
            else{
                if(st1.find(B[i])!=st1.end()) count++;
                if(st2.find(A[i])!=st2.end()) count++;
            }
            st1.insert(A[i]); st2.insert(B[i]);
            arr[i] = count;
        }
        return arr;
    }
};