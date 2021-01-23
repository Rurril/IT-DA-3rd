
arr= list(map(str,input().split(":")))

count=0
#빈칸이 아닌 수만큼 count++
for i in range(len(arr)):
	if arr[i]!='': count+=1

for i in range(8):
	if arr[i]=='':
		for j in range(8-count):
			arr.insert(i, '0'*4)
		while '' in arr:
			arr.remove('')
	else:
		if len(arr[i]) != 4:
			arr[i] = '0'*(4-len(arr[i]))+arr[i]
#:로 나누기 
print(':'.join(arr))
	
