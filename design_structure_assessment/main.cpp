#include <iostream>
#include "tList.h"
#include "Table.h"
#include "tHashmap.h"

void DLL() {
	tList<int> myList;

	myList.push_front(40);
	myList.push_front(91);
	myList.push_front(52);
	myList.push_front(12);

	auto iter = myList.begin();

	while (iter != myList.end()) {
		cout << *iter << endl;
		iter++;
	}
	cout << endl;

	myList.pop_front();
	myList.pop_back();
	myList.push_back(76);
	myList.push_back(83);
	myList.push_back(106);
	myList.push_back(34);
	myList.remove(91);

	for (auto v : myList) {
		cout << v << endl;
	}
	cout << endl;

	myList.resize(9);
	myList.push_front(54);
	myList.push_front(32);
	myList.push_front(21);
	myList.push_back(21);

	for (auto v : myList) {
		cout << v << endl;
	}
	cout << endl;
	myList.remove(21);
	myList.remove(0);

	for (auto v : myList) {
		cout << v << endl;
	}
	cout << endl << myList.front() << endl << myList.back() << endl;
	cout << endl;
	myList.resize(5);

	for (auto v : myList) {
		cout << v << endl;
	}
	cout << endl;
	myList.clear();

	if (myList.empty())
		cout << "List is now empty" << endl;
	for (auto v : myList) {
		cout << v << endl;
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

	cout << "---------------------------------------" << endl;
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

void Hash() {
	tHashmap<string, int> test(8);
	test["Bel"] = 32;
	test["Alex"] = 206;
	test["Dev"] = 89;
	test["Joe"] = 1;
	test["Sam"] = 56;

	cout << test["Alex"] << endl;
	cout << test["Joe"] << endl;
	cout << test["Bel"] << endl;
	cout << test["Sam"] << endl;
	cout << test["Dev"] << endl << endl;

	if (test.count("Alex") == 0)
		cout << "There is no Alex" << endl << endl;
	else
		cout << "There is " << test.count("Alex") << " Alex" << endl << endl;

	cout << test.at("Alex") << endl;
	cout << test.at("Ryan") << endl;
	cout << test.at("Bonesteele") << endl;
	//The last two are supposed to be errors

	test.clear();
	if (test.empty()) {
		cout << "List is now empty" << endl;
	}
}

int main() {
	cout << "List---------------------------------------------" << endl;
	//DLL();

	cout << "Sorting---------------------------------------------" << endl << endl;
	//Merge();

	cout << "Hashing---------------------------------------------" << endl << endl;
	Hash();


	system("pause");
	return 0;
}