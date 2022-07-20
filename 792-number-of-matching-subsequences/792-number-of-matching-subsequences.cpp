struct Node{
        Node* nodes[26];
        void create_link(char c, Node* node){
            nodes[c-'a'] = node;
        }
        Node* next(char c){
            return nodes[c-'a'];
        }
        int flag = 0;
    };
    
    class Trie{
        public:
        Node* root;
        int cnt = 0;
        Trie(){
            root = new Node();
        }
        
        void insert(string &s){
            Node* node = root;
            for(char c: s){
                if(node->next(c)==NULL){
                    node->create_link(c, new Node());
                }
                node = node->next(c);
            }
            node->flag++;
        }  
        
        void fun(string &s, Node* node, int i){
            if(node->flag){
                cnt+=node->flag;
            }
            if(i==size(s)){
                return;
            }
            for(char c='a'; c<='z'; c++){
                int j = i;
                if(node->next(c)){
                    while(j<size(s) and s[j]!=c) j++;
                    if(j<size(s)) fun(s, node->next(c), j+1);
                }
            }
        }
        
        void cntFun(string s){
            fun(s, root, 0);
        }
    };

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        Trie T;
        for(string &t: words){
            T.insert(t);
        }
        T.cntFun(s);
        return T.cnt;
    }
};