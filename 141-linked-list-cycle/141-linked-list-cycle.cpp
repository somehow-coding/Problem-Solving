/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    
    bool hasCycle(ListNode *head) {
        //approach 1:
        set<ListNode*> nodes_visited;
        ListNode* ptr = head;
        while(ptr){
            if(nodes_visited.count(ptr)){
                return true;
            }
            else{
                nodes_visited.insert(ptr);
            }
            ptr = ptr->next;
        }
        return false;
    } 
};