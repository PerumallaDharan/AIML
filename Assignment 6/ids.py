def is_valid(x, y, maze):
    if 0 <= x < len(maze) and 0 <= y < len(maze[0]) and maze[x][y] == 0:
        return True
    return False

def dfs(maze, start, end, depth):
    if start == end:
        return [start]

    if depth <= 0:
        return None

    x, y = start
    directions = [(0, 1), (0, -1), (1, 0), (-1, 0)]

    for dx, dy in directions:
        new_x, new_y = x + dx, y + dy
        if is_valid(new_x, new_y, maze):
            path = dfs(maze, (new_x, new_y), end, depth - 1)
            if path is not None:
                return [start] + path

    return None

def ids(maze, start, end):
    max_depth = 11  

    for depth in range(max_depth):
        path = dfs(maze, start, end, depth)
        if path is not None:
            return path

    return None

def main():
    board = [
        [0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0],
        [0, 0, 1, 0, 0, 0, 0],
        [0, 0, 1, 0, 0, 0, 0],
        [0, 0, 1, 0, 0, 0, 0],
        [0, 0, 1, 0, 0, 0, 0],
        [0, 0, 1, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0],
    ]

    start = (3, 0)
    end = (5, 4)

    path = ids(board, start, end)
    if not path:
        print("No path found.")
    else:
        print("Path found:", path)

if __name__ == '__main__':
    main()