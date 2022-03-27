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
class List {
public:
  ListNode* head;
  ListNode* tail;

  List() : head(nullptr), tail(nullptr) {}

  void Push(int val) {
    if (head == nullptr) {
      head = new ListNode(val);
      tail = head;
    } else {
      tail->next = new ListNode(val);
      tail = tail->next;
    }
  }
};

class Solution {
public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    List sum;
    int carry = 0;
    int current = 0;
    while (l1 != nullptr || l2 != nullptr) {
      if (l1 == nullptr) {
        current = carry + l2->val;  
        sum.Push(current % 10);
        carry = current / 10;
        l2 = l2->next;
        continue;
      }
      if (l2 == nullptr) {
        current = carry + l1->val;
        sum.Push(current % 10);
        carry = current / 10;
        l1 = l1->next;
        continue;
      }
      current = carry + l1->val + l2->val;
      l1 = l1->next;
      l2 = l2->next;
      sum.Push(current % 10);
      carry = current / 10;
    }
    if (carry > 0) sum.Push(carry);
    return sum.head;
  }
};
