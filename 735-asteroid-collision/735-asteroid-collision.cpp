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
    
    //to be observed(sense..)->they will colide if only if + -> and - <-
    //that means positive on left and negative on right then only than they will collide.
    
    // returns if two asteroids can collide.
    bool canCollide(int a, int b){
        return (a>0 and b<0);
    }
    
    // returns out of 2 asteroids which will left after collision.
    int asteroidLeft(int a, int b){
        if(abs(a)==abs(b)){
            return 0;
        }
        if(abs(a)>abs(b)){
            return a;
        }
        return b;
    }
    
    // returns final state of asteroids after collision.
    vector<int> asteroidCollision(vector<int>& asteroids) {
        // stack for tracking dynamic state of asteroids.
        stack<int> st;
        for(int asteroid: asteroids){
            // flag is maintained for checking whether to push current asteroid to stack.
            bool flag = 1;
            while(st.size() and canCollide(st.top(),asteroid)){
                int left = asteroidLeft(st.top(),asteroid);
                if(left==0){
                    st.pop();
                    // if both got exploded then the current asteroid should not be pushed.
                    flag = 0;
                    break;
                }
                else if(left==asteroid){
                    st.pop();
                }
                else{
                    // if the current got exploded than can't be pushed.
                    flag = 0;
                    break;
                }
            }
            if(flag == 1){
                st.push(asteroid);
            }     
        }
        //final state of asteroids.
        vector<int> state(st.size());
        while(st.size()){
            state[st.size()-1] = st.top();
            st.pop();
        }
        return state;
    }
};