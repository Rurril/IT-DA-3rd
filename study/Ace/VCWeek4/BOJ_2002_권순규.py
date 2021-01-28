N = int(input())

answer = 0
IsPassed = dict()
Order = []
pointer = 0
for _ in range(N):
    car = input()
    db[car]=False
    Order.append(car)

for _ in range(N):
    car = input()
    if car != Order[pointer]:
        answer += 1
        db[car] = True
    else:
        pointer += 1
        while pointer < N and IsPassed[Order[pointer]]:
            pointer += 1

print(answer)
