#pragma once
#include <limits>
#include <cassert>
#include <string>
#include <iostream>
#define NDEBUG

template<typename K, typename V>
class tHashmap
{
	V* data;
	size_t size;
	bool* isActive;

	template<typename T>
	size_t hash(const T& val) {
		T::please_specialize_this_template_for_your_type;
	}

	template<>
	size_t hash<int>(const int& val) {
		return val * 2654435761 % std::numeric_limits<size_t>::max();
	}

	template<>
	size_t hash<std::string>(const std::string& val) {
		size_t hash = 0, x = 0;
		for (size_t i = 0; i < val.length(); i++) {
			hash = (hash << 4) + val[i];
			if ((x = hash & 0xF0000000L) != 0) {
				hash ^= (x >> 24);
				hash &= ~x;
			}

		}
		return (hash & 0x7FFFFFFF);
	}

public:
	tHashmap(size_t newSize) {
		size = newSize;
		data = new V[newSize];
		isActive = new bool[newSize];
		for (size_t i = 0; i < newSize; i++) {
			isActive[i] = false;
		}
	}
	~tHashmap() { delete data; delete isActive; }

	V& operator[] (const K& key) {
		auto hashedKey = hash<K>(key) % size;
		if (!isActive[hashedKey]) {
			V * tmp = new V();
			data[hashedKey] = *tmp;
		}
		isActive[hashedKey] = true;
		return data[hashedKey];
	}

	const V& operator[] (const K& key) const {
		auto hashedKey = hash<K>(key) % size;
		if (!isActive[hashedKey]) {
			V * tmp = new V();
			data[hashedKey] = *tmp;
		}
		isActive[hashedKey] = true;
		return data[hashedKey];
	}

	V& at(const K& key) {
		auto hashedKey = hash<K>(key) % size;
		assert(isActive[hashedKey]);
		return data[hashedKey];
	}

	size_t count(const K& key) {
		size_t counter = 0;
		auto hashedKey = hash<K>(key) % size;
		for (size_t i = 0; i < Size(); i++) {
			if (data[i] == data[hashedKey])
				counter++;
		}
		return counter;
	}

	void clear() {
		resize(0);
	}
	size_t Size() const {
		return size;
	}
	bool empty() const {
		if (Size() == 0)
			return true;
		else
			return false;
	}

	void resize(size_t newSize) {
		size = newSize;
	}
};