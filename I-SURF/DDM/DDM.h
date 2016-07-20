#ifndef DDM_H
#define DDM_H

//test
//#include "../utilities/globalDefinitions.hpp"
#include <iostream>
#include <fstream>
#include <dirent.h>
#include <cstring>
#include <vector>


class DDM{
private:
	std::vector<std::vector<double> > partitionRate; //for store percentage
	std::vector<std::vector<double> > edgeCnt; //for store number of edges of p and q
	std::vector<int> partitionSize; //for store total edges count
	int f_read(std::string name);
	int numPartition;
	int originNumPartition;
	std::vector<std::string> partitionName;
	void prepare(std::vector<int> val);
	void set();
	int findPart(int num);
public:
	DDM(std::string dirName);
	~DDM();
	long nextPartitionPart();
	void addPartition(std::string fileName);
	void testPrint();
};

#endif
