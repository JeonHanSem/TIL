def classify(a,b):
	if a <= b:
		return 1
	elif b < a:
		return 2
#	elif c < a and c < b:
#		return 3

def make(num):
	ma = [0,0,1,1]
	
	for i in range(4,num+1):
		if (i%3) == 0:
			ma.append(ma[i/3]+1)
		elif (i%2) == 0:
			if classify(ma[i/2],ma[i-1]) == 1:
				ma.append(ma[i/2]+1)
			else:
				ma.append(ma[i-1]+1)
		else:
			ma.append(ma[i-1]+1)
	print ma[num]

def main():
	num = raw_input()
	make(int(num))

if __name__ == '__main__':
	main()
