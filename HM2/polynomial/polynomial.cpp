#include <stdio.h>

template<class T> //----link list code start
class llist_node{
    public:
        llist_node<T>* next;
        T value;
}

template <class T>
class llist{
    public:
        int element_count=0;
        llist_node<T>* start = nullptr, end = nullptr;
    
        void insert(const T& New_item);
        void del(int count);
}

template <class T>
void llist<T>::del(int count){
    
    if(count > element_count || count < 0){
        cout  << "link list removal out of range";
        return;
    }
    
    if (count == 0) {
        
        llist_node<T>* temp = start;
        start = start->next;
        delete temp;
        
        if (start == nullptr) end = nullptr;
        return;
    }

    llist_node<T>* current = start;
    for (int i = 0; i < count - 1; ++i) {
        current = current->next;
    }

    llist_node<T>* target = current->next;
    current->next = target->next;

    if (target == end) {
        end = current;
    }

    delete target;
    element_count--;
}


template <class T>
void llist<T>::insert(const T& New_item) // 接收的 T 會需要 = 的 operator overload
    element_count++;
    llist_node<T>* A = new llist_node<T>;
    A.value = T;
    if(start == nullptr){
        start = A;
        end = A;
    }else{
        end->next = A;
        end = A;
    }
}

//----------------------link list code start



template <class T>
class Polynomial_seg{ // 做 = 的 operator overload
    public:
    int _exp, coef;
}

class Polynomial{
    public:
    
}

int main()
{
    printf("Hello World");

    return 0;
}
