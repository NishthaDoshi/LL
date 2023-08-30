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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL){
            return l2;
        }
        if(l2==NULL){
            return l1;
        }
        ListNode * head=l1;
        if(l1->val>l2->val){
            head=l2;
            l2=l2->next;
        }
        else{
            l1=l1->next;
        }
        ListNode *temp=head;
        while(l1!= NULL && l2!=NULL){
             if(l1 -> val < l2 -> val){
                temp->next = l1;
                l1 = l1 -> next;
            }
            else{
                temp->next = l2;
                l2 = l2 -> next;
            }
            temp = temp -> next;
        }
         if(!l1)
            temp -> next = l2;
        else
            temp -> next = l1;
            
        return head;
    }
//         ListNode* t1=list1;
//         ListNode* t2=list2;
};
