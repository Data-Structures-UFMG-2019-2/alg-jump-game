#ifndef QUEUE_CELL_H
#define QUEUE_CELL_H

#define FORWARD 1
#define BACKWARD 0

#define RECURSIVE 1
#define ITERATIVE -1

namespace Queue {

    template <class T> class Queue;
    
    template <class T>
    class Cell{
        private:
            T object;
            Cell* next;
            Cell* prev;
            void cascade_clear(int direction);

            friend class Queue<T>;
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