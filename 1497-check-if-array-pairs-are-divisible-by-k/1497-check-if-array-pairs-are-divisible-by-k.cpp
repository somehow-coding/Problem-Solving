class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        map<int,int> m;
        int y;
        for(int a: arr) {
            y = a%k;
            if(y<0) y+=k;
            m[y]++;
        }
        for(auto i: m) cout<<i.first<<" ";
        for(int i=0; i<size(arr); i++){
            int x = arr[i]%k;
            if(x<0) x += k;
            if(m[x]==0){
                continue;
            }
            m[x]--;
            if(x==0){
                if(m[0]) m[0]--;
                else return false;
            }
            else if(m[k-x]){
                m[k-x]--;
            }
            else{
                return false;
            }
        }
        return true;
    }
};