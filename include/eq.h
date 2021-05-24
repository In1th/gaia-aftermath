#ifndef EQ_H

#define EQ_H

#include <vector>
#include <array>
#include <string>

#include "item.h"
#include "stackable.h"
#include "nonstackable.h"

template<typename T> class Stack {

    private:

        std::vector<T> stack;
        
    public:

        int size();
        void push(T);
        T at(int);
        void remove(int);
        void insert(T, int);
        void swap(int, int);


};

template class Stack<item_ptr>;

template<typename T, int LIMIT> class Limited_Stack :public Stack<T> {

    private:

        std::array<T,LIMIT> stack;

    public:

        void push(T);
        T at(int);
        T remove(int);
        void insert(T, int);
        void replace(T, T);

};

void show(Stack<item_ptr> s);
void inspect(Stack<item_ptr> s, int index);
void i_throw(Stack<item_ptr> &s, int index);
void add(Stack<item_ptr> &s);

int search(std::string phrase);

#endif