n = int(input())
v = [0] * 26

for _ in range(n):
    s = input()
    cnt = 1
    for j in range(len(s) - 1, -1, -1):
        v[ord(s[j]) - ord('A')] += cnt
        cnt *= 10

v1 = [value for value in v if value > 0]
v1.sort(reverse=True)

t = 9
sum_val = 0
for value in v1:
    sum_val += value * t
    t -= 1

print(sum_val)
