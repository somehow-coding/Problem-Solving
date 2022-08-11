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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // int N = 0;
        // ListNode* node = head;
        // while(node) node=node->next, N++;
        // N -= n;
        // if(N==0){
        //     return head->next;
        // }
        // N-=1;
        // node = head;
        // while(N--){
        //     node = node->next;
        // }
        // node->next = node->next->next;
        // return head;
        
        int N = 0;
        
        //doing this for ease
        ListNode* temp_head = new ListNode(-1);
        temp_head->next = head;
        
        ListNode* node = temp_head;
        while(node) node=node->next, N++;
        N = N - n - 1;
        node = temp_head;
        while(N>0){
            node = node->next;
            N--;
        }
        node->next = node->next->next;
        return temp_head->next;
    }
};