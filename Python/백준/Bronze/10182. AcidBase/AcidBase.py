import math
n = int(input())
for _ in range(n):
    s1, s2 = input().split(" = ")
    m = float(s2)
    if s1 == "H":
        pH = -math.log10(m)
        print(f"{pH:.2f}")
    elif s1 == "OH":
        pOH = -math.log10(m)
        pH = 14 - pOH
        print(f"{pH:.2f}")
