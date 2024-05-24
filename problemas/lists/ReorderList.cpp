// https://leetcode.com/problems/reorder-list/
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
            length++;
            head = head->next;
        }
        return length;
    }

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
public:
    void reorderList(ListNode* head) {
        int listLength = getLength(head);
        if (listLength == 1) return;

        ListNode* previousNode = nullptr;
        ListNode* secondHalfHead = head;
        int offset = (listLength + 1) / 2;
        for (int i = 0; i < offset; i++) {
            previousNode = secondHalfHead;
            secondHalfHead = secondHalfHead->next;
        }
        previousNode->next = nullptr;
        secondHalfHead = reverseList(secondHalfHead);

        ListNode* firstHalfHead = head;
        for (int i = 0; i < listLength; i++) {
            if (i % 2 == 0) {
                ListNode* nextFirstHalfHead = firstHalfHead->next;
                firstHalfHead->next = secondHalfHead;
                firstHalfHead = nextFirstHalfHead;
            } else {
                ListNode* nextSecondHalfHead = secondHalfHead->next;
                secondHalfHead->next = firstHalfHead;
                secondHalfHead = nextSecondHalfHead;
            }
        }
    }
};