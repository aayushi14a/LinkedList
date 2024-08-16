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

ListNode* mergeSortedLL(ListNode* head1, ListNode* head2) {
    ListNode* dummy = new ListNode(-1);
    ListNode* head = dummy;
    while (head1 && head2) {
        if (head1->val < head2->val) {
            dummy->next = head1;
            head1 = head1->next;
        } else {
            dummy->next = head2;
            head2 = head2->next;
        }
        dummy = dummy->next;
    }
    if (!head2) {
        dummy->next = head1;
    }
    if (!head1) {
        dummy->next = head2;
    }
    return head->next;
}

ListNode* getMidP (ListNode* head) {
    if (!head) {
		return head;
	}
    ListNode* slow = head;
    ListNode* fast = head->next;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

ListNode* mergeSort(ListNode* head1) {
    if (head1 == NULL || head1->next == NULL) {
		return head1;
	}
    ListNode* midP = getMidP(head1);
    ListNode* head2 = midP->next;
    midP->next = NULL;
    head1 = mergeSort(head1);
    head2 = mergeSort(head2);
    return mergeSortedLL(head1, head2);
}

void removeDuplicates(ListNode* head) {
    ListNode* prev = head;
    ListNode* curr = head->next;
    while (curr) {
        if (curr->val != prev->val) {
            prev->next = curr;
            prev = curr;
        }
        curr = curr->next;
    }
    prev->next = NULL;
}

int main()
{
    ListNode* head = new ListNode(10);
    head->next = new ListNode(30);
    head->next->next = new ListNode(70);
    head->next->next->next = new ListNode(20);
    head->next->next->next->next = new ListNode(40);
    head->next->next->next->next->next = new ListNode(30);
    head->next->next->next->next->next->next = new ListNode(50);
    printLL(head);
    head = mergeSort(head);
    printLL(head);
    removeDuplicates(head);
    printLL(head);
    return 0;
}
