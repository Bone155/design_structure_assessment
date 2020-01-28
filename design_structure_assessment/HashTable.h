#pragma once
template<typename KeyType, typename T>
class HashTable {
public:
	HashTable(size_t newSize) : size(newSize), data(new T[newSize]) {}
	~HashTable() { delete[] data; }
	T& operator [] (const KeyType& key) {
		auto hashedKey = Hash(key) % size;
		return data[hashedKey];
	}
	const T& operator [] (const KeyType& key) const {
		auto hashedKey = Hash(key) % size;
		return data[hashedKey];
	}
private:
	// ideally this would be a std::function
	// specified as a template parameter
	size_t Hash(const KeyType& key) {

	}
	T* data;
	size_t size;
};
