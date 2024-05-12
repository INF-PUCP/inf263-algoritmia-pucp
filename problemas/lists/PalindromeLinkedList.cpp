// https://leetcode.com/problems/palindrome-linked-list/

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

    ListNode* reverseList(ListNode* head, int listSize) {
        ListNode* previousListNode = nullptr;
        ListNode* currentListNode = head;
        ListNode* nextListNode = nullptr;
        while (listSize > 0) {
            nextListNode = currentListNode->next;
            currentListNode->next = previousListNode;
            previousListNode = currentListNode;
            currentListNode = nextListNode;
            listSize--;
        }
        return previousListNode;
    }

    bool isPalindrome(ListNode* head) {
        int listSize = getSize(head);

        if (listSize <= 1) {
            return true;
        }

        int halfListSize = listSize / 2;

        ListNode* secondHalfHead = head;
        int steps = halfListSize;
        if (listSize % 2 == 1) {
            steps++;
        }
        for (int i = 0; i < steps; i++) {
            secondHalfHead = secondHalfHead->next;
        }

        ListNode* firstHalfHead = reverseList(head, halfListSize);

        ListNode* firstHalfCurrent = firstHalfHead;
        ListNode* secondHalfCurrent = secondHalfHead;

        for (int i = 0; i < halfListSize; i++) {
            if (firstHalfCurrent->val != secondHalfCurrent->val) {
                return false;
            }
            firstHalfCurrent = firstHalfCurrent->next;
            secondHalfCurrent = secondHalfCurrent->next;
        }

        return true;
    }
};