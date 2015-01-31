#include <algorithm>
#include <priority_queue>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct compare {
    bool operator()(ListNode* node1, ListNode* node2) { 
        if ( node1 != NULL && node2 != NULL )
            return node1->val > node2->val; 
        return false; 
    }
};
 
typedef priority_queue<ListNode*, vector<ListNode*>, compare> list_queue; 

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        list_queue pqueue;
        
        for ( auto it = lists.begin(); it != lists.end(); ++it ) {
                    if ( *it != NULL )
                        pqueue.push(*it);
        }
        
        if ( pqueue.empty() ) return NULL;
        
        ListNode* head = pqueue.top();
        pqueue.pop();
        ListNode* cur = head;
        
        while ( !pqueue.empty() ) {
            if ( cur->next != NULL )
                pqueue.push(cur->next); 
            
            ListNode* next = pqueue.top();
            pqueue.pop();
            cur->next = next;
            cur = cur->next;
        }
        
        return head;
    }
};
