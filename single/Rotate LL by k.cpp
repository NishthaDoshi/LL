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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next == NULL ||k==0)
        {
        return head ;
        }
        ListNode* cur = head ;
        int len = 1;
        while(cur->next!=NULL)
        {
        ++len ;
        cur = cur->next ;
        }

        //Pointing the last node to the head;
        cur->next = head ;
        k = k % len ;
        k = len - k ; //how many times to travers
        while(k--)
        {
        cur = cur->next ;
        }

        //Make the node to the head and break the connection
        head = cur->next ;
        cur->next = NULL ;

        return head;


    }
};
