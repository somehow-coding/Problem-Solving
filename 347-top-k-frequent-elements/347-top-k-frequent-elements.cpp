class Solution {
public:
    typedef pair<int,int> pii;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int i: nums) mp[i]++;
        priority_queue<pii,vector<pii>,greater<pii>> pq;
        for(auto i: mp){
            pq.push({i.second,i.first});
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<int> res;
        while(pq.size()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};