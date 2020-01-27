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
	tList() { 
		head = new Node();
		tail = new Node();
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
		Node* n = new Node();
		n->data = val;
		n->next = head;
		if (head->next == nullptr)
			head->next = n;
		head = n;
	}
	void pop_front() {
		Node* n = new Node();
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
		Node* n = new Node();
		n->data = val;
		n->prev = tail;
		if (tail->prev == nullptr)
			tail->prev = n;
		tail = n;
	}
	void pop_back() {
		Node* n = new Node();
		if (tail != nullptr) {
			n = tail;

			if (tail->prev != nullptr) {
				tail->prev->next = nullptr;
			}
		}
		tail = tail->prev;

		delete n;
	}

	T& front() { return head->data; }
	const T& front() const { return head->data; }
	T& back() { return tail->data; }
	const T& back() const { return tail->data; }

	void remove(const T& val) {
		Node* n = head;
		while (n != nullptr) {
			if (n.data == val) {
				
				if (n == head)
				{
					head = n->next;
					n->next = nullptr;
					n = nullptr;
					delete n;
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
		if ((head == tail->prev) && (tail == head->next))
			return true;
		else
			return false;
	}
	void clear() {
		
	}
	void resize(size_t newSize) {
		size_t size;
		Node* n = new Node();
		n->prev = tail;


		if (tail->next == nullptr)
			push_back();
		tail = n;

		/*if (> newSize) {

		}

		for (size_t i = 0; i < newSize; i++) {

		}*/

		delete n;
	}

	class iterator
	{
		Node * cur;

	public:
		iterator() { cur = new Node(); }
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
			if (cur != nullptr) {
				cur = cur->prev;
			}
			return *this;
		}
		iterator operator--(int) {
			if (cur != nullptr) {
				cur = cur->prev;
			}
			return *this;
		}
	};

	iterator begin() { return iterator(head); }
	const iterator begin() const { return iterator(head); }
	iterator end() { return iterator(nullptr); }
	const iterator end() const { return iterator(nullptr); }
};

