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
    
    /*
    1->2->3->4
    5->6->7
    */
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        //recursive approach.
        
        // return fun(headA, headB);
        
        // a kind of cyclic approach will also work (no prove) but the method is simple
        // keep two pointers
        // traverse both simulataneously and then if someone become null point it again
        // to the start of the list.
        
        //how it works...(no prove + intutition it is just working)
        
        ListNode* ptr1 = headA, *ptr2 = headB;
        if(!ptr1 and !ptr2) return NULL;
        while(ptr1 and ptr2 and ptr1!=ptr2){
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
            if(ptr1 == ptr2){
                return ptr1;
            }
            if(!ptr1) ptr1 = headA;
            if(!ptr2) ptr2 = headB;
        }
        return ptr1;
    }
};