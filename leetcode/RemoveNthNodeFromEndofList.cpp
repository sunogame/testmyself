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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        ListNode* p1 = head;
        ListNode* p2 = head;
        for(int i=0;i<n;i++)
            p2 = p2->next;
        if(p2 == NULL)
        {
            ListNode* tmp = head;
            head = head->next;
            delete tmp;
            return head;
        }
        p2 = p2->next;
        while(p2)
        {
            p1 = p1->next;
            p2 = p2->next;
        }
        ListNode* tmp = p1->next;
        p1->next = p1->next->next;
        delete tmp;
        return head;
    }
};
