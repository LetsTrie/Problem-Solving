#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// Insert a node at the head of a linked list
// https://www.hackerrank.com/challenges/insert-a-node-at-the-head-of-a-linked-list
ListNode* insertNodeAtHead(ListNode* head, int data) {
    ListNode* newNode = new ListNode(data);
    if (head == nullptr) return newNode;

    newNode->next = head;
    return newNode;
}

// Insert a node at a specific position in a linked list
// "position" is assumed to be zero-based.
// https://www.hackerrank.com/challenges/insert-a-node-at-a-specific-position-in-a-linked-list
ListNode* insertNodeAtPosition(ListNode* head, int data, int position) {
    int currentPosition = 0;
    ListNode* current = head;
    ListNode* newNode = new ListNode(data);

    while (++currentPosition < position && current->next != nullptr) {
        current = current->next;
    }

    if (current->next != nullptr) newNode->next = current->next;
    current->next = newNode;

    return head;
}

// Insert a Node at the Tail of a Linked List
// https://www.hackerrank.com/challenges/insert-a-node-at-the-tail-of-a-linked-list
ListNode* insertNodeAtLastPosition(ListNode* head, int data) {
    ListNode* newNode = new ListNode(data);
    if (head == nullptr) return newNode;

    ListNode* current = head;
    while (current->next != nullptr) current = current->next;

    current->next = newNode;
    return head;
}

// Delete a Node
// https://www.hackerrank.com/challenges/delete-a-node-from-a-linked-list
ListNode* deleteNodeAtPosition(ListNode* head, int position) {
    if (position == 0) return head -> next;
    ListNode* current = head;
    
    int currentPosition = 0;
    while(++currentPosition < position && current -> next != nullptr) {
        current = current -> next;
    }
    
    if (current -> next) {
        ListNode* nodeToDelete = current -> next;
        current -> next = nodeToDelete -> next;
        delete nodeToDelete;
    }
    
    return head;
}

ListNode* deleteDuplicates(ListNode* head) {
    ListNode* current = head;
    while (current) {
        if (current->next && current->val == current->next->val) {
            ListNode* temp = current->next;
            current->next = current->next->next;
            delete temp;
        } else {
            current = current->next;
        }
    }
    return head;
}

ListNode* reverseList(ListNode* head) {
    ListNode* reversed = nullptr;
    while (head) {
        ListNode* newNode = new ListNode(head->val);
        newNode->next = reversed;
        reversed = newNode;
        head = head->next;
    }
    return reversed;
}

// Print the Elements of a Linked List
// https://www.hackerrank.com/challenges/print-the-elements-of-a-linked-list/
// https://www.hackerrank.com/challenges/print-the-elements-of-a-linked-list-in-reverse/
void printList(ListNode* head) {
    if (head == nullptr) {
        cout << endl;
        return;
    }

    cout << head->val << " ";
    printList(head->next);
}

int main() {
    ListNode* head = nullptr;

    // Insertion
    head = insertNodeAtLastPosition(head, 1);
    head = insertNodeAtLastPosition(head, 2);
    head = insertNodeAtLastPosition(head, 2);
    head = insertNodeAtLastPosition(head, 3);
    head = insertNodeAtLastPosition(head, 4);
    head = insertNodeAtLastPosition(head, 4);
    head = insertNodeAtLastPosition(head, 4);

    cout << "Original List: ";
    printList(head);

    // Deletion
    int positionToDelete = 2;
    cout << "Deleting node at position " << positionToDelete << ": ";
    head = deleteNodeAtPosition(head, positionToDelete);
    printList(head);

    // Insertion at a specific position
    int newData = 5;
    int positionToInsert = 3;
    head = insertNodeAtPosition(head, newData, positionToInsert);
    cout << "List after inserting " << newData << " at position " << positionToInsert << ": ";
    printList(head);

    newData = 10;
    head = insertNodeAtHead(head, newData);
    cout << "List after inserting " << newData << " at the head: ";
    printList(head);

    // Duplicate removal
    ListNode* uniqueList = deleteDuplicates(head);
    cout << "List after removing duplicates: ";
    printList(uniqueList);

    // Reversing the list
    ListNode* reversedList = reverseList(uniqueList);
    cout << "Reversed List: ";
    printList(reversedList);

    return 0;
}
