// https://leetcode.com/problems/task-scheduler/

class Solution {
private:
    const int ALPHABET = 26;

    int GetValue(const char& c) {
        return c - 'A';
    }

public:
    int leastInterval(vector<char>& tasks, int n) {
        int cooldown_period = n + 1;

        vector<int> frequencies(ALPHABET, 0);
        for (char task : tasks) {
            frequencies[GetValue(task)]++;
        }
        
        priority_queue<int, vector<int>, less<int>> max_heap;
        for (int frequency : frequencies) {
            if (frequency > 0) {
                max_heap.push(frequency);
            }
        }

        int min_units = 0;
        while (!max_heap.empty()) {
            vector<int> finished_tasks;
            int rem_period = cooldown_period;
            for (int i = 0; i < cooldown_period; i++) {
                if (max_heap.empty()) break;
                int max_task = max_heap.top();
                max_heap.pop();
                if (max_task > 1) finished_tasks.push_back(max_task - 1);
                min_units++;
                rem_period--;
            }
            for (int finished_task : finished_tasks) {
                max_heap.push(finished_task);
            }
            if (!max_heap.empty()) min_units += rem_period;
        }
        return min_units;
    }
};