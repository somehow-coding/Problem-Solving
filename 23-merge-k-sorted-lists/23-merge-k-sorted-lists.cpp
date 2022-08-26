/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
        if(!l1){
            return l2;
        }
        if(!l2){
            return l1;
        }
        ListNode *head = NULL, *pre = NULL;
        while(l1 and l2){
            if(l1->val<l2->val){
                if(!head){
                    head = l1, pre = l1;
                }
                else{
                    pre->next = l1;
                    pre = l1;
                }
                l1 = l1->next;
            }
            else{
                if(!head){
                    head = l2, pre = l2;
                }
                else{
                    pre->next = l2;
                    pre = l2;
                }
                l2 = l2->next;
            }
        }
        if(l1){
            pre->next = l1;
        }
        else{
            pre->next = l2;
        }
        return head;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(!lists.size()){
            return NULL;
        }
        ListNode *head = lists[0];
        for(int i=1;i<lists.size(); i++){
            head = mergeTwoLists(head, lists[i]);
        }
        return head;
    }
};