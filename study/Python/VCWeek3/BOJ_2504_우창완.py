bracket=str(input())
answer=0
open_bracket=['(', '[']
close_bracket=[ ')', ']']
check=list()
def check_bracket(bracket):
	for i in bracket:
		if i in open_bracket:
			check.append(bracket[i])
		elif i in close_bracket:
			if not check:
				print(0)
				quit()
			else:
				if i==')':
					if check[-1]=='(': check.pop()
					else:
						print(0)
						quit()
				elif i==']':
					if check[-1]=='[': check.pop()
					else:
						print(0)
						quit()

def solve(bracket):
	cacul=list()
	for i in bracket:
		if i in open_bracket:
			open_bracket.append(i)
			cacul.append(0)



if __name__=="main":
	bracket=str(input())
	check_bracket(bracket)
	check.clear
	solve(bracket)
	
	

print(answer)


