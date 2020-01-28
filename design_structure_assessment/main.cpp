#include <iostream>
#include "tList.h"

int main() {
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
	system("pause");
	return 0;
}