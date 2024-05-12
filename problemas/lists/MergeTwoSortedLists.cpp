// https://leetcode.com/problems/merge-two-sorted-lists/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* currentFirstListNode = list1;
        ListNode* currentSecondListNode = list2;

        ListNode* headListNode = nullptr;
        ListNode* currentListNode = nullptr;
        ListNode* target = nullptr;

        while (currentFirstListNode != nullptr || currentSecondListNode != nullptr) {
            if (
                currentSecondListNode == nullptr ||
                currentFirstListNode != nullptr && currentFirstListNode->val < currentSecondListNode->val
            ) {
                target = currentFirstListNode;
                currentFirstListNode = currentFirstListNode->next;
            } else {
                target = currentSecondListNode;
                currentSecondListNode = currentSecondListNode->next;
            }

            if (headListNode == nullptr) {
                headListNode = target;
                currentListNode = target;
            } else {
                currentListNode->next = target;
                currentListNode = target;
            }

            currentListNode->next = nullptr;
        }

        return headListNode;
    }
};