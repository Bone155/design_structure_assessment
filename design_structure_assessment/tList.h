#pragma once
template<typename T>
class tList
{
	struct Node
	{
		T data;
		Node * prev;
		Node * next;
	};

	Node * head;
	Node * tail;

public:
	tList() { head = nullptr; }
	tList(const tList& other) {
		head.data = other.head.data;
		tail.data = other.tail.data;
	}
	tList& operator=(const tList &rhs) {
		head.data = rhs.head.data;
		tail.data = rhs.tail.data;
	}
	~tList() { delete head; delete tail; }

	void push_front(const T& val) {
		Node* n;
		n.data = val;
		n.next = head;
		if (head.next == nullptr)
			head.next = n;
		head = n;
	}
	void pop_front() {
		Node* n;
		if (head != nullptr) {
			n = head;

			if (head.next != nullptr) {
				head.next.previous = nullptr;
			}
		}
		head = head.next;

		delete n;
	}
	void push_back(const T& val) {
		Node* n;
		n.data = val;
		n.previous = tail;
		if (tail.previous == nullptr)
			tail.previous = n;
		tail = n;
	}
	void pop_back() {
		Node* n;
		if (tail != nullptr) {
			n = tail;

			if (tail.previous != nullptr) {
				tail.previous.next = nullptr;
			}
		}
		tail = tail.previous;

		delete n;
	}

	T& front() { return head; }
	const T& front() const { return front(); }
	T& back() { return tail; }
	const T& back() const { return back(); }

	void remove(const T& val) {
		Node* n;
		if (head != nullptr) {

		}
		head = head.next;

		delete n;
	}

	bool empty() const {
		if (front() == nullptr && back() == nullptr)
			return true;
		else
			return false;
	}
	void clear() {}
	void resize(size_t newSize) {}

	class iterator
	{
		Node * cur;

	public:
		iterator() {}
		iterator(Node * startNode) { cur = startNode; }

		bool operator==(const iterator& rhs) const {
			if (cur == rhs.cur) {
				return true;
			}
			else {
				return false;
			}
		}
		bool operator!=(const iterator& rhs) const {
			if (cur != rhs.cur) {
				return false;
			}
			else {
				return true;
			}
		}
		T& operator*() const {
			return cur.data;
		}
		iterator& operator++() {}
		iterator operator++(int) {}
		iterator& operator--() {}
		iterator operator--(int) {}
	};

	iterator begin() {}
	const iterator begin() const {}
	iterator end() {}
	const iterator end() const {}
};

