class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head == NULL) return head;
        
        ListNode* Temp = head;

        while (Temp->next != NULL){
            if (Temp->next->val == val) {
                Temp->next = Temp->next->next;
            }
            else{
                Temp = Temp->next;
            }
        }

        if (head->val == val){
            head = head->next;
        }

        return head;
    }
};
