Pillar, Beam = 0, 1
Install, Destroy = 1, 0
n = 0

def is_valid_Pillar(buildings, x_pos, y_pos) -> bool:
    answer = False
    if y_pos == 0: answer = True
    elif Pillar in buildings[x_pos][y_pos - 1]: answer = True
    elif x_pos > 0 and Beam in buildings[x_pos - 1][y_pos]: answer = True
    elif x_pos < n and Beam in buildings[x_pos][y_pos]: answer = True
    return answer

def is_valid_Beam(buildings, x_pos, y_pos) -> bool:
    answer = False
    if Pillar in buildings[x_pos][y_pos - 1]: answer = True
    elif Pillar in buildings[x_pos + 1][y_pos - 1]: answer = True
    elif x_pos > 0 and x_pos < n - 1:
        if Beam in buildings[x_pos - 1][y_pos] and Beam in buildings[x_pos + 1][y_pos]:
            answer = True

    return answer

def solution(building_size : int, orders : [[]]) -> [[]]:
    global n
    n = building_size
    result = []

    buildings = {i : {} for i in range(0, n + 1)}
    for row in buildings.keys():
        buildings[row] = {j : [] for j in range(0, n + 1)}
    
    for order in orders:
        x_pos, y_pos, struct, operation = order[:]
        if operation is Install:
            installable = False
            if struct is Pillar:
                if y_pos == 0: installable = True # Pillar bottom
                else:
                    if Pillar in buildings[x_pos][y_pos - 1]: installable = True #Pillar under
                    elif x_pos > 0 and Beam in buildings[x_pos - 1][y_pos]: installable = True #Beam left down
                    elif x_pos < n and Beam in buildings[x_pos + 1][y_pos]: installable = True #Beam right down

            elif struct is Beam:
                # If pillar is underneath
                if Pillar in buildings[x_pos][y_pos - 1] or Pillar in buildings[x_pos + 1][y_pos - 1]: installable = True
                elif x_pos == 0 or x_pos == n - 1: installable = False
                elif Beam in buildings[x_pos - 1][y_pos] and Beam in buildings[x_pos + 1][y_pos]: installable = True

        
            if installable:
                buildings[x_pos][y_pos].append(struct)
        elif operation is Destroy:
            destroyable = True
            buildings[x_pos][y_pos].remove(struct)
            if struct is Pillar:
                if y_pos < n - 1 and Pillar in buildings[x_pos][y_pos + 1]:
                    if not is_valid_Pillar(buildings, x_pos, y_pos + 1):
                        destroyable = False

                if destroyable and x_pos > 0 and Beam in buildings[x_pos - 1][y_pos + 1]:
                    if not is_valid_Beam(buildings, x_pos - 1, y_pos + 1):
                        destroyable = False
                
                if destroyable and x_pos < n and Beam in buildings[x_pos][y_pos + 1]:
                    if not is_valid_Beam(buildings, x_pos, y_pos + 1):
                        destroyable = False

            elif struct is Beam:
                if y_pos < n:
                    if Pillar in buildings[x_pos][y_pos]:
                        if not is_valid_Pillar(buildings, x_pos, y_pos):
                            destroyable = False
                    if destroyable and Pillar in buildings[x_pos + 1][y_pos]:
                        if not is_valid_Pillar(buildings, x_pos + 1, y_pos):
                            destroyable = False
                
                if destroyable and x_pos > 0 and Beam in buildings[x_pos - 1][y_pos]:
                    if not is_valid_Beam(buildings, x_pos - 1, y_pos):
                        destroyable = False
                
                if destroyable and x_pos < n - 1 and Beam in buildings[x_pos + 1][y_pos]:
                    if not is_valid_Beam(buildings, x_pos + 1, y_pos):
                        destroyable = False

            if not destroyable:
                buildings[x_pos][y_pos].append(struct)
    
    for x_pos, building in sorted(buildings.items(), key = lambda x : x[0]):
        for y_pos, structs in sorted(building.items(), key = lambda x : x[0]):
            for struct in structs:
                result.append([x_pos, y_pos, struct])

    return result

if __name__ == "__main__":
    build_frame = [[1,0,0,1],[1,1,1,1],[2,1,0,1],[2,2,1,1],[5,0,0,1],[5,1,0,1],[4,2,1,1],[3,2,1,1]]	
    build_frame = [[0, 0, 0, 1], [2, 0, 0, 1], [4, 0, 0, 1], [0, 1, 1, 1], [1, 1, 1, 1], [2, 1, 1, 1], [3, 1, 1, 1], [2, 0, 0, 0], [1, 1, 1, 0], [2, 2, 0, 1]]
    print(solution(5, build_frame))
