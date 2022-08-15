class MyStack {
public:
    queue<int> q1,q2;
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        q2 = {};
        while(q1.size()!=1){
            q2.push(q1.front());
            q1.pop();
        }
        int ret = q1.front();
        q1 = q2;
        return ret;
    }
    
    int top() {
        return q1.back();
    }
    
    bool empty() {
        return q1.size()==0;
    }
};
