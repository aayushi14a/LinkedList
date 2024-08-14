#include <iostream>
//created by Aayushi Agrawal
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int val) {
        this->val = val;
        this->next = NULL;
    }
};

void insertAtHead(ListNode* &head, int val) {
    ListNode* n = new ListNode(val);
    n->next = head;
    head = n;
}

ListNode* getTail (ListNode* head) {
    while (head->next != NULL) {
        head = head->next;
    }
    return head;
}

void insertAtTail(ListNode* &head, int val) {
    ListNode* n = new ListNode(val);
    if (head == NULL) {
        head = n;
        return;
    }
    ListNode* tail = getTail(head);
    tail->next = n;
}

ListNode* getIndex(ListNode* head, int idx) {
    ListNode* temp = NULL;
    int cnt = 0;
    while (cnt < idx && head!= NULL) {
        head = head->next;
        cnt++;
    }
    return head;
}

void insertAtIndex(ListNode* &head, int val, int idx) {
    if (idx == 0) {
        insertAtHead(head, val);
        return;
    }
    ListNode* n = new ListNode(val);
    ListNode* prev = getIndex(head,idx - 1);
    if (prev == NULL) {
        return;
    }
    n->next = prev->next;
    prev->next = n;
}

void removeAtHead(ListNode* &head) {
    ListNode* n = head->next;
    head->next = NULL;
    head = n;
}

void removeAtTail(ListNode* &head) {
    ListNode* prev= NULL;
    ListNode* tail= head;
    while (tail->next != NULL) {
        prev = tail;
        tail = tail->next;
    }
    if (prev == NULL) {
        return;
    }
    prev->next = NULL;
    delete tail;
}

void removeAtIndex(ListNode* &head, int idx) {
    if (idx == 0) {
        removeAtHead(head);
    }
    ListNode* n = getIndex(head, idx - 1);
    if (n == NULL) {
        return;
    }
    ListNode* temp = n->next;
    if (temp == NULL) return;
    n->next = n->next->next;
    temp->next = NULL;
}

void getSize(ListNode* head) {
    int n = 0;
    while (head) {
        head = head->next;
        n++;
    }
    cout << "Size of LL: " << n << endl;
}

void printLinkedList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

void searchIterative(ListNode* head, int target) {
    while (head) {
        if (head->val == target) {
            cout << "Found " << target << " in the list" << endl;
            return;
        }
        head = head->next;
    }
    cout << target << " not in the list" << endl;
}

void searchRecursive(ListNode* head, int target) {
    if (!head) {
        cout << target << " not in the list" << endl;
        return;
    }
    if (head->val == target) {
        cout << "Found " << target << " in the list" << endl;
        return;
    }
    searchRecursive(head->next, target);
}

void reverseLinkedList(ListNode* &head){
    ListNode* prev = NULL;
    ListNode* curr = head;
    while (curr) {
        ListNode* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    head = prev;
}

int getMid1(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow->val;
}

int getMid2(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head->next;
    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow->val;
}

ListNode* kreverse(ListNode* &head, int k) {
    if (head == NULL) {
        return NULL;
    }
    int i = 1;
    ListNode* curr = head;
    ListNode* prev = NULL;
    while (i <= k && curr != NULL) {
        ListNode* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
        i++;
    }
    head->next = kreverse(curr,k);
    return prev;
}

ListNode* kthNode(ListNode* head, int k) {
    ListNode* temp = head;
    while (k--) {
        temp = temp->next;
    }
    ListNode* slow = head;
    while (temp) {
        slow = slow->next;
        temp = temp->next;
    }
    return slow;
}

int main()
{
    ListNode* head =  NULL;
    insertAtHead(head,10);
    insertAtHead(head,30);
    insertAtHead(head,50);
    insertAtHead(head,20);
    insertAtHead(head,40);
    printLinkedList(head);

    insertAtTail(head,60);
    insertAtTail(head,70);
    printLinkedList(head);

    insertAtIndex(head,80,6);
    printLinkedList(head);

    removeAtHead(head);
    printLinkedList(head);

    removeAtTail(head);
    printLinkedList(head);

    removeAtIndex(head,3);
    printLinkedList(head);

    getSize(head);
    searchIterative(head,50);
    searchRecursive(head,60);
    searchRecursive(head,70);

    reverseLinkedList(head);
    printLinkedList(head);

    cout << "The mid-value is " << getMid1(head) << endl;

    insertAtTail(head,70);
    printLinkedList(head);
    cout << "The mid-value is " << getMid1(head) << endl;
    cout << "The mid-value is " << getMid2(head) << endl;

    cout << "Original LL: " ;
    printLinkedList(head);
    cout << "Reversed LL: ";
    printLinkedList(kreverse(head,2));

    ListNode* kth = kthNode(head,2);
    cout << "Kth node from end is: " << kth->val << endl;

    //sortLinkedList(head);
    return 0;
}
