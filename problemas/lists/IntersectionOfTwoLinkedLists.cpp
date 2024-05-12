// https://leetcode.com/problems/intersection-of-two-linked-lists/
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    int getSize(ListNode* head) {
        int listSize = 0;
        ListNode* currentListNode = head;
        while (currentListNode != nullptr) {
            currentListNode = currentListNode->next;
            listSize++;
        }
        return listSize;
    }

    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode* currentFirstNode = headA;
        int firstListSize = getSize(currentFirstNode);

        ListNode* currentSecondNode = headB;
        int secondListSize = getSize(currentSecondNode);

        while (firstListSize > secondListSize) {
            currentFirstNode = currentFirstNode->next;
            firstListSize--;
        }

        while (secondListSize > firstListSize) {
            currentSecondNode = currentSecondNode->next;
            secondListSize--;
        }

        while (currentFirstNode != currentSecondNode) {
            currentFirstNode = currentFirstNode->next;
            currentSecondNode = currentSecondNode->next;
        }

        return currentFirstNode;
    }
};