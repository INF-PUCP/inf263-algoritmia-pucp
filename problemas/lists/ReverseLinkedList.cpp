// https://leetcode.com/problems/reverse-linked-list/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* previousListNode = nullptr;
        ListNode* currentListNode = head;
        ListNode* nextListNode = nullptr;
        while (currentListNode != nullptr) {
            nextListNode = currentListNode->next;
            currentListNode->next = previousListNode;
            previousListNode = currentListNode;
            currentListNode = nextListNode;
        }
        return previousListNode;
    }
};