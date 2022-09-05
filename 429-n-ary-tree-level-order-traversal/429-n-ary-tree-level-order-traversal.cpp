/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node*> q;
        q.push(root);
        
        if(!root) {
            return {};
        }
        
        vector<vector<int>> res;
        
        while(q.size()) {            
            int n = q.size();
            vector<int> temp;
            
            while(n--) {
                Node* node = q.front();
                q.pop();
                temp.push_back((node->val));
                for(auto child: node->children) {
                    q.push(child);
                }
            }
            
            res.push_back(temp);
        }
        return res;
    }
};