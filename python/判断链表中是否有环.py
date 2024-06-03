from tkinter.tix import ListNoteBook

class Solution:
    def hasCycle(self , head: ListNoteBook) -> bool:
        #先判断链表为空的情况
        if head == None: 
            return False
        #快慢双指针
        fast = head 
        slow = head
        #如果没环快指针会先到链表尾
        while fast != None and fast.next != None: 
            #快指针移动两步
            fast = fast.next.next 
            #慢指针移动一步
            slow = slow.next 
            #相遇则有环
            if fast == slow: 
                return True
        #到末尾则没有环
        return False 
