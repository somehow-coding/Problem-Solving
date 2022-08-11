class Solution {
public:
    bool valid; 
    
    long MAX(long a, long b){
        return a>b?a:b;
    }
    
    long MIN(long a, long b){
        return b>a?a:b;
    }
    
    //pair [min, max]
    pair<long,long> fun(TreeNode* root){
        if(!root){
            return {LONG_MIN,LONG_MAX};
        }
        auto l = fun(root->left), r = fun(root->right);
        if(!(l.first<root->val and root->val<r.second)){
            valid = false;
        }
        auto maxi = MAX(root->val,r.first);
        auto mini = MIN(root->val,l.second);
        return {maxi,mini};
    }
    
    bool isValidBST(TreeNode* root) {
        valid = true;
        fun(root);
        return valid;
    }
};