import sys, string
	
iter_cnt = 0
iter_sum = [0]*100
round_edge = [0]*100

def iterTime(line,r_pos):
	global iter_cnt,iter_sum
	#merge iter time
	if line.find('Finished iteration') > -1:
		iter_cnt += 1
		i_sec = line[line.find('Finished iteration')+30:].split()
		iter_sum[r_pos] += int(i_sec[0])

def roundNewEdge(line,r_pos):
	if line.find('output.round') > -1:
		r_edge = line[line.find('output.round')+15:].split(',')
		round_edge[r_pos] = int(r_edge[4])

def printInfo(r_pos):
	global iter_sum,round_edge
	i_sum = edgeSum = 0
	for i in range(1,r_pos+1):
		i_sum+=iter_sum[i]
		edgeSum += round_edge[i]
	print "Average iteration time : %d s" % (i_sum/iter_cnt)
	print "Average edges added per round : %d" % (edgeSum/r_pos)
	print "Average edges added per iteration : %d" % (edgeSum/iter_cnt)
#	print iterTime / round	
#	for i in range(1,r_pos+1):
#		print "ROUND #%d time : %d s" % (i, iter_sum[i])

def Round(lines):
	r_pos = 0
	for line in lines:
		#find round num
		if line.find('ROUND NO #') > -1:
			r_pos = int(line[line.find('ROUND NO #')+10:])
		
		iterTime(line,r_pos)
		roundNewEdge(line,r_pos)
	printInfo(r_pos)
	
def GC(lines):
	cnt=0
	totalTime =0
	totalHeap =0
	for line in lines:
		cnt+=1
		if cnt < 4:
			continue
		gc = line.split()
		if len(gc) is 5:
			totalHeap += int(gc[2][gc[2].find('(')+1:gc[2].find(')')-1])
			totalTime += float(gc[3])
		elif len(gc) is 6:
			totalHeap += int(gc[3][gc[3].find('(')+1:gc[3].find(')')-1])
			totalTime += float(gc[4])
	print "GC count : %d " % (cnt - 3)
	print "GC time : %f sec" % totalTime
	print "Consume heap size : %dK" % totalHeap

def main():
	f1 = open(sys.argv[1],"r")
	
	lines = f1.readlines()
	Round(lines)

	f2 = open(sys.argv[2],"r")
	lines = f2.readlines()
	GC(lines)
if __name__ == '__main__':
	main()
