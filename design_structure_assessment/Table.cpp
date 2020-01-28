#include "Table.h"

vector<Entry> Table::mostSkilled(int topRows)
{
	vector<Entry> temp;
	for (int i = 0; i < topRows; i++) {
		if (i > sVector.size() - 1) {
			break;
		}
		temp.push_back(sVector[i]);
	}
	return temp;
}

void Table::skillMerge(vector<Entry>& array, size_t p, size_t q, size_t r)
{
	size_t leftEnd = q - p + 1;
	size_t rightEnd = r - q;

	vector<Entry> left;	left.resize(leftEnd);
	vector<Entry> right;	right.resize(rightEnd);

	for (int i = 0; i < leftEnd; i++) {
		left[i] = array[p + i];
	}
	for (int j = 0; j < rightEnd; j++) {
		right[j] = array[q + j + 1];
	}

	size_t i = 0;
	size_t j = 0;

	for (int k = p; k <= r; k++) {
		if ((j >= rightEnd) || (i < leftEnd && left[i].skillLevel >= right[j].skillLevel)) {
			array[k] = left[i];
			i++;
		}
		else {
			array[k] = right[j];
			j++;
		}
	}
}

void Table::skillMergeSort(vector<Entry> &array, size_t startIdx, size_t endIdx)
{
	if (startIdx < endIdx) {
		size_t midIdx = (startIdx + endIdx) / 2;
		skillMergeSort(array, startIdx, midIdx);
		skillMergeSort(array, midIdx + 1, endIdx);
		skillMerge(array, startIdx, midIdx, endIdx);
	}
}

void Table::nameMerge(vector<Entry>& array, size_t p, size_t q, size_t r)
{
	size_t leftEnd = q - p + 1;
	size_t rightEnd = r - q;

	vector<Entry> left;	left.resize(leftEnd);
	vector<Entry> right;	right.resize(rightEnd);

	for (int i = 0; i < leftEnd; i++) {
		left[i] = array[p + i];
	}
	for (int j = 0; j < rightEnd; j++) {
		right[j] = array[q + j + 1];
	}

	size_t i = 0;
	size_t j = 0;

	for (int k = p; k <= r; k++) {
		if ((j >= rightEnd) || (i < leftEnd && left[i].name <= right[j].name)) {
			array[k] = left[i];
			i++;
		}
		else {
			array[k] = right[j];
			j++;
		}
	}
}

void Table::nameMergeSort(vector<Entry>& array, size_t startIdx, size_t endIdx)
{
	if (startIdx < endIdx) {
		size_t midIdx = (startIdx + endIdx) / 2;
		nameMergeSort(array, startIdx, midIdx);
		nameMergeSort(array, midIdx + 1, endIdx);
		nameMerge(array, startIdx, midIdx, endIdx);
	}
}

Table::Table()
{
}

Table::Table(string filename)
{
	vector<Entry> temp;
	string tempLevel;
	temp.resize(1);
	std::fstream file;
	file.open(filename, std::ios::in);
	if (!file.is_open())
	{
		std::cerr << "File not found." << endl;
	}
	string text;
	while (std::getline(file, text)) {
		for (int i = 0; i < text.length(); i++) {
			if (text[i] == ',') {
				temp[0].name = text.substr(0, i);
				break;
			}
		}
		
		for (int i = text.length(); i > 0; i--) {
			if (text[i] == ',') {
				tempLevel = text.substr(i + 1, text.length() - i);
				temp[0].skillLevel = std::stoi(tempLevel);
				break;
			}
		}
		sVector.push_back(temp[0]);
	}
	file.close();
	cout << endl;
}

Table::~Table()
{
}
