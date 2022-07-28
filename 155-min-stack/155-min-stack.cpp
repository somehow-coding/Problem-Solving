class MinStack {
public:
    stack<pair<int,int>> st;
    
    MinStack() {
        //we have a stack...
    }
    
    void push(int val) {
        if(!st.size()){
            st.push({val,val});
        }
        else{
            int minv = st.top().second;
            st.push({val, min(minv,val)});
        }
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
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