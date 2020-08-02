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
    bool isPalindrome(ListNode* head) {
        if(head==NULL)
            return true;
        ListNode *slow = head, *fast = head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        
        ListNode *middle = slow, *prev = NULL, *cur = NULL;
        while(middle!=NULL){
            cur = middle->next;
            middle->next = prev;
            prev = middle;
            middle = cur;
        }
        while(prev!=NULL&&head!=NULL){
            if(prev->val!=head->val)
                return false;
            prev = prev->next;
            head = head->next;
        }
        return true;
    }
};