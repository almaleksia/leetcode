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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if ( m == n ) return head;
        
        int i = 1;
        int head_begin = 0;
        ListNode* subhead = head;
        ListNode* cur = NULL;
        stack<ListNode*> st;
        
        ListNode* save_subhead = subhead;
        while( i <= n ) {
           
            if ( i < m && subhead->next != NULL) {
                save_subhead = subhead;
                subhead = subhead->next;
            }
            
            if ( i >= m ) {
                if ( i == m ) {
                    if ( subhead == head ) {
                        head_begin = 1;
                        cur = subhead;
                    } else {
                        cur = save_subhead->next;
                        subhead = save_subhead;
                    }
                }
                else {
                    if ( cur->next != NULL ) {
                        cur = cur->next;
                    } else { break; }
                }
                
                st.push(cur);
            }
            
            i++;
        }
        
        ListNode* tail = NULL;
        int first = 1;
      
        while( !st.empty() ) {
            if ( first ) { 
                tail = st.top();
                tail = tail->next;
                first = 0;
                
                if ( head_begin) {
                    head = subhead = st.top();
                } else {
                    subhead->next = st.top();
                }
                
                cur = st.top();
            } else {
                cur->next = st.top();
                cur = cur->next;
            }
            
            st.pop();
        }
        
        if ( cur != NULL ) {
            cur->next = tail;
        }
        
        return head;    
    }
};
