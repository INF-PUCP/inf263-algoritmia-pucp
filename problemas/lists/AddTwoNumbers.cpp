// https://leetcode.com/problems/add-two-numbers/
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = nullptr;
        ListNode* currentListNode = nullptr;

        ListNode* firstCurrentNode = l1;
        ListNode* secondCurrentNode = l2;
        int carry = 0;
        while (firstCurrentNode != nullptr || secondCurrentNode != nullptr) {
            if (firstCurrentNode != nullptr) {
                carry += firstCurrentNode->val;
                firstCurrentNode = firstCurrentNode->next;
            }
            if (secondCurrentNode != nullptr) {
                carry += secondCurrentNode->val;
                secondCurrentNode = secondCurrentNode->next;
            }

            int digit = carry % 10;
            carry /= 10;
            if (head == nullptr) {
                head = new ListNode(digit);
                currentListNode = head;
            } else {
                currentListNode->next = new ListNode(digit);
                currentListNode = currentListNode->next;
            }
        }

        if (carry > 0) {
            currentListNode->next = new ListNode(carry);
        }

        return head;
    }
};