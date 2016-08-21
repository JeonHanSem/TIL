import sys, string
	
iter_cnt = 0
io_cnt = 0
iter_sum = [0]*100
round_edge = [0]*100
round_time = [0]*100
io_time = [0]*100

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

def r_Time(r_str1,r_str2,r_pos,flag):
	global round_time
	
	time = r_str1.split(':')
	hour1 = time[0]
	min1 = time[1]
	sec1 = time[2]
	time = r_str2.split(':')
	hour2 = time[0]
	min2 = time[1]
	sec2 = time[2]

	total = 0
	if int(hour1) < int(hour2):
		total += (int(hour1)+12-int(hour2)) * 3600
	else:
		total += (int(hour1)-int(hour2)) * 3600
	if int(min1) < int(min2):
		total += (int(min1)+60-int(min2)) * 60 - 3600
	else:
		total += (int(min1)-int(min2)) * 60
	if int(sec1) < int(sec2):
		total += int(sec1)+60-int(sec2) - 60
	else:
		total += int(sec1)-int(sec2)

	if flag is 1:
		round_time[r_pos-1] += total
	else:
		io_time[r_pos] += total

def printInfo(r_pos):
	global iter_sum,round_edge
	i_sum = edgeSum = roundSum = ioSum = 0
	for i in range(1,r_pos+1):
		i_sum+=iter_sum[i]
		edgeSum += round_edge[i]
		roundSum += round_time[i]
		ioSum += io_time[i]
	print "Average Round time : %d sec" % (roundSum/r_pos)
	print "Average iteration time : %d sec" % (i_sum/iter_cnt)
	print "Average edges added per round : %d" % (edgeSum/r_pos)
	print "Average edges added per iteration : %d" % (edgeSum/iter_cnt)
	print "Average IO time : %d sec" % (ioSum/io_cnt)

def Round(lines):
	r_pos = 0
	global io_cnt #distinct io
	io_flag = 0
	for line in lines:
		#find round num
		if line.find('ROUND NO #') > -1:
			r_pos = int(line[line.find('ROUND NO #')+10:])
			r_str1 = line.split()
			if r_pos > 1:
				r_Time(r_str1[1], r_str2[1],r_pos,1)
			r_str2 = r_str1
		#calc io time
		if line.find('output.IO') > -1:
			if io_flag is 0:
				io_str1 = line.split()
			io_cnt+=1
			io_flag+=1
		else:
			if io_flag > 0:
				io_str2 = line.split()
				r_Time(io_str2[1],io_str1[1],r_pos,2)
			io_flag = 0

		iterTime(line,r_pos)
		roundNewEdge(line,r_pos)
	r_str1 = line.split()
	r_Time(r_str1[1],r_str2[1],r_pos+1,1)
	printInfo(r_pos)
def GC(lines):
	cnt=0
	totalTime =0
	maxHeap=0
	for line in lines:
		cnt+=1
		if cnt < 4:
			continue
		gc = line.split()
		if len(gc) is 5:
			maxHeap = maxHeap if maxHeap > int(gc[2][gc[2].find('(')+1:gc[2].find(')')-1]) else int(gc[2][gc[2].find('(')+1:gc[2].find(')')-1])

			totalTime += float(gc[3])
		elif len(gc) is 6:
			maxHeap = maxHeap if maxHeap > int(gc[3][gc[3].find('(')+1:gc[3].find(')')-1]) else int(gc[3][gc[3].find('(')+1:gc[3].find(')')-1])
			totalTime += float(gc[4])
	print "GC count : %d " % (cnt - 3)
	print "GC time : %f sec" % totalTime
	print "Max consume heap size : %dK" % maxHeap

def main():
	f1 = open(sys.argv[1],"r")
	
	lines = f1.readlines()
	Round(lines)

	f2 = open(sys.argv[2],"r")
	lines = f2.readlines()
	GC(lines)

if __name__ == '__main__':
	main()
