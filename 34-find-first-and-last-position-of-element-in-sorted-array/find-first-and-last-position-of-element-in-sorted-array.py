class Solution:
    def searchRange(self, nums: list[int], target: int) -> list[int]:
        low, high = 0, len(nums) - 1
        # i want 2 sep searches. low and high are ints, so each call
        # gets its own copy and the first call doesn't affect the second
        first = self.findFirstIndex(nums, low, high, target)
        second = self.findLastIndex(nums, low, high, target)
        return [first, second]

    def findFirstIndex(self, nums, low, high, target):
        # stays -1 if target is never found
        res = -1
        while low <= high:
            mid = (low + high) // 2
            if nums[mid] == target:
                # record this matcb
                res = mid
                high = mid - 1  # keep looking LEFT for an earlier one (diff from the last index func)
            elif nums[mid] > target:
                high = mid - 1 #target is in left half
            else:
                low = mid + 1 # target is in right half
        return res

    def findLastIndex(self, nums, low, high, target):
        res = -1
        while low <= high:
            mid = (low + high) // 2
            if nums[mid] == target:
                # record match
                res = mid
                low = mid + 1 # keep looking RIGHT for a later one (diff form the first indeX)
            elif nums[mid] > target:
                high = mid - 1
            else:
                low = mid + 1
        return res