a=[]
sum=0
n,m=map(int,input().split(" "))
for i in range(n):
  k=int(input())
  a.append(k)
for i in range(n-1,-1,-1):
  sum+=m//a[i]
  m%=a[i]
print(sum)