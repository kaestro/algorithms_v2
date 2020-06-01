from typing import List


class Solution:
    def countSquares(self, matrix: List[List[int]]) -> int:
        row_size, col_size = len(matrix), len(matrix[0])
        ans = sum(matrix[0]) + sum(matrix[i][0] for i in range(1, row_size))
        for row in range(1, row_size):
            for col in range(1, col_size):
                if matrix[row][col] == 0:
                    continue
                
                val = min([matrix[row - 1][col - 1], matrix[row - 1][col], matrix[row][col - 1]])
                matrix[row][col] = val + 1
                ans += val + 1
        return ans


if __name__ == "__main__":
    S = Solution()
    matrix = [ [0,1,1,1], [1,1,1,1], [0,1,1,1] ]
    matrix = [ [1,0,1], [1,1,0], [1,1,0] ]
    print(S.countSquares(matrix))