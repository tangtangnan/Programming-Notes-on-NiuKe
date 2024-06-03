
from typing import List 

class Solution:
    def twoSum(self , numbers: List[int], target: int) -> List[int]:
        res = []
        #创建哈希表,两元组分别表示值、下标
        hash = dict() 
        #在哈希表中查找target-numbers[i]
        for i in range(len(numbers)) :
            temp = target - numbers[i]
            #若是没找到，将此信息计入哈希表
            if temp not in hash: 
                hash[numbers[i]] = i
            else:
                #哈希表中记录的是之前的数字，所以该索引比当前小
                res.append(hash[temp] + 1) 
                res.append(i + 1)
                break
        return res
