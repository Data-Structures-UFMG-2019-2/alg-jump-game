#ifndef QUEUE_H
#define QUEUE_H

#include"./cell.hpp"

namespace Queue {

    template <class T>
    class Queue{
        private:
            int size;
            Cell<T>* first;
            Cell<T>* last;
        public:
            Queue();
            ~Queue();
            int length();
            void add(T object);
            T remove();
            void clear();
            void clear(int strategy);
    };

}

#endif