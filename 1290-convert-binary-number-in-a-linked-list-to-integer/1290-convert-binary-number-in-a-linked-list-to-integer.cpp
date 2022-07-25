class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int ans = 0, n = 0;
        ListNode* ptr = head;
        while(ptr){
            ptr= ptr->next;
            n++;
        }
        ptr = head, n--;
        while(ptr){
            ans = ans + ((ptr->val)*pow(2, n));
            n--;
            ptr= ptr->next;
        }
        return ans;
    }
};