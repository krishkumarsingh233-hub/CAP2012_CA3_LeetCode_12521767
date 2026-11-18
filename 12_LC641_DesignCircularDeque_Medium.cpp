class Node{
    public:
    int val;
    Node* prev;
    Node* next;

    Node(int data){
        val=data;
        prev=next=NULL;
    }
};

class MyCircularDeque {
public:
Node* head;
Node* tail;
int max_len;
int curr_len;
    MyCircularDeque(int k) {
        head=tail=NULL;
        max_len=k;
        curr_len=0;
    }
    
    bool insertFront(int value) {
        if(curr_len>=max_len) return false;
        if(!head){
            head=new Node(value);
            tail=head;
        }
        else{
            Node* temp=new Node(value);
            temp->next=head;
            head->prev=temp;
            head=temp;
        }
        curr_len++;
        return true;
    }
    
    bool insertLast(int value) {
        if(curr_len>=max_len) return false;

        if(!head){
            head=new Node(value);
            tail=head;
        }
        else{
            Node* temp=new Node(value);
            tail->next=temp;
            temp->prev=tail;
            tail=tail->next;
        }
        curr_len++;
        return true;
    }
    
    bool deleteFront() {
        if(!head) return false;
        if(head==tail){
            delete head;
            head=tail=NULL;
            curr_len--;
            return true;
        }
        Node*temp=head;
        head=head->next;
        delete temp;
        curr_len--;
        head->prev=NULL;
        return true;
    }
    
    bool deleteLast() {
        if(!tail) return false;
        if(head==tail){
            delete head;
            curr_len--;
            head=tail=NULL;
            return true;
        }
        Node*temp=tail;
        tail=tail->prev;
        tail->next=NULL;
        delete temp;
        curr_len--;
        return true;
    }
    
    int getFront() {
        if(!head) return -1;
        return head->val;
    }
    
    int getRear() {
        if(!tail) return -1;
        return tail->val;
    }
    
    bool isEmpty() {
        return curr_len==0;
    }
    
    bool isFull() {
       return curr_len==max_len; 
    }
};

