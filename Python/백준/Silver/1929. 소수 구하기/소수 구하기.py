import math
n,m=map(int,input().split(" "))
for i in range(n,m+1):
  flag=True
  for j in range(2,int(math.sqrt(i))+1):
    if(i%j==0):
      flag=False
      break
  if(flag==True and i!=1):
    print(i)