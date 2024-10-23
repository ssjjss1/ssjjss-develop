n, m = map(int, input().split(" "))
d = [i for i in range(1, n + 1)]

for _ in range(m):
    x, y = map(int, input().split(" "))
    d[x-1:y] = d[x-1:y][::-1]
for i in d:
    print(i, end=" ")