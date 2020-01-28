#include <iostream>
#include "tList.h"
#include "Table.h"

void DLL() {
	tList<int> myList;

	myList.push_front(40);
	myList.push_front(91);
	myList.push_front(52);
	myList.push_front(12);

	auto iter = myList.begin();

	while (iter != myList.end()) {
		std::cout << *iter << std::endl;
		iter++;
	}
	std::cout << std::endl;

	myList.pop_front();
	myList.pop_back();
	myList.push_back(76);
	myList.push_back(83);
	myList.push_back(106);
	myList.push_back(34);
	myList.remove(91);

	for (auto v : myList) {
		std::cout << v << std::endl;
	}
	std::cout << std::endl;

	myList.resize(9);
	myList.push_front(54);
	myList.push_front(32);
	myList.push_front(21);
	myList.push_back(21);

	for (auto v : myList) {
		std::cout << v << std::endl;
	}
	std::cout << std::endl;
	myList.remove(21);
	myList.remove(0);

	for (auto v : myList) {
		std::cout << v << std::endl;
	}
	std::cout << std::endl << myList.front() << std::endl << myList.back() << std::endl;
	std::cout << std::endl;
	myList.resize(5);

	for (auto v : myList) {
		std::cout << v << std::endl;
	}
	std::cout << std::endl;
	myList.clear();

	if (myList.empty())
		std::cout << "List is now empty" << std::endl;
	for (auto v : myList) {
		std::cout << v << std::endl;
	}
}

void Merge() {
	Table acTable("Assassins.txt");

	vector<Entry> topA = acTable.mostSkilled(10);
	for (int i = 0; i < topA.size(); i++) {
		cout << topA[i].name << "," << topA[i].skillLevel << endl;
	}
	cout << endl;

	acTable.nameMergeSort(topA, 0, topA.size() - 1);
	for (int i = 0; i < topA.size(); i++) {
		cout << topA[i].name << "," << topA[i].skillLevel << endl;
	}
	cout << endl;

	acTable.skillMergeSort(topA, 0, topA.size() - 1);
	for (int i = 0; i < topA.size(); i++) {
		cout << topA[i].name << "," << topA[i].skillLevel << endl;
	}
	cout << endl;

	cout << "---------------------------------------n/" << endl;
	topA = acTable.mostSkilled(6);
	for (int i = 0; i < topA.size(); i++) {
		cout << topA[i].name << "," << topA[i].skillLevel << endl;
	}
	cout << endl;

	acTable.nameMergeSort(topA, 0, topA.size() - 1);
	for (int i = 0; i < topA.size(); i++) {
		cout << topA[i].name << "," << topA[i].skillLevel << endl;
	}
	cout << endl;

	acTable.skillMergeSort(topA, 0, topA.size() - 1);
	for (int i = 0; i < topA.size(); i++) {
		cout << topA[i].name << "," << topA[i].skillLevel << endl;
	}
	cout << endl;
}

size_t basicHash(unsigned char* data, size_t size) {
	size_t hash = 0;
	for (size_t i = 0; i < size; ++i) {
		hash += data[i];
	}
	return hash;
}
size_t hardHash(unsigned char* data, size_t size) {
	size_t hash = 0, x = 0;
	for (size_t i = 0; i < size; ++i) {
		hash = (hash << 4) + data[i];
		if ((x = hash & 0xF0000000L) != 0) {
			hash ^= (x >> 24);
			hash &= ~x;
		}
	}
	return (hash & 0x7FFFFFFF);
}

int main() {
	//DLL();
	cout << "Listn/---------------------------------------------n/" << endl;

	//Merge();
	cout << "Sorting---------------------------------------------n/" << endl;

	cout << "Hashing---------------------------------------------n/" << endl;



	system("pause");
	return 0;
}