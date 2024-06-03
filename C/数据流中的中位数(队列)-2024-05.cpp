
#include <iostream>
#include <queue>

using namespace std;

class MedianFinder {
    priority_queue<int, vector<int>, less<int>> maxHeap; // 大顶堆，存放比中位数小的数
    priority_queue<int, vector<int>, greater<int>> minHeap; // 小顶堆，存放比中位数大的数

public:
    MedianFinder() {}

    void Insert(int num) 
    {
        if (maxHeap.empty() || num <= maxHeap.top()) 
        {
            maxHeap.push(num);
        }
        else 
        {
            minHeap.push(num);
        }

        // 调整两个堆的元素个数
        if (maxHeap.size() > minHeap.size() + 1)
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        else if (minHeap.size() > maxHeap.size()) 
        {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    double GetMedian() 
    {
        if (maxHeap.size() == minHeap.size()) 
        {
            return (maxHeap.top() + minHeap.top()) / 2.0;
        }
        else 
        {
            return maxHeap.top();
        }
    }
};



int main678() {
    MedianFinder finder;

    finder.Insert(5);
    cout << "Current median: " << finder.GetMedian() << endl; // 输出：5

    finder.Insert(2);
    cout << "Current median: " << finder.GetMedian() << endl; // 输出：3.5

    finder.Insert(7);
    cout << "Current median: " << finder.GetMedian() << endl; // 输出：5

    finder.Insert(1);
    cout << "Current median: " << finder.GetMedian() << endl; // 输出：3

    return 0;
}
