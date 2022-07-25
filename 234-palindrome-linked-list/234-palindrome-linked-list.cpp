class Solution {
public:
    bool is = true;
    
    void fun(ListNode* &i, ListNode* j){
        if(!j){
            return;
        }
        fun(i, j->next);
        if(i->val!=j->val){
            is = false;
        }
        i=i->next;
    }
    
    bool isPalindrome(ListNode* head) {
        ListNode* i = head, *j = head;
        fun(i, j);
        return is;
    }
};