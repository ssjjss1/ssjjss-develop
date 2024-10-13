d = {}
for _ in range(7):
    semina, num = input().split()
    d[semina] = int(num)
print(max(d, key=d.get))