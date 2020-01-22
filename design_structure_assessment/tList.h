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
	size_t nodeSize;
public:
	tList() { 
		head = nullptr;
		tail = nullptr;

		head->next = tail;
		head->prev = nullptr;

		tail->next = nullptr;
		tail->prev = head;

		nodeSize = 0;
	}
	tList(const tList& other) {
		head = other.head;
		tail = other.tail;
		size = other.size;
	}
	tList& operator=(const tList &rhs) {
		
		head->data = rhs.head->data;
		head->next = rhs.head->next;
		head->prev = rhs.head->previous;

		tail->data = rhs.tail->data;
		tail->next = rhs.head->next;
		tail->prev = rhs.head->previous;

		nodeSize = rhs.nodeSize;
	}
	~tList() { delete head; delete tail; }

	void push_front(const T& val) {
		Node* n{};
		n->data = val;
		n->next = head;
		if (head->next == nullptr)
			head->next = n;
		head = n;
	}
	void pop_front() {
		Node* n;
		if (head != nullptr) {
			n = head;

			if (head->next != nullptr) {
				head->next->previous = nullptr;
			}
		}
		head = head->next;

		delete n;
	}
	void push_back(const T& val) {
		Node* n;
		n->data = val;
		n->previous = tail;
		if (tail->previous == nullptr)
			tail->previous = n;
		tail = n;
	}
	void pop_back() {
		Node* n;
		if (tail != nullptr) {
			n = tail;

			if (tail->previous != nullptr) {
				tail->previous->next = nullptr;
			}
		}
		tail = tail->previous;

		delete n;
	}

	T& front() { return head; }
	const T& front() const { return front(); }
	T& back() { return tail; }
	const T& back() const { return back(); }

	void remove(const T& val) {
		Node* n = head;
		while (n != nullptr) {
			if (n.data == val) {
				
				if (n == head)
				{
					head = n->next;
					n->next = nullptr;
					delete n;
					n = nullptr;
					break;
				}
				else if (n == tail)
				{
					tail = n->prev;
					tail->next = nullptr;
					delete n;
					break;
				}
				else
				{
					n->prev->next = n->next;
					n->next->prev = n->prev;
					n->prev = nullptr;
					n->next = nullptr;
					delete n;
					break;
				}
			}
		}

	}

	bool empty() const {
		if ((head == tail->previous) && (tail == head->next))
			return true;
		else
			return false;
	}
	void clear() {
		resize(0);
	}
	void resize(size_t newSize) {
		nodeSize = newSize;
	}
	size_t size() const {
		return nodeSize;
	}

	class iterator
	{
		Node * cur;

	public:
		iterator() { cur = nullptr; }
		iterator(Node * startNode) {
			cur = startNode;

		}

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
			return cur->data;
		}
		iterator& operator++() {
			cur = cur->next;
			return this;
		}
		iterator operator++(int) {
			iterator temp(cur);
			++temp.cur;
			return temp;
		}
		iterator& operator--() {
			cur = cur->prev;
			return this;
		}
		iterator operator--(int) {
			iterator temp(cur);
			--temp.cur;
			return temp;
		}
	};

	iterator begin() { return iterator(head); }
	const iterator begin() const { return iterator(head.next); }
	iterator end() { return iterator(tail); }
	const iterator end() const { return iterator(tail.previous); }
};

