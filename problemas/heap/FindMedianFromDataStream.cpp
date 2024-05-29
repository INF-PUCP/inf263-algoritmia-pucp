// https://leetcode.com/problems/find-median-from-data-stream/
class MedianFinder {
private:
    priority_queue<int> firstHalf;
    priority_queue<int, vector<int>, greater<int>> secondHalf;

public:
    MedianFinder() {
        firstHalf = priority_queue<int>();
        secondHalf = priority_queue<int, vector<int>, greater<int>>();
    }
    
    void addNum(int num) {
        if (firstHalf.empty() || firstHalf.top() >= num) {
            firstHalf.push(num);
        } else {
            secondHalf.push(num);
        }

        while (secondHalf.size() > firstHalf.size()) {
            int lowest = secondHalf.top();
            secondHalf.pop();
            firstHalf.push(lowest);
        }

        while (firstHalf.size() > secondHalf.size() + 1) {
            int highest = firstHalf.top();
            firstHalf.pop();
            secondHalf.push(highest);
        }
    }
    
    double findMedian() {
        double median = 0.0;

        if (firstHalf.size() == secondHalf.size()) {
            median = (firstHalf.top() + secondHalf.top()) / 2.0;
        } else {
            median = double(firstHalf.top());
        }

        return median;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */