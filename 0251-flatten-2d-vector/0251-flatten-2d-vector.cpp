class Vector2D {
public:
    vector<vector<int>>vec;
    int x,y;
    Vector2D(vector<vector<int>>& vec) {
        this->vec = vec;
        x = 0, y = 0;
        while(x<vec.size() and vec[x].size()==0) x++;
    }
    
    int next() {
        int val = vec[x][y];
        if(y==vec[x].size()-1){
            x++; y=0;
            while(x<vec.size() and vec[x].size()==0) x++;
        } else y++;
        return val;
    }
    
    bool hasNext() {
        return x<vec.size();
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(vec);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */