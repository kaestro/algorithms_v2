from typing import List

class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        postRequisites = [[] for _ in range(numCourses)]
        numPrerequisites = [0 for _ in range(numCourses)]
        for course, prerequisite in prerequisites:
            postRequisites[prerequisite].append(course)
            numPrerequisites[course] += 1
        
        order = [course for course in range(numCourses) if numPrerequisites[course] == 0]
        for course in order:
            for nextCourse in postRequisites[course]:
                numPrerequisites[nextCourse] -= 1
                if numPrerequisites[nextCourse] == 0:
                    order.append(nextCourse)
        
        if len(order) == numCourses:
            ans = order 
        else:
            ans = []
        return ans


if __name__ == "__main__":
    S = Solution()

    numCourses, prerequisites = 2, [[1,0]]
    numCourses, prerequisites = 4, [[1,0],[2,0],[3,1],[3,2]]
    print(S.findOrder(numCourses, prerequisites))
