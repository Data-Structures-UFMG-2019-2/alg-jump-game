#ifndef CELL_H
#define CELL_H

#define FORWARD 1
#define BACKWARD 0

#define RECURSIVE 1
#define ITERATIVE -1

namespace List {

    template <class T> class LinkedList;
    
    template <class T>
    class Cell{
        private:
            T object;
            Cell* next;
            Cell* prev;
            void cascade_clear(int direction);

            friend class LinkedList<T>;
        public:
            Cell(T object);
            ~Cell();
            Cell<T>* operator++();
            Cell<T>* operator--();
            T get_object();
            Cell<T>* get_next();
            Cell<T>* get_prev();
    };
}

#endif