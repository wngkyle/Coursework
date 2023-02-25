#include <iostream>
#include <list>

using namespace std;

template <class T>
class LList;

template <class T>
class LListItr;

template <class T>
class LListNode {
private:
	LListNode<T>* next;
	LListNode<T>* prev;
	T data;
public:
	LListNode(T newdata = T(), LListNode<T>* newnext = nullptr, LListNode<T>* newprev = nullptr) :
		data(newdata), next(newnext), prev(newprev) {}
	friend class LList<T>;
	friend class LListItr<T>;
};

template <class T>
class LListItr {
private:
	LListNode<T>* ptr;
public:
	LListItr(LListNode<T>* newptr = nullptr) :ptr(newptr) {}
	T operator*() const { return ptr->data; }
	T& operator*() { return ptr->data; }
	LListItr<T>& operator++();
	LListItr<T> operator++(int);
	LListItr<T>& operator--();
	LListItr<T> operator--(int);

	bool operator==(const LListItr<T>& rhs) { return ptr == rhs.ptr;}
	bool operator!=(const LListItr<T>& rhs) { return ptr != rhs.ptr; }
	friend class LList<T>;
};
template <class T>
LListItr<T>& LListItr<T>::operator++() {
	if (ptr->next != nullptr) {
		ptr = ptr->next;
	}
	return *this;
}
template <class T>
LListItr<T>& LListItr<T>::operator--() {
	if (ptr->prev != nullptr) {
		ptr = ptr->prev;
	}
	return *this;
}
template <class T>
LListItr<T> LListItr<T>::operator++(int) {
	LListItr<T> temp = *this;
	if (ptr->next != nullptr) {
		ptr = ptr->next;
	}
	return temp;
}
template <class T>
LListItr<T> LListItr<T>::operator--(int) {
	LListItr<T> temp = *this;
	if (ptr->prev != nullptr) {
		ptr = ptr->prev;
	}
	return temp;
}

template <class T>
class LList {
private:
	LListNode<T>* head;
	LListNode<T>* tail;
public:
	LList& operator=(const LList& rhs);

	LList();
	virtual ~LList();
	LList(const LList& rhs);
	LListItr<T> begin() const { return head->next; }
	LListItr<T> end() const { return tail; }
	bool isEmpty() const { return head->next == tail; }
	void push_front(const T& item) { insertAfter(item, head); }
	void push_back(const T& item) { insertAfter(item, tail->prev); }
	void insertAfter(const T& item, LListItr<T> location);
	T remove(LListItr<T> location);
	T pop_back() { return isEmpty() ? T() : remove(tail->prev); }
	T pop_front() { return isEmpty() ? T() : remove(begin()); }
	void clear() { while (!isEmpty()) pop_front(); }
};
template <class T>
LList<T>& LList<T>::operator=(const LList<T>& rhs) {
	if (this != &rhs) {
		clear();
		for (LListItr<T> i = rhs.begin(); i != rhs.end(); i++)
			push_back(*i);
	}
	return *this;
}
template <class T>
LList<T>::LList(const LList<T>& rhs) {
	head = new LListNode<T>;
	tail = new LListNode<T>(T(), nullptr, head);
	head->next = tail;
	*this = rhs;
}
template <class T>
T LList<T>::remove(LListItr<T> location) {
	LListNode<T>* node = location.ptr;
	T temp = node->data;
	node->prev->next = node->next;
	node->next->prev = node->prev;
	delete node;
	location.ptr = nullptr;
	return temp;
}
template <class T>
void LList<T>::insertAfter(const T& item, LListItr<T> location) {
	LListNode<T>* node = location.ptr;
	node->next = new LListNode<T>(item, node->next, node);
	node->next->next->prev = node->next;
}

template <class T>
LList<T>::~LList() {
	clear();
	delete head;
	delete tail;
}

template <class T>
LList<T>::LList() {
	head = new LListNode<T>;
	tail = new LListNode<T>(T(), nullptr, head);
	head->next = tail;
}


int main() {
	list<int> l1;
	for (int i = 0; i < 10; i++)
		l1.push_front(i);
	list<int> l2 = l1;
	for (list<int>::iterator i = l2.begin(); i != l2.end(); i++)
		cout << *i << endl;
}