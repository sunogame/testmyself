/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
    	//copy node
    	if(head==NULL)
    	    return head;
    	RandomListNode* trav = head;
    	while( trav )
    	{
    		RandomListNode* tmp = new RandomListNode(trav->label);
    		tmp->next = trav->next;
    		trav->next = tmp;
    		trav = trav->next->next;
    	}
    	//copy random
    	trav = head;
    	while( trav )
    	{
    	    if(trav->random)
                trav->next->random = trav->random->next;
    		trav = trav->next->next;
    	}
    	// separate
    	RandomListNode* ans = head->next;
    	RandomListNode* copy = head->next;
    	trav = head;
    	while( trav )
    	{
    		trav->next = trav->next->next;
    		if(copy->next)
                copy->next = copy->next->next;
    		trav = trav->next;
    		copy = copy->next;
    	}
    	return ans;
    }
};

