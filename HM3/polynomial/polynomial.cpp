#include <iostream>
using namespace std;

//---------------------------------------- Linked list

template<class T>
class llist_node {
public:
    llist_node<T>* next = nullptr;
    T value;
};

template <class T>
class llist {
public:
    int element_count = 0;
    llist_node<T>* start = nullptr;
    llist_node<T>* end = nullptr;

    void insert(const T& New_item);
    void del(int count);
    ~llist();
};

template <class T>
void llist<T>::insert(const T& New_item) {
    element_count++;
    llist_node<T>* A = new llist_node<T>;
    A->value = New_item;
    A->next = nullptr;
    if (start == nullptr) {
        start = A;
        end = A;
    } else {
        end->next = A;
        end = A;
    }
}

template <class T>
void llist<T>::del(int count) {
    if (count >= element_count || count < 0) {
        cout << "link list removal out of range\n";
        return;
    }

    if (count == 0) {
        llist_node<T>* temp = start;
        start = start->next;
        delete temp;
        if (start == nullptr) end = nullptr;
        element_count--;
        return;
    }

    llist_node<T>* current = start;
    for (int i = 0; i < count - 1; ++i) {
        current = current->next;
    }

    llist_node<T>* target = current->next;
    current->next = target->next;
    if (target == end) end = current;
    delete target;
    element_count--;
}

template <class T>
llist<T>::~llist() {
    llist_node<T>* current = start;
    while (current != nullptr) {
        llist_node<T>* next = current->next;
        delete current;
        current = next;
    }
    start = nullptr;
    end = nullptr;
}

//---------------------------------------- Polynomial_seg

class Polynomial_seg {
public:
    int _exp = 0, coef = 0;
};

//---------------------------------------- Polynomial

class Polynomial {
public:
    llist<Polynomial_seg> poly;

    void insert(Polynomial_seg seg, int mode = 1);

    Polynomial operator+(const Polynomial& rhs) const;
    Polynomial operator-(const Polynomial& rhs) const;
    Polynomial operator*(const Polynomial& rhs) const;
};

void Polynomial::insert(Polynomial_seg seg, int mode) {
    if (mode == 0) seg.coef *= -1;

    if (poly.start == nullptr) {
        poly.insert(seg);
        return;
    }

    llist_node<Polynomial_seg>* current = poly.start;
    while (current != nullptr) {
        if (current->value._exp == seg._exp) {
            current->value.coef += seg.coef;
            return;
        }
        current = current->next;
    }
    poly.insert(seg);
}

Polynomial Polynomial::operator+(const Polynomial& rhs) const {
    Polynomial result;
    llist_node<Polynomial_seg>* current = poly.start;

    while (current != nullptr) {
        result.insert(current->value, 1);
        current = current->next;
    }

    current = rhs.poly.start;
    while (current != nullptr) {
        result.insert(current->value, 1);
        current = current->next;
    }

    return result;
}

Polynomial Polynomial::operator-(const Polynomial& rhs) const {
    Polynomial result;
    llist_node<Polynomial_seg>* current = poly.start;

    while (current != nullptr) {
        result.insert(current->value, 1);
        current = current->next;
    }

    current = rhs.poly.start;
    while (current != nullptr) {
        result.insert(current->value, 0); // mode=0 means negate
        current = current->next;
    }

    return result;
}

Polynomial Polynomial::operator*(const Polynomial& rhs) const {
    Polynomial result;
    llist_node<Polynomial_seg>* curR = poly.start;

    while (curR != nullptr) {
        llist_node<Polynomial_seg>* curL = rhs.poly.start;

        while (curL != nullptr) {
            Polynomial_seg temp;
            temp.coef = curR->value.coef * curL->value.coef;
            temp._exp = curR->value._exp + curL->value._exp;
            result.insert(temp);
            curL = curL->next;
        }

        curR = curR->next;
    }

    return result;
}

//---------------------------------------- main

int main() {
}
