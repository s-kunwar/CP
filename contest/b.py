import sys

input = sys.stdin.readline

t = int(input())

for _ in range(t):
    n, m = map(int, input().split())

    deg = [0] * (n + 1)

    for _ in range(m):
        u, v = map(int, input().split())
        deg[u] += 1
        deg[v] += 1

    x = sum(d > 1 for d in deg) - 1
    y = m // x - 1

    print(x, y)
