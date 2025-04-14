class MinStack {
public:
    stack<int>st;
    stack<int>monost;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if(monost.size()==0 or monost.top()>=val) monost.push(val);
    }
    
    void pop() {
        int val = st.top(); st.pop();
        if(monost.top()==val) monost.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return monost.top();
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