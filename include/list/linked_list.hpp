#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include"./cell.hpp"

#define FRONT 0
#define BACK 1

namespace List{
    template <class T>
    class LinkedList{
        private:
            int size;
            Cell<T>* first;
            Cell<T>* last;
            Cell<T>* from_back(int i);
            Cell<T>* from_front(int i);
        public:
            LinkedList();
            ~LinkedList();
            int length();
            void add(T object);
            void add(T object, int position);
            void insert_after(Cell<T>* cell, T object);
            void insert_before(Cell<T>* cell, T object);
            T get(int i);
            Cell<T>* begin();
            Cell<T>* get_cell(int i);
            void each(void (*callback)(T));
            T remove(int i);
            void remove(Cell<T>* cell);
            void clear();
            void clear(int strategy);
    };
}

#endif