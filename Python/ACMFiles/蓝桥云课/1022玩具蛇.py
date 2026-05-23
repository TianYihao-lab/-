dx = [-1, 0, 1, 0]
dy = [0, -1, 0, 1]
ans = 0

def dfs(x, y, cnt):
    global ans
    # 标记当前位置
    vis[x][y] = True
    if cnt == 15:  # 已经走了16个格子（0~15共16个）
        ans += 1
        vis[x][y] = False  # 回溯
        return

    # 尝试四个方向
    for i in range(4):
        nx, ny = x + dx[i], y + dy[i]
        if 1 <= nx <= 4 and 1 <= ny <= 4 and not vis[nx][ny]:
            dfs(nx, ny, cnt + 1)

    # 回溯
    vis[x][y] = False

# 枚举所有起点
for i in range(1, 5):
    for j in range(1, 5):
        vis = [[False] * 5 for _ in range(5)]
        dfs(i, j, 0)

print(ans)