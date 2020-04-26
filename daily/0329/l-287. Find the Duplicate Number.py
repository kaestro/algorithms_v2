class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        walker, runner = nums[0], nums[0]
        while walker != runner:
            walker, runner = nums[walker], nums[runner]
            runner = nums[runner]
        
        duplicate = nums[0]
        while duplicate != walker:
            walker, duplicate = nums[walker], nums[duplicate]
        
        return duplicate
