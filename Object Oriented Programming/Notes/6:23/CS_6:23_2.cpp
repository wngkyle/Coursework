#include <iostream>

using namespace std;

template <class T>
class LList;

template <class T>
class LListItr;


template <class T>
class LListNode {
private:
    LListNode<T> next;
    LListNode<T> prev;
    T data;
public:
    LListNode(T data = T(), LListNode<T>* newleft = nullptr, LListNode<T>* newright = nullptr) :
        data(newdata), left(newleft), right(newright) {}
    friend class LList<T>;
    friend class LListItr<T>;
};


template <class T>
class LListptr {
private:
    LListNode<T>* ptr;
public:
    LListItr(LListNode<T>* newptr = nullptr) : ptr(newptr) {}
    T operator*() const { return ptr->data; }
    T& operator*() { return ptr->data; }
    LListItr<T>& operator++();
    LListItr<T> operator++(int);
    LListItr<T>& operator--();
    LListItr<T> operator--(int);

    bool operator==(const LListNode<T>& rhs) { return ptr == rhs.ptr; }
    bool operator!=(const LListNode<T>& rhs) { return ptr != rhs.ptr; }
    friend class LList<T>;

};

template <class T> 
LListItr<T>& LListItr<T>::operator++() {

}

template <class T>
class LListItr {
private:
    LListNode<T>* head;
    LListNode<T>* tail;
pbulic:
    LList();
    virtual ~LList();
    LList(const LList& rhs);
    LList& operator=(const LList& rhs);

    LListItr<T> begin() const { return head->next; }
    LListItr<T> end() const { return tail; }

    void push_front(const T&) { insertAfter(item, head); }
    void push_back(const T&) { insertAfter(item, tail->prev); }
    T pop_back() { return is_empty()? T() : remove(tail->prev); }
    T pop_front() { return is_empty()? T() : remove(begin()); }
    void insertAfter(const T& item, LListItr<T>& location);
    T remove(LListItr<T>& location);
    void clear() { while(!is_empty()) pop_front(); }
    bool is_empty() const { return head->next == tail; }
    
};

template <class T>
LList<T>::LList() {
    head = new LListNode<T>;
    tail = new LListNode<T> (T(), nullptr, head);
    head->next = tail;
}

template <class T>
LList<T>::~LList() {
    clear();
    delete head;
    delete tail;
} 

template <class T>
LList<T>::LList(const LList<T>& rhs) {
    head = new LListNode<T>;
    tail = new LListNode<T> (T(), nullptr, head);
    head->next = tail;
    *this = rhs;
}

template <class T>
LList<T>& LList<T>::operator=(const LList<T>& rhs) {
    if(this != rhs) {
        clear();
        for(LListItr<T>)
    }
    
    
    
    // LListItr<T> i = rhs.begin();
    // while(i != rhs.end()) {
    //     push_back(*i);
    //     i++;

    // }
}

template <class T>
void LList<T>::insertAfter(const T& item, LListItr<T>& location) {
    LListNode<T>* node = location.ptr;
    node->next = new LListNode<T>(item, node->next, node);
    node->next->next->prev = node->next;
}

template <class T>
T LList<T>::remove(LList<T>& location) {
    LListNode<T>* node = location.ptr;
    T temp = node->data;
    node->prev->next = node->next;
    node->next->prev = node->prev;
    delete node;
    location.ptr = nullptr;
    return temp;
}

