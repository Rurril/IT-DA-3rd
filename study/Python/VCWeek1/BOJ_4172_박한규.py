import math

x = [1]
for i in range(1, 1000000):
    st = x[int(i - math.sqrt(i))]
    nd = x[int(math.log(i))]
    rd = x[int(i * ((math.sin(i)) ** 2))]
    x.append(st + nd + rd)

while True:
    n = int(input())
    if n == -1:
        break
    else:
        print(x[n]%1000000)


