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
class Solution {
public:
    int Size(ListNode* head) {
        int cnt = 0;
        while (head != nullptr) {
            cnt++;
            head = head->next;
        }
        return cnt;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int number_lists = lists.size();
        vector<int> list_size, last_position;
        vector<ListNode*> current;

        int total_size = 0;
        for (int i = 0; i < number_lists; i++) {
            list_size.push_back(Size(lists[i]));
            last_position.push_back(0);
            current.push_back(lists[i]);
            total_size += list_size[i];
        }

        ListNode* head;
        ListNode* tail;
        head = tail = nullptr;
        
        for (int i = 0; i < total_size; i++) {
            pair<int, int> ind_val = {-1, 1e5};
            for (int j = 0; j < number_lists; j++) {
                if (last_position[j] < list_size[j] &&
                    current[j]->val < ind_val.second) {
                  ind_val.first = j;
                  ind_val.second = current[j]->val;
                }
            }
            if (head == nullptr) {
              head = new ListNode(ind_val.second);
              tail = head;
            } else {
              tail->next = new ListNode(ind_val.second);
              tail = tail->next;
            }
            last_position[ind_val.first]++;
            current[ind_val.first] = current[ind_val.first]->next;
        }

        return head;
    }
};
