// https://leetcode.com/problems/middle-of-the-linked-list/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    int getSize(ListNode* head) {
        int listSize = 0;
        ListNode* currentListNode = head;
        while (currentListNode != nullptr) {
            listSize++;
            currentListNode = currentListNode->next;
        }
        return listSize;
    }
    ListNode* middleNode(ListNode* head) {
        int listSize = getSize(head);
        int steps = listSize / 2;
        ListNode* middleNode = head;
        for (int i = 0; i < steps; i++) {
            middleNode = middleNode->next;
        }
        return middleNode;
    }
};