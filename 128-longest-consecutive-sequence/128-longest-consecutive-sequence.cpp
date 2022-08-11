class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //sort and count(take care of edges)....
        unordered_map<int,int> mp;
        for(int num: nums) mp[num]++;
        int retlen = 0;
        
        for(auto [key, val]: mp){
            cout<<"["<<key<<"]"<<" "<<val<<endl;
        }
        
        for(auto &p: mp){
            cout<<p.first<<endl;
            if(p.second==0){
                continue;
            }
            int len = 1, num;
            num = p.first - 1;
            while(mp.count(num) and mp[num]>0){
                len++;
                mp[num] = 0;
                num--;
            }
            num = p.first + 1;
            while(mp.count(num) and mp[num]>0){
                len++;
                mp[num] = 0;
                num++;
            }
            retlen = max(retlen, len);
        }
        return retlen;
    }
};