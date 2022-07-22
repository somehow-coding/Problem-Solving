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
    ListNode* partition(ListNode* head, int x) {
        ListNode* part1=NULL, *part2=NULL, *ptr = head, *i;
        ListNode* head1 = NULL, *head2 = NULL;
        while(ptr){
            i = ptr;
            ptr = ptr->next;
            if(i->val<x){
                if(!part1){
                    head1 = part1 = i;
                }
                else{
                    part1->next = i;
                    part1 = i;
                }
                i->next = NULL;
            }
            else{
                if(!part2){
                    head2 = part2 = i;
                }
                else{
                    part2->next = i;
                    part2 = i;
                }
                i->next = NULL;
            }
        }
        head = head1;
        if(!head) return head2;
        if(part1) part1->next = head2;
        return head;
    }
};