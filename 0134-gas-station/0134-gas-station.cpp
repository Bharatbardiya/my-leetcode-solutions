class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int station = -1, remgas = 0;
        for(int i = 0; i<n; i++){
            int dif = gas[i]-cost[i];
            if(station==-1 and dif>=0){
                station = i; remgas = dif;
            }
            else{
                remgas+=dif;
                if(remgas<0){
                    station = -1; remgas = 0;
                }
            }
        }
        if(station==-1) return -1;

        int i = 0;
        while(i!=station){
            remgas +=(gas[i]-cost[i]);
            if(remgas<0) return -1;
            i++;
        }
        return station;
    }
};