class Solution {
public:
    int minimizeXor(int num1, int num2) {
        vector<int>arr;
        int count = 0;
        while(num1>0){
            if((num1&1)==1) arr.push_back(1);
            else arr.push_back(0);
            num1 = num1>>1;
        }
        while(arr.size()<32) arr.push_back(0);

        while(num2>0){
            if((num2&1)==1) count++;
            num2 = num2>>1;
        }

        for(int i = 31; i>=0; i--){
            if(arr[i]==1 and count>0){
                count--; arr[i]=-1;
            }
        }
        for(int i = 0; i<32; i++){
            if(arr[i]==0 and count>0){
                arr[i] = -1; count--;
            }
        }
        // for(auto x : arr) cout<<x<<" ";
        int ans = 0;
        for(int i = 0; i<32; i++){
            if(arr[i]==-1){
                ans = (ans | (1<<i));
            }
        }
        // cout<<endl;
        return ans;
    }
};