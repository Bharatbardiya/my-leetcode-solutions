class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int count = 0, n = A.size();
        vector<int>hash(n+1);
        vector<int>arr(n);
        for(int i = 0; i<n; i++){
            if(A[i]==B[i]){
                count++; hash[A[i]]+=2;
            }
            else{
                hash[A[i]]++; hash[B[i]]++;
                if(hash[A[i]]==2) count++;
                if(hash[B[i]]==2) count++;
            }
            arr[i] = count;
        }
        return arr;
    }
};