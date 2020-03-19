from typing import List

class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
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
    
    def pythonicRotate(self, matrix: List[List[int]]) -> None:
        matrix[:] = zip(*matrix[::-1])
    
    # remove the tuple format

    def completeRotate(self, matrix: List[List[int]]) -> None:
        matrix[:] = map(list, zip(*matrix[::-1]))
    
    def woZipRotate(self, matrix: List[List[int]]) -> None:
        matrix[:] = [[row[i] for row in matrix[::-1]] for i in range(len(matrix))]


if __name__ == "__main__":
    matrix = [
            [1,2,3],
            [4,5,6],
            [7,8,9] ]
    matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
    #Solution().pythonicRotate(matrix)
    #Solution().completeRotate(matrix)
    Solution().woZipRotate(matrix)
    print(matrix)