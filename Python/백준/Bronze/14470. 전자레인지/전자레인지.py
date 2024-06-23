import sys
a=int(sys.stdin.readline())
b=int(sys.stdin.readline())
c=int(sys.stdin.readline())
d=int(sys.stdin.readline())
e=int(sys.stdin.readline())
if a<0:
    num=-a*c+d+b*e
else:
    num=(b-a)*e
print(num)