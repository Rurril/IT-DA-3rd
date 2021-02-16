#병약한 윤호
import sys
from collections import deque

def bfs(arr):
    q = deque()
    word = ['B', 'L', 'D']
    cnt = 0
    #0에 word[i]가 있고 없으면 -1에 word[i]가 있으면 ... 만약 없다면 거기서 끝내기
    #tmp.pop(-1); tmp.pop(0)
    if arr[0] == word[0] :
        q.append([0, 0])
        arr.pop(0)
        cnt += 1
    elif arr[-1] == word[0] :
        q.append([-1, 0])
        arr.pop(-1)
        cnt += 1
    else :
        return cnt

    #...
    while arr and q:
        index, turn = q.popleft()
        print(arr)
        if index == 0 :
            if turn < 2 :
                if arr[0] == word[turn+1] :
                    q.append([0, turn+1])
                    arr.pop(0)
                    cnt += 1
            elif turn == 2 :
                if arr[index] == word[0] :
                    q.append([0, 0])
                    arr.pop(0)
                    cnt += 1 
        elif index == -1 :
            if turn < 2 :
                if arr[index] == word[turn+1] :
                    q.append([-1, turn+1])
                    arr.pop(-1)
                    cnt += 1
            elif turn == 2 :
                if arr[index] == word[0] :
                    q.append([-1, 0])
                    arr.pop(-1)
                    cnt += 1
    
    return cnt

#맨 마지막과 맨 첫번째를 비교
#왔다갔다 하면서 배열을 줄여 나가는게 맞는듯... 0과 -1 만으로
N = int(sys.stdin.readline())
medicine = list(sys.stdin.readline().rstrip('\n'))
tmp = []
#그대로 tmp = medicine 하면 medicine도 같이 줄여나가짐...
for i in range(3*N) :
    tmp.append(medicine[i])
visited = [0]*(3*N)
print(bfs(tmp))