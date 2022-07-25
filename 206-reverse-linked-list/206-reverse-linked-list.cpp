class Solution {
public:
    void fun(ListNode* &i, ListNode* j, int &N){
        if(!j){
            return;
        }
        fun(i, j->next, N);
        if(N==0){
            return;
        }
        swap(i->val, j->val);
        N--;
        i = i->next;
    }
    
    ListNode* reverseList(ListNode* head) {
        int N = 0;
        ListNode* ptr = head;
        while(ptr){
            ptr = ptr->next;
            N++;
        }
        N = N/2;
        ptr = head;
        fun(ptr, head, N);
        return head;
    }
};