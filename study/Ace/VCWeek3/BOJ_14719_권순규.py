H, W = map(int,input().split())
m = [[0] * W for _ in range(H)]
for x, n in enumerate(list(map(int,input().split()))):
    for y in range(H-1,H-1-n,-1):
        m[y][x]=1

answer = 0
for y in range(H):
    add = False
    tmp = 0
    x = 0
    while x < W:
        if m[y][x] == 1:
            if not add:
                add = True
            else:
                while True:
                    if x < W and m[y][x] == 1:
                        x += 1
                    else:
                        x -= 1
                        break
                answer += tmp
                tmp = 0
        else:
            if add:
                tmp += 1
        x += 1

print(answer)
            
