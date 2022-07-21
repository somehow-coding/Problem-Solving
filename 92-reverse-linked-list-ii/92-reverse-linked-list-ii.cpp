
class Solution {
public:
    void reverse(ListNode* head, ListNode* &list, int m, int n, int i){
        if(n==-1){
            return;
        }
        reverse(head->next, list, m, n-1, i+1);
        if(i<m) return;
        swap(list->val, head->val);
        list = list->next;
    }
    
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int i = 1;
        ListNode* ptr = head;
        while(i<left){
            i++;
            ptr = ptr->next;
        }
        int n = (right-left), m = (right-left)/2;
        if(n&1) m++;
        cout<<m;
        reverse(ptr, ptr, m, n, 0);
        return head;
    }
};