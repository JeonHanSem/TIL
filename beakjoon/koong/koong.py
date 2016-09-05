def koong(num):
	fibo = [1,1,2,4]
	for i in range(4,68):
		fibo.append(fibo[i-1] + fibo[i-2] + fibo[i-3] + fibo[i-4])
	print fibo[num]

def main():
	T = raw_input()
	for i in range(0,int(T)):
		num = raw_input()
		koong(int(num))

if __name__ == '__main__':
	main()
