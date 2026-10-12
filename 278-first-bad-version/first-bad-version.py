# The isBadVersion API is already defined for you.
# def isBadVersion(version: int) -> bool:

class Solution:
    def firstBadVersion(self, n: int) -> int:
        # brute force
        # for i in range(1, n+1):
        #     if isBadVersion(i):
        #         return i

        left, right = 1, n
        # when they equal each other that means that you found the answer
        while left < right:
            mid = (left+right) // 2
            if isBadVersion(mid):
                right = mid
            # good version
            else:
                left = mid+1
        # it can be left or right 
        return right

        