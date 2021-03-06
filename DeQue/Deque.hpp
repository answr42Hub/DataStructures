#include "SLNode.hpp"
#include <cstdlib>

template <typename T>
class Deque {
private:
    SLNode<T>* last;
    size_t count;

public:
    Deque() {
        last = nullptr;
        count = 0;
    }

    ~Deque() {
        while(last)
            pop_front();
    }

    void push_front(T data) {
        if(last)
            last->next = new SLNode<T>(data, last->next);
        else {
            last->next = last = new SLNode<T>(data);
        }
        
        count++;
    }

    void push_back(T data) {
        if(last)
            last = last->next = new SLNode<T>(data, last->next);
        else
            last->next = last = new SLNode<T>(data);

        count++;
    }

    void pop_front() {

        if(last) {
            if(count > 1) {
                SLNode<T>* first = last->next;
                last->next = first->next;
                delete first;
            }
            else {
                delete last;
                last = nullptr;
            }
            count--;
        }
    }
    
    void pop_back() {
        if(last) {
            if(count > 1) {
                SLNode<T>* runner = last;
                while (runner->next != last)
                    last = last->next;
                last->next = runner->next;
                delete runner;
            }
            else {
                delete last;
                last = nullptr;
            }
            count--;
        }
    }

    T front() {
        if(last)
            return last->next->data;
    }

    T back() {
        if(last)
            return last->data;
    }

    size_t size() {
        return count;
    }
};