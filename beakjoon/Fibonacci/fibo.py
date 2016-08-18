import sys
rl = lambda: sys.stdin.readline()
	
def main():		
	cnt0 = [1,0]
	cnt1 = [0,1]

	for x in range(2,41):
		cnt0.append(cnt0[x-1]+cnt0[x-2])
		cnt1.append(cnt1[x-1]+cnt1[x-2])
	T = int(rl())
	for i in range(T):
		n = int(rl())
		print "%d %d" % (cnt0[n],cnt1[n])

if __name__ == '__main__':
	main()
