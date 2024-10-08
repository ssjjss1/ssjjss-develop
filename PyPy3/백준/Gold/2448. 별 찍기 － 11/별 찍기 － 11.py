#function
#!피라미드 그리기
c=[[" "for i in range(7004)]for j in range(7004)]
def f(n, x, y):
      if(n==3):
            c[x][y]="*"
            c[x+1][y-1]="*"
            c[x+1][y+1]="*"
            for i in range(0,3):
                  c[x+2][y-i]="*"
                  c[x+2][y+i]="*"
            return
      f(n//2,x,y)
      f(n//2,x+n//2,y-n//2)
      f(n//2, x+n//2, y+n//2)
n=int(input())
f(n, 0, n-1)
for i in range(0,2*n):
      for j in range(0,2*n):
            print(c[i][j],end="")
      print()