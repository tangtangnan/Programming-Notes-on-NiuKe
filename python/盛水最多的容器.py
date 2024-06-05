from typing import List 

class Solution:
    def maxArea(self , height: List[int]) -> int:
        #排除不能形成容器的情况
        if len(height) < 2: 
            return 0
        res = 0
        #双指针左右界
        left = 0 
        right = len(height) - 1
        #共同遍历完所有的数组
        while left < right:
            #计算区域水容量
            capacity = min(height[left], height[right]) * (right - left) 
            #维护最大值
            res = max(res, capacity) 
            #优先舍弃较短的边
            if height[left] < height[right]: 
                left += 1
            else:
                right -= 1
        return res

if __name__ == "__main__":
    s = Solution()
    nums = [1,7,3,2,4,5,8,2,2,2,7]
    result = s.maxArea(nums)
    print(result) 

