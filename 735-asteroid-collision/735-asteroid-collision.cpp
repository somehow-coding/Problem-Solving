class Solution {
public:
    // if(changes are dynamic){
    //     order matters: priority_queue, set or multiset;
    //     order doesnt matters: stack and queue;
    // }
    
    //here in this question dynamic changes are happening.
    //that is after collision vector is changing.....
    //changing how??
    //if 2 asteroids collide(they are offourse of opposite nature), 
    //the smaller one will explode.
    
    //questions to be asked??
    //is zero allowed very important to know this to write solution...
    
    bool opposite(int a, int b){
        return (a>0 and b<0);
    }
    
    int asteroidLeft(int a, int b){
        if(abs(a)==abs(b)){
            return 0;
        }
        if(abs(a)>abs(b)){
            return a;
        }
        return b;
    }
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(int asteroid: asteroids){
            bool flag = 0;
            while(st.size() and opposite(st.top(),asteroid)){
                int left = asteroidLeft(st.top(),asteroid);
                if(left==0){
                    st.pop();
                    flag = 1;
                    break;
                }
                else if(left==asteroid){
                    st.pop();
                }
                else{
                    flag = 1;
                    break;
                }
            }
            if(flag == 1){
                continue;
            } 
            st.push(asteroid);
        }
        vector<int> final_state(st.size());
        while(st.size()){
            final_state[st.size()-1] = st.top();
            st.pop();
        }
        return final_state;
    }
};