#pragma once
template<typename T>
class tList
{
	struct Node
	{
		T data;
		Node * prev;
		Node * next;

		Node() { prev = next = nullptr; }
		Node(const T& val) { prev = next = nullptr; data = val; }
	};

	Node * head;
	Node * tail;
	
public:
	tList() { 
		head = nullptr;
		tail = nullptr;
	}
	tList(const tList& other) {
		head->data = other.head->data;
		head->next = other.head->next;
		head->prev = other.head->prev;

		tail->data = other.tail->data;
		tail->next = other.head->next;
		tail->prev = other.head->prev;
	}
	tList& operator=(const tList &rhs) {
		head = rhs.head;
		tail = rhs.tail;
	}
	~tList() { delete head; delete tail; }

	void push_front(const T& val) {
		Node* n = new Node(val);
		Node* oldHead = head;
		n->next = head;
		if (oldHead != nullptr)
			oldHead->prev = n;
		if (tail == nullptr)
			tail = n;
		head = n;
	}
	void pop_front() {
		Node* n = new Node();
		if (head != nullptr) {
			n = head;

			if (head->next != nullptr) {
				head->next->prev = nullptr;
			}
		}
		head = head->next;

		delete n;
	}
	void push_back(const T& val) {
		Node* n = new Node(val);
		Node* oldTail = tail;
		n->prev = tail;
		if (oldTail != nullptr)
			oldTail->next = n;
		if (head == nullptr)
			head = n;
		tail = n;
	}
	void pop_back() {
		if (tail != nullptr) {
			auto n = tail;
			tail = tail->prev;
			if (tail != nullptr) {
				tail->next = nullptr;
			}
		}

	}

	T& front() { return head->data; }
	const T& front() const { return head->data; }
	T& back() { return tail->data; }
	const T& back() const { return tail->data; }

	void remove(const T& val) {
		Node* n = head;
		while (n != nullptr)
		{
			if (n->data == val) {
				if (n == head)
				{
					head = n->next;
				}
				else if (n == tail)
				{
					tail = n->prev;
					tail->next = nullptr;
				}
				else {
					n->prev->next = n->next;
					n->next->prev = n->prev;
				}

			}
			n = n->next;
		}
		
		delete n;
	}

	bool empty() const {
		if ((head == nullptr) && (tail == nullptr))
			return true;
		else
			return false;
	}
	void clear() {
		head = new Node();
		tail = new Node();
		head = nullptr;
		tail = nullptr;
	}
	void resize(size_t newSize) {
		size_t size = 0;
		Node* n = head;
		while (n != nullptr)
		{
			n = n->next;
			size++;
		}
		if (size > newSize) {
			for (int i = 0; i < size - newSize; i++) {
				pop_back();
			}
		}
		else if (size < newSize) {
			for (int i = size; i < newSize; i++) {
				n = new Node(0);
				push_back((T)n->data);
			}
		}

		delete n;
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
			return !(*this == rhs);
		}
		T& operator*() {
			return cur->data;
		}
		const T& operator*() const {
			return cur->data;
		}
		iterator& operator++() {
			
			cur = cur->next;
			return *this;
		}
		iterator operator++(int) {
			
			cur = cur->next;
			return *this;
		}
		iterator& operator--() {
			cur = cur->prev;
			return *this;
		}
		iterator operator--(int) {
			cur = cur->prev;
			return *this;
		}
	};

	iterator begin() { return iterator(head); }
	const iterator begin() const { return iterator(head); }
	iterator end() { return iterator(nullptr); }
	const iterator end() const { return iterator(nullptr); }
};
