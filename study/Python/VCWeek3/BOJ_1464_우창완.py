o = ''
for i in input():
    if len(o) == 0 or o[0] >= i:
        o = i + o
    else:
        o = o + i
    print(o)
print(o)
