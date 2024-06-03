from typing import List 

class Solution:
    def recursion(self, res:List[List[int]], num:List[int], index:int):
        #分枝进入结尾，找到一种排列
        if index == len(num) - 1:  
            res.append(num.copy())  # 添加当前排列的副本
        else:
            used = set()  # 用于记录已经使用过的元素
            #遍历后续的元素
            for i in range(index, len(num)): 
                if num[i] in used:
                    continue
                used.add(num[i])
                #交换二者
                used.add(num[i])
                temp = num[i]
                num[i] = num[index]
                num[index] = temp
                #继续往后找
                self.recursion(res, num, index + 1) 
                #回溯
                temp = num[i]
                num[i] = num[index]
                num[index] = temp

    def permute(self , num: List[int]) -> List[List[int]]: #表明输入和输出
        #先按字典序排序
        num.sort() 
        res = list(list())
        #递归获取
        self.recursion(res, num, 0) 
        return res

if __name__ == "__main__":
    s = Solution()
    nums = [-1, -2, -1]#重复数字和非重复数字都可以
    result = s.permute(nums)
    print(result) # Output: [[1, 2, 3], [1, 3, 2], [2, 1, 3], [2, 3, 1], [3, 2, 1], [3, 1, 2]]

