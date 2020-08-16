#include<string>
#include<sstream>
#include<iostream>

#include"../../include/queue/queue.hpp"

template<class T>
Queue::Queue<T>::Queue(){
    this->size = 0;
    this->first = nullptr;
    this->last = nullptr;
}

template<class T>
Queue::Queue<T>::~Queue(){

}

template<class T>
int Queue::Queue<T>::length(){
    return this->size;
}

template<class T>
void Queue::Queue<T>::add(T object){
    Cell<T>* cell = new Cell<T>(object);

    if(this->size == 0){
        this->first = cell;
        this->last = cell;
    }
    else{
        cell->prev = this->last;
        this->last->next = cell;
        this->last = cell;
    }
    ++this->size;
}

template<class T>
T Queue::Queue<T>::remove(){
    Cell<T>* cell = nullptr;
    T object;
    if(this->size <= 0){
        throw("Empty queue");
    }
    else {
        cell = this->first;
        this->first = cell->next;
        if(size == 1){
            this->last = nullptr;
        }
    }
    --this->size;
    object = cell->object;
    delete cell;
    return object;
}

template<class T>
void Queue::Queue<T>::clear(){
    if(this->size > 0){
        this->first->cascade_clear(FORWARD);
        delete this->first;
        this->first = nullptr;
        this->last = nullptr;
        this->size = 0;
    }
}

template<class T>
void Queue::Queue<T>::clear(int strategy){
    if(strategy == ITERATIVE){
        while(this->size > 0){
            this->remove();
        }
    }
    else if(strategy == RECURSIVE){
        if(this->size > 0){
            this->first->cascade_clear(FORWARD);
            delete this->first;
            this->first = nullptr;
            this->last = nullptr;
            this->size = 0;
        }
    }
}

template class Queue::Queue<int>;