from collections import deque

graph = []

dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]

result = 0


def bfs(a, b, x):
    global result

    queue = deque()
    queue.append((a, b))

    pang = deque()
    pang.append((a, b))

    count = 1

    while queue:
        x, y = queue.popleft()

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if nx < 0 or nx > 11 or ny < 0 or ny > 5:
                continue
            if graph[nx][ny] == x:
                queue.append((nx, ny))
                pang.append((nx, ny))
                count += 1

    if count >= 4:
        result += 1

        for x, y in pang:
            graph[x][y] = "."

def gravity():
    for i in range(10, -1, -1):
        for j in range(6):
            if graph[i][j]


for i in range(12):
    graph.append(list(input()))

while True:
    chk = 0
    for i in range(12):
        for j in range(6):
            bfs(i, j)

