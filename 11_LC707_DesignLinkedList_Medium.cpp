class node {
        public: 
        int val;
        node*next;

        node(int d){
            val = d;
            next = NULL ;
        }
} ;

class MyLinkedList {
public:
    node*head;
    node*tail;
    int size;


    MyLinkedList() {
        head= tail = NULL;
        size = 0;
        
      
    }
    
    int get(int index) {
        if(index<0 || index>=size)
            return -1;
        else if(index==0) return head->val;
        else if(index==size-1) return tail->val;
        else {
            node*temp = head;
            for(int i = 1; i<=index; i++) {
                temp = temp->next ;
            }
            return temp->val;
        }
    }
    
    void addAtHead(int val) {
        node *temp = new node(val);

        if(size==0) {
            head= tail = temp;
            size++;
        }
        else {
        temp->next = head;
        head = temp ;
        size++;
        }

    }
    
    void addAtTail(int val) {
        node*temp = new node(val) ;
        if(size==0) {
            head=tail=temp;
            size++;
        }
        else {
        tail->next = temp;
        tail = temp;
        size++;
        }
    }
    
    void addAtIndex(int index, int val) {
        if(index==0) {
            addAtHead(val);
            return;
        }
        else if(index==size) {
            addAtTail(val);
            return;
        }
        else if(index<0 || index>=size) {
            return;
        }
        else {
            node*temp = head;
            for(int i = 0; i<index-1; i++) {
                temp = temp->next;
            }
            node*nodetoinsert = new node(val) ;
            nodetoinsert->next = temp->next;
            temp->next = nodetoinsert;
            size++;

        }
        
    }
    
    void deleteAtIndex(int index) {
        if(index<0 || index>=size) return;
        else if(index==0) {
            node*temp = head;
            head = head->next;
            delete temp;
            size--;
            return;
        }
        else if(index==size-1) {
            node*temp = head;
            while(temp->next!=tail) {
                temp = temp->next;
            }
            tail = temp;

            temp= temp->next;
            tail->next = NULL;
            delete temp;
            size--;
        }
        else {
            node* temp = head;
            for(int i=0; i<index-1; i++) {
                temp = temp->next;
            }
            node* delnode = temp->next;
            temp->next = temp->next->next;
            delete delnode;
            size--;
            

        }
        
    }
};

