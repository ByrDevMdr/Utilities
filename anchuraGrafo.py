from collections import deque

def main():
    n, m = map(int, input("Ingrese numeros: ").split())
    grid = []
    for i in range(n):
        line = input().strip()
        if len(line) < m:
            line += ' ' * (m - len(line)) # Se rrellena con espacios si la línea es corta 
        grid.append(list(line))
    
    sx, sy = 0, 0
    ex, ey = n-1, m-1

    dist = [[-1]*m for _ in range(n)]
    q = deque([(sx, sy)])
    dist[sx][sy] = 0

    dirs = [(1,0),(-1,0),(0,1),(0,-1)]
    while q:
        x, y = q.popleft()
        for dx, dy in dirs:
            nx, ny = x+dx, y+dy
            if 0 <= nx < n and 0 <= ny < m and grid[nx][ny] != '#' and dist[nx][ny] == -1:
                dist[nx][ny] = dist[x][y] + 1
                q.append((nx, ny))

    print(dist[ex][ey])

if __name__ == "__main__":
    main()