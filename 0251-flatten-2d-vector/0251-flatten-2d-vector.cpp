class Vector2D {
public:
    vector<int>arr;
    int i;
    Vector2D(vector<vector<int>>& vec) {
        for(auto v : vec){
            for(auto x : v) arr.push_back(x);
        }
        this->i = 0;
    }
    
    int next() {
        return arr[i++];
    }
    
    bool hasNext() {
        if(i<arr.size()) return true;
        return false;
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(vec);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */