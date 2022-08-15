class MyStack {
public:
    queue<int> q;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        int n = q.size()-1;
        while(n--){
            int val = q.front();
            q.pop();
            q.push(val);
        }
        int ret = q.front();
        q.pop();
        return ret;
    }
    
    int top() {
        return q.back();
    }
    
    bool empty() {
        return q.size()==0;
    }
};
