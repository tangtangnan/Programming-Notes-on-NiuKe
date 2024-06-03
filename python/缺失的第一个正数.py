from typing import List 

class Solution:
    def minNumberDisappeared(self , nums: List[int]) -> int:
        n = len(nums)
        mp = dict()
        #哈希表记录数组中出现的每个数字
        for i in range(n): 
            if nums[i] in mp:
                mp[nums[i]] += 1
            else:
                mp[nums[i]] = 1
        res = 1
        #从1开始找到哈希表中第一个没有出现的正整数
        while res in mp: 
            res += 1
        return res
