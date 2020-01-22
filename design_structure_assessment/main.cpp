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

	system("pause");
	return 0;
}