import heapq
class Solution:
    def __init__(self):
        #小顶堆，元素数值都比大顶堆大
        self.max = [] 
        #大顶堆，元素数值较小，加入元素要乘-1才能实现大顶堆，取出时也要乘-1还原
        self.min = [] 
    def Insert(self, num):
        #先加入较小部分
        heapq.heappush(self.min, (-1 * num)) 
        #将较小部分的最大值取出，送入到较大部分
        heapq.heappush(self.max, -1 * self.min[0]) 
        heapq.heappop(self.min)
        #平衡两个堆的数量
        if len(self.min) < len(self.max):  
            heapq.heappush(self.min, -1 * self.max[0])
            heapq.heappop(self.max)
    def GetMedian(self):
        #奇数个
        if len(self.min) > len(self.max): 
            return self.min[0] * -1.0
        else:
            #偶数个
            return (-1 * self.min[0]  + self.max[0]) / 2 

if __name__ == "__main__":
    solution = Solution()

    solution.Insert(5)
    print("Current median:", solution.GetMedian())  # 输出：5.0

    solution.Insert(2)
    print("Current median:", solution.GetMedian())  # 输出：3.5

    solution.Insert(7)
    print("Current median:", solution.GetMedian())  # 输出：5.0

    solution.Insert(1)
    print("Current median:", solution.GetMedian())  # 输出：3.0
