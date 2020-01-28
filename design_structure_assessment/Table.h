#pragma once
#include "Entry.h"
#include <vector>
#include <fstream>

using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::endl;

class Table
{
public:
	vector<Entry> sVector;
	vector<Entry> mostSkilled(int topRows);
	void skillMerge(vector<Entry> & array, size_t p, size_t q, size_t r);
	void skillMergeSort(vector<Entry> &array, size_t startIdx, size_t endIdsx);
	void nameMerge(vector<Entry> & array, size_t p, size_t q, size_t r);
	void nameMergeSort(vector<Entry> &array, size_t startIdx, size_t endIdx);

	Table();
	Table(string filename);
	~Table();
};

