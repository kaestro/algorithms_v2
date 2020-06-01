from typing import List

dr = [-1, 0, 1, 0]
dc = [0, 1, 0, -1]

class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, newColor: int) -> List[List[int]]:
        que, firstColor, row_size, col_size = [(sr, sc)], image[sr][sc], len(image), len(image[0])
        image[sr][sc] = newColor
        visited = set()
        visited.add((sr, sc))

        def out_boundary(r: int, c:int)->bool:
            return r < 0 or r >= row_size or c < 0 or c >= col_size

        while que:
            next_que = []

            for row, col in que:
                for i in range(4):
                    nr, nc = row + dr[i], col + dc[i]
                    if (nr, nc) in visited: continue
                    if out_boundary(nr, nc): continue
                    if image[nr][nc] != firstColor: continue
                    image[nr][nc] = newColor
                    visited.add((nr, nc))
                    next_que.append((nr, nc))
            que = next_que
        return image


if __name__ == "__main__":
    image = [[1,1,1],[1,1,0],[1,0,1]]
    sr, sc, newColor = 1,1,2
    s = Solution()
    print(s.floodFill(image, sr, sc, newColor))