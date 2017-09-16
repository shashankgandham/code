
t = int(input())

for i in range(0, t):
	s = input()
	l = s.split(' ')
	if(len(l) == 1):
		k = l[0].title()
	elif(len(l) == 2):
		k = (l[0].upper())[0] + '. ' + l[1].title()
	else:
		k = (l[0].upper())[0] + '. ' + (l[1].upper())[0] + '. ' + l[2].title()
	print(k)
