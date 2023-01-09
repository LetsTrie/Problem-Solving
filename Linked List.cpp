/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// Problem: https://leetcode.com/problems/remove-duplicates-from-sorted-list/
ListNode* deleteDuplicates(ListNode* head) {
  ListNode* cur = head;
  while(cur) {
    if(cur->next && cur->val == cur->next->val) {
      ListNode* tNode = cur->next;
      cur->next = cur->next->next;
      delete(tNode);
    } else {
      cur = cur->next;
    }
  }

  return head;
}

// Problem: https://leetcode.com/problems/reverse-linked-list/
ListNode* reverseList(ListNode* head) {
  ListNode* rev = NULL;

  while(head) {
    ListNode* node = new ListNode(head->val);
    node->next = rev;
    rev = node;
    head = head->next;
  }

  return rev;
}
