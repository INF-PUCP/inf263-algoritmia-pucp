// https://leetcode.com/problems/top-k-frequent-elements/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& numbers, int k) {
        unordered_map<int, int> frequencies;
        for (int number : numbers) {
            if (frequencies.count(number) > 0) {
                frequencies[number]++;
            } else {
                frequencies[number] = 1;
            }
        }

        vector<pair<int, int>> frequencyNumberPairs;
        for (pair<int, int> numberFrequency : frequencies) {
            int number = numberFrequency.first;
            int frequency = numberFrequency.second;
            frequencyNumberPairs.push_back({frequency, number});
        }

        sort(frequencyNumberPairs.begin(), frequencyNumberPairs.end(), greater{});

        vector<int> kMostFrequentNumbers;
        for (int i = 0; i < k; i++) {
            kMostFrequentNumbers.push_back(frequencyNumberPairs[i].second);
        }
        return kMostFrequentNumbers;
    }
};