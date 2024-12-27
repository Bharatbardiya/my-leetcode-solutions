class MinStack {
public:
    stack<int>st1,st2;
    int mini = INT_MAX;
    MinStack() {
        
    }
    
    void push(int val) {
        st1.push(val);
        mini = min(mini, val);
        if(st2.size()==0 or st2.top()>=val) st2.push(val);
    }
    
    void pop() {
        int t = st1.top();
        st1.pop();
        if(st2.top()==t){
            st2.pop();
            if(st2.size()==0) mini = INT_MAX;
            else mini = st2.top();
        }
    }
    
    int top() {
        return st1.top();
    }
    
    int getMin() {
        return st2.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */