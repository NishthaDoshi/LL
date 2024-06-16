class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

class MyLinkedList {
public:
     Node* head;
     Node* tail;
    MyLinkedList() {
       head = NULL;
       tail = NULL;    
    }
    
    int get(int ind) {
        Node* temp = head;
        int cnt = 0;
        while(temp != NULL && cnt < ind){
            temp = temp->next;
            cnt++;
        }
        if(temp != NULL) return temp->data;
        return -1;
    }
    
    void addAtHead(int val) {
        Node* newNode = new Node(val);
        newNode -> next = head;
        head = newNode;
        if(tail == NULL) tail = newNode;
    }
    
    void addAtTail(int val) {
        Node* newNode = new Node(val);
        if(tail == NULL){
            head = newNode;
            tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = tail->next;
        }
    }
    
    void addAtIndex(int ind, int val) {
        if(ind == 0){
            addAtHead(val);
            return;
        }
        Node* temp = head;
        int cnt  = 1;
        while(temp != NULL && cnt < ind){
            temp = temp->next;
            cnt++;
        }
        if(temp != NULL){
            if(temp->next == NULL){
                addAtTail(val);
                return;
            }
            Node* newNode = new Node(val);
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
    
    void deleteAtIndex(int ind) {
        if(ind == 0){
            if(head == tail) tail = NULL;
            Node* demo = head;
            head = head->next;
            delete demo;
            return;
        }
        Node* temp = head;
        int cnt = 1;
        while(temp != NULL && cnt < ind){
            temp = temp->next;
            cnt++;
        }
        if(temp != NULL && temp->next != NULL){
            Node*  demo = temp->next;
            if(temp->next->next == NULL) tail = temp;
            temp->next = temp->next->next;
            delete demo;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
