class Solution {
public:
     ListNode* fun(ListNode* a, ListNode* b){
        if(!a and !b){
            return NULL;
        }
        if(a and a->val==INT_MAX){
            return a;
        }
        if(b and b->val==INT_MAX){
            return b;
        }
        if(a==b){
            return a;
        }
        ListNode* ret = NULL;
        int x, y;
        if(a and b){
            x = a->val, y = b->val;
            a->val = INT_MAX, b->val=INT_MAX;
            ret = fun(a->next, b->next);
            a->val = x, b->val = y;
        }
        else if(a){
            x = a->val;
            a->val = INT_MAX;
            ret = fun(a->next, b);
            a->val = x;
        }
        else{
            x = b->val;
            b->val = INT_MAX;
            ret = fun(a, b->next);
            b->val = x;
        }
        return ret;
    }
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        return fun(headA, headB);
    }
};