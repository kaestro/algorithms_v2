import math
from typing import List

class NumArray:

    def __init__(self, nums: List[int]):
        nums_len = len(nums)
        next_pow2 = 2 ** math.ceil(math.log2(nums_len))
        for i in range(nums_len, next_pow2):
            nums.append(0)

        self.offset = next_pow2
        self.seg_tree = [0] * (self.offset * 2)
        for i in range(self.offset, self.offset * 2):
            self.seg_tree[i] = nums[i - self.offset]

        for i in range(self.offset - 1, 0, -1):
            self.seg_tree[i] = self.seg_tree[i << 1] + self.seg_tree[i << 1 | 1]

        return

    def update(self, i: int, val: int) -> None:
        i += self.offset
        self.seg_tree[i] = val
        while i > 1:
            self.seg_tree[i >> 1] = self.seg_tree[i] + self.seg_tree[i ^ 1]
            i >>= 1

    def sumRange(self, i: int, j: int) -> int:
        res = 0
        i += self.offset
        j += self.offset + 1
        while i < j:
            if (i & 1):
                res += self.seg_tree[i]
                i += 1
            if (j & 1):
                res += self.seg_tree[j - 1]
                j -= 1
            i >>= 1
            j >>= 1
        return res



if __name__ == "__main__":
    nums = [1,3,5]
    numArr = NumArray(nums)
    print(numArr.sumRange(0, 2))
    numArr.update(1, 2)
    print(numArr.sumRange(0,2))