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
    ListNode *detectCycle(ListNode *head) {
        // ListNode *temp=head;
        // unordered_map<ListNode*, int> mpp;
        // while(temp!=NULL){
        //     if(mpp.count(temp)!=0) {return temp;}
            
        //     mpp[temp]=1;
        //     temp=temp->next;
        // }
        // return NULL;
    ListNode* slow = head;  
    ListNode* fast = head;  

    // Phase 1: Detect the loop
    while (fast != NULL && fast->next != NULL) {

        slow = slow->next;        
        fast = fast->next->next;  
        if (slow == fast) {
            slow = head; 
            while (slow != fast) {
                slow = slow->next;  
                fast = fast->next;  
                }
            return slow;  
        }
    }
    return NULL;
    }
};
