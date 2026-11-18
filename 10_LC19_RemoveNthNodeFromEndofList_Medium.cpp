class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode * temp = head;
        int c=0;
        while(temp!=NULL){
            c++;
            temp=temp->next;
        }
        if(c==1 && n==1){
            return NULL;
        }
        if(c==n){
           return  head=head->next;
        }
    ListNode * t=head;
    for(int i=0;i<c-n-1;i++){
        t=t->next;
    }
    ListNode   * t2=(t->next);
    ListNode * t3=NULL;
    if(t2!=NULL){
         t3=t2->next;

    }

   
    t->next=t3;

    return head;


    }
};
