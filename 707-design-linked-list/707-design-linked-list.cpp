class MyLinkedList {
public:
    struct LinkedNode {
        int val;
        LinkedNode* next;
        LinkedNode(int val): val(val), next(nullptr) {}
    };
    int size;
    LinkedNode* dummy;
    
    MyLinkedList() {
        dummy = new LinkedNode(0);
        size = 0;
    }
    
    int get(int index) {
        if (index > size - 1 || index < 0) return -1;
        LinkedNode* cur = dummy->next;
        
        for (int i = 0; i < index; ++i) {
            cur = cur->next;
        }
        return cur->val;
    }
    
    void addAtHead(int val) {
        LinkedNode* newHead = new LinkedNode(val);
        newHead->next = dummy->next;
        dummy->next = newHead;
        size++;
    }
    
    void addAtTail(int val) {
        LinkedNode* newTail = new LinkedNode(val);
        LinkedNode* cur = dummy;
        
        for (int i = 0; i < size; ++i) {
            cur = cur->next;
        }
        cur->next = newTail;
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if (index > size || index < 0) return;
        
        LinkedNode* newNode = new LinkedNode(val);
        LinkedNode* cur = dummy;
        
        for (int i = 0; i < index; ++i) {
            cur = cur->next;
        }
        newNode->next = cur->next;
        cur->next = newNode;
        size++;
    }
    
    void deleteAtIndex(int index) {
        if (index >= size || index < 0) return;
        LinkedNode* cur = dummy;
        
        for (int i = 0; i < index; ++i) {
            cur = cur->next;
        }
        LinkedNode* temp = cur->next;
        cur->next = cur->next->next;
        delete temp;
        size--;
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