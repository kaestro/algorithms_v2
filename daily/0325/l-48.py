from typing import List
import os
import sys

cur = os.path.dirname(__file__)
up = os.path.dirname(cur)
#target = up + "\\freq_methods"

#sys.path.append(target)
sys.path.append(up)

#from printMat import printMat
from freq_methods.printMat import printMat

class Solution:
    # rotate clockwise
    def rotate(self, matrix: List[List[int]]) -> None:
        matrix [:]= matrix[::-1]
        matrix[:] = map(list, zip(*matrix))


    # rotate counter_clockwise
    def rotate_rvs(self, matrix: List[List[int]]) -> None:
        matrix[:] = map(list, zip(*matrix))
        matrix[:] = matrix[::-1]


    def rotate_nozip(self, matrix: List[List[int]]) -> None:
        matrix[:] = [[row[i] for row in matrix[::-1]] for i in range(len(matrix))]


    def dumb_rotate(self, matrix: List[List[int]]) -> None:
        size = len(matrix)
        if size == 0: return

        for step in range(size // 2):
            step_length = size - 2 * step - 1;
            for second in range(step_length):
                temp = matrix[step + second][size - 1 - step]
                matrix[step + second][size - 1 - step] = matrix[step][step + second]
                temp, matrix[size - 1 - step][size - 1 - step - second] = matrix[size - 1 - step][size - 1 - step - second], temp
                temp, matrix[size - 1 - step - second][step] = matrix[size - 1 - step - second][step], temp
                matrix[step][step + second] = temp


if __name__ == "__main__":
    S = Solution()

    input_matrix = [ [1,2,3], [4,5,6], [7,8,9] ]

    S.rotate_nozip(input_matrix)

    printMat(input_matrix)