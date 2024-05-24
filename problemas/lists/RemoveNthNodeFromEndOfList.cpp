// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
private:
    int getLength(ListNode* head) {
        int length = 0;
        while (head != nullptr) {
            head = head->next;
            length++;
        }
        return length;
    }

public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int index = getLength(head) - n;

        ListNode* previousListNode = nullptr;
        ListNode* currentListNode = head;

        for (int i = 0; i < index; i++) {
            previousListNode = currentListNode;
            currentListNode = currentListNode->next;
        }

        if (previousListNode == nullptr) {
            head = head->next;
        } else {
            previousListNode->next = currentListNode->next;
        }

        return head;
    }
};