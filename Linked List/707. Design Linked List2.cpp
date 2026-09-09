class MyLinkedList {
private:
    int val;
    MyLinkedList* next;

public:
    MyLinkedList* head = nullptr;

    MyLinkedList(int val = 0) : val(val), next(nullptr) {}

    int get(int index) {
        MyLinkedList* ptr = head;

        for (int i = 0; i < index; i++) {
            if (ptr == nullptr)
                return -1;

            ptr = ptr->next;
        }

        if (ptr == nullptr)
            return -1;

        return ptr->val;
    }

    void addAtHead(int val) {
        MyLinkedList* newNode = new MyLinkedList(val);

        newNode->next = head;
        head = newNode;
    }

    void addAtTail(int val) {
        MyLinkedList* newNode = new MyLinkedList(val);

        if (head == nullptr) {
            head = newNode;
            return;
        }

        MyLinkedList* ptr = head;

        while (ptr->next != nullptr) {
            ptr = ptr->next;
        }

        ptr->next = newNode;
    }

    void addAtIndex(int index, int val) {
        if (index < 0)
            return;

        if (index == 0) {
            addAtHead(val);
            return;
        }

        MyLinkedList* ptr = head;

        for (int i = 0; i < index - 1; i++) {
            if (ptr == nullptr)
                return;

            ptr = ptr->next;
        }

        if (ptr == nullptr)
            return;

        MyLinkedList* newNode = new MyLinkedList(val);

        newNode->next = ptr->next;
        ptr->next = newNode;
    }

    void deleteAtIndex(int index) {
        if (head == nullptr || index < 0)
            return;

        if (index == 0) {
            MyLinkedList* del = head;
            head = head->next;
            delete del;
            return;
        }

        MyLinkedList* ptr = head;

        for (int i = 0; i < index - 1; i++) {
            if (ptr == nullptr)
                return;

            ptr = ptr->next;
        }

        if (ptr == nullptr || ptr->next == nullptr)
            return;

        MyLinkedList* del = ptr->next;

        ptr->next = del->next;
        delete del;
    }
};