class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head=NULL, *pre = NULL;
        while(list1 and list2){
            if(list1->val>list2->val){
                if(!head){
                    head = pre = list2;
                }
                else{
                    pre->next = list2;
                    pre = list2;
                }
                list2 = list2->next;
            }
            else{
                if(!head){
                    head = pre = list1;
                }
                else{
                    pre->next = list1;
                    pre = list1;
                }
                list1 = list1->next;
            }
        }
        if(list1){
            if(!pre) head = list1;
            else pre->next = list1;
        }
        if(list2){
            if(!pre) head = list2;
            else pre->next = list2;
        }
        return head;
    }
};