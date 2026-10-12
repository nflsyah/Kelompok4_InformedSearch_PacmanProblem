import heapq

def heurestic(currPos, goal):
    #Manhattan distance
    return abs(currPos[0] - goal[0]) + abs(currPos[1] - goal[1])

def gbfs(grid, size, start, goal):
    #Directions: Up, Down, Left, Right
    rowMov = [-1, 1, 0, 0]
    colMov = [0, 0, -1, 1]
    
    #Priority queue
    queue = []
    entryCount = 0
    
    initialH = heurestic(start, goal)
    heapq.heappush(queue, (initialH, entryCount, start[0], start[1]))
    
    #Track paths using dictionary
    parentMap = {}
    visited = set()
    visited.add(start)
    
    found = False
    
    while queue:
        _, _, currRow, currCol = heapq.heappop(queue)
        currPos = (currRow, currCol)
        
        if currPos == goal:
            found = True
            break            
        for i in range(4):
            nextRow = currRow + rowMov[i]
            nextCol = currCol + colMov[i]
            nextPos = (nextRow, nextCol)
            
            #Check boundary and wall
            if 0 <= nextRow < size and 0 <= nextCol < size:
                if grid[nextRow][nextCol] != '#' and nextPos not in visited:
                    visited.add(nextPos)
                    parentMap[nextPos] = currPos
                    entryCount += 1
                    hval = heurestic(nextPos, goal)
                    heapq.heappush(queue, (hval, entryCount, nextRow, nextCol))
    
    #Reconstruct path from goal to start
    if not found:
        return []
        
    path = []
    curr = goal
    while curr in parentMap:
        path.append(curr)
        curr = parentMap[curr]
    path.append(start)
    path.reverse()
    
    return path

#MAIN LOGIC
size = int(input().strip())

grid = []
start = None
goal = None

for row in range(size):
    rowInput = input().strip().split()
    grid.append(rowInput)
    for col in range(size):
        if rowInput[col] == 'S' or rowInput[col] == 's':
            start = (row, col)
        elif rowInput[col] == 'G' or rowInput[col] == 'g':
            goal = (row, col)

result = gbfs(grid, size, start, goal)

#Output path
if result:
    cost = 0
    for pos in result[1:]:
        cell_value = grid[pos[0]][pos[1]]
        if cell_value.isdigit():
            cost += int(cell_value)

    print("Visited path:")
    for pos in result:
        print(pos)
    print("Path cost:", cost)
else:
    print("No path found")