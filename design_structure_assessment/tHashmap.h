#pragma once
template<typename K, typename V>
class tHashmap
{
	V* data;
	size_t size;

	size_t Hash(const K &key) {
		size_t hash = 0;
		for (size_t i = 0; i < size; ++i) {
			hash += data[i];
		}
		return hash;
	}

public:
	tHashmap(size_t newSize) : size(newSize), data(new V[newSize]) {}
	~tHashmap() {}

	V& operator[] (const K& key) {
		auto hashedKey = Hash(key) % size;
		return data[hashedKey];
	}
	const V& operator[] (const K& key) const {
		auto hashedKey = Hash(key) % size;
		return data[hashedKey];
	}

	V& at(const K& key) {
		auto hashedKey = Hash(key) % size;
		return data[hashedKey];
	}

	size_t count(const K& key) {

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

