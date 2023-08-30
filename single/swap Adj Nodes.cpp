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
    ListNode* swapPairs(ListNode* head) {
        ListNode* temp= head;
        ListNode* t1= head;
         ListNode* t2= t1->next;
         head=t2;
         t1->next =t2->next;
         t2->next=t1;
         temp=t1->next;
        while(temp!=NULL){
            ListNode* t2= t1->next;
            t1->next =t2->next;
         temp=t1->next;
        }

    }
};
