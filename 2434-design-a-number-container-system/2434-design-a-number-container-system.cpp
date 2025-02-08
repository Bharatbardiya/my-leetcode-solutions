class NumberContainers {
public:
    map<int, set<int>>mp1;
    map<int,int>mp2;

    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if(mp2.find(index)==mp2.end()){
            mp2[index] = number;
            mp1[number].insert(index);
        }
        else{
            int prev = mp2[index];
            mp1[prev].erase(index);
            mp2[index] = number;
            mp1[number].insert(index);
        }
    }
    
    int find(int number) {
        if(mp1.find(number)!=mp1.end()){
            if(mp1[number].size()>0) return *mp1[number].begin();
            else return -1;
        }
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */