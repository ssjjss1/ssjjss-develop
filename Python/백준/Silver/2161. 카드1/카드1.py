n = int(input())
a = []

card = [i for i in range(1, n + 1)]

while len(card) != 1:
    a.append(card.pop(0)) 
    card.append(card.pop(0)) 

for j in a:
    print(j, end=' ')

print(card[0])