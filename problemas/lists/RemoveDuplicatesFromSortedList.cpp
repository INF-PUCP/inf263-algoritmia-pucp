// https://leetcode.com/problems/remove-duplicates-from-sorted-list/
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* resultHead = nullptr;
        ListNode* previousResultNode = nullptr;
        ListNode* currentListNode = head;

        while (currentListNode != nullptr) {
            ListNode* nextListNode = currentListNode->next;
            if (resultHead == nullptr || currentListNode->val != previousResultNode->val) {
                if (resultHead == nullptr) {
                    resultHead = currentListNode;
                } else {
                    previousResultNode->next = currentListNode;
                }
                previousResultNode = currentListNode;
                previousResultNode->next = nullptr;
            }
            currentListNode = nextListNode;
        }

        return resultHead;
    }
};