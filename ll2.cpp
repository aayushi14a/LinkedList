#include <iostream>
//created by Aayushi Agrawal
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode (int val) {
        this->val = val;
        this->next = NULL;
    }
};

void printLL(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

bool detectCycle(ListNode* head) {
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return true;
        }
    }
    return false;
}

void removeCycle(ListNode* head) {
    ListNode* slow = head;
    ListNode *fast = head;
    while (true) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) break;
    }
    slow = head;
    while (slow->next != fast->next) {
        slow = slow->next;
        fast = fast->next;
    }
    fast->next = NULL;
}

int main()
{
    ListNode* head = new ListNode(10);
    head->next = new ListNode(30);
    head->next->next = new ListNode(20);
    head->next->next->next = new ListNode(50);
    head->next->next->next->next = new ListNode(60);
    head->next->next->next->next->next = new ListNode(40);
    head->next->next->next->next->next->next = head->next;

    // printLL(head);
    detectCycle(head)? cout << "contains a cycle" << endl : cout << "does not contain a cycle" << endl;
    removeCycle(head);
    printLL(head);
    return 0;
}
