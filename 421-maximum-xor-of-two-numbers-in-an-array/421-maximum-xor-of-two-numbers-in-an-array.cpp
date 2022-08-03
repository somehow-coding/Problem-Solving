struct TrieNode{
    TrieNode* bits[2];
    
    void create_new_link(int bit, TrieNode* node){
        bits[bit] = node;
    }
    TrieNode* next_node(int bit){
        return bits[bit];
    }
};

class Trie{
  public:
    TrieNode* root;
    Trie(){
        root = new TrieNode();
    }
    
    void insert(int n){
        TrieNode* node = root;
        for(int i=31; i>=0; i--){
            int bit = (n>>i) & 1;
            if(!(node->next_node(bit))){
                node->create_new_link(bit, new TrieNode());
            }
            node = node->next_node(bit);
        }
    }
    
    int maxXor(int n){
        TrieNode* node = root;
        int mx = 0;
        for(int i=31; i>=0; i--){
            int bit = (n>>i) & 1;
            if(node->next_node(!bit)!=NULL){
                mx = mx + pow(2,i);
                node = node->next_node(!bit);
            }
            else{
                node = node->next_node(bit);
            }
        }
        return mx;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie T;
        for(int n: nums) T.insert(n);
        int res = 0;
        for(int n: nums){
            res = max(res, T.maxXor(n));
        }
        return res;
    }
};