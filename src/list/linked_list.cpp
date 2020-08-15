#include<string>
#include<sstream>
#include<iostream>

#include"../../include/list/linked_list.hpp"

template<class T>
List::LinkedList<T>::LinkedList(){
    this->size = 0;
    this->first = nullptr;
    this->last = nullptr;
}

template<class T>
List::LinkedList<T>::~LinkedList(){
    this->clear(ITERATIVE);
}

template<class T>
int List::LinkedList<T>::length(){
    return this->size;
}

template<class T>
void List::LinkedList<T>::add(T object){
    List::Cell<T>* cell = new List::Cell<T>(object);

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
void List::LinkedList<T>::insert_after(List::Cell<T>* cell, T object){
    List::Cell<T>* new_cell = new List::Cell<T>(object);
    if(cell == nullptr){ // Insert at the beginning of the list when cell == NULL
        if(this->size == 0){
            this->first = cell;
            this->last = cell;
        }
        else{
            new_cell->next = this->first;
            this->first->prev = new_cell;
            this->first = new_cell;
        }
    }
    else{
        new_cell->prev = cell;
        new_cell->next = cell->next;
        cell->next = new_cell;
        if(cell == this->last){
            this->last = new_cell;
        }
        else{
            new_cell->next->prev = new_cell;
        }
    }
    ++this->size;
}

template<class T>
void List::LinkedList<T>::insert_before(List::Cell<T>* cell, T object){
    List::Cell<T>* new_cell = new List::Cell<T>(object);
    if(cell == nullptr){ // Insert at the end of the list when cell == NULL
        if(this->size == 0){
            this->first = cell;
            this->last = cell;
        }
        else{
            new_cell->prev = this->last;
            this->last->next = new_cell;
            this->last = new_cell;
        }
    }
    else{
        new_cell->next = cell;
        new_cell->prev = cell->prev;
        cell->prev = new_cell;
        if(cell == this->first){
            this->first = new_cell;
        }
        else{
            new_cell->prev->next = new_cell;
        }
    }
    ++this->size;
}

template<class T>
T List::LinkedList<T>::get(int i){
    List::Cell<T>* cell;
    if(i >= this->size || i < -this->size){
        throw("Object not found");
    }
    else{
        if(i < 0){ // negative indexes get cells from the back of the list
            i = this->size + i;
        }
        if(i <= (float)this->size/2.0){ // if the cell is closer to the front
            cell = this->from_front(i);
        }
        else{ // if the cell is closer to the back
            cell = this->from_back((this->size-i)-1);
        }
        return cell->get_object();
    }
}

template<class T>
List::Cell<T>* List::LinkedList<T>::begin(){
    return this->first;
}

template<class T>
List::Cell<T>* List::LinkedList<T>::get_cell(int i){ // negative values for i return cells from the back of the list
    List::Cell<T>* cell;
    if(i >= this->size || i < -this->size){
        return nullptr;
    }
    else{
        if(i < 0){
            i = this->size + i;
        }
        if(i <= (float)this->size/2.0){
            cell = this->from_front(i);
        }
        else{
            cell = this->from_back((this->size-i)-1);
        }
        return cell;
    }
}

template<class T>
List::Cell<T>* List::LinkedList<T>::from_back(int i){ // return i-th cell (starting at the end)
    int cell_i = 0;
    for (List::Cell<T>* cell = this->last; cell != nullptr; cell = cell->prev, cell_i++){
        if(cell_i == i){
            return cell;
        }
    }
    return nullptr;
}

template<class T>
List::Cell<T>* List::LinkedList<T>::from_front(int i){ // return i-th cell (starting at the beginning)
    int cell_i = 0;
    for (List::Cell<T>* cell = this->first; cell != nullptr; cell = cell->next, cell_i++){
        if(cell_i == i){
            return cell;
        }
    }
    return nullptr;
}

template<class T>
void List::LinkedList<T>::each(void (*callback)(T)){
    for(List::Cell<T>* it = this->begin(); it != nullptr; it = it->get_next()){
        callback(it->object);
    }
}

template<class T>
T List::LinkedList<T>::remove(int i){ // negative values for i remove itens from the back of the list
    List::Cell<T>* cell = nullptr;
    T object;
    if(i >= this->size || i < -this->size){
        throw("Object not found");
    }
    else if(this->size == 1){
        cell = this->first;
        this->first = nullptr;
        this->last = nullptr;
    }
    else if(i == 0 || i == -this->size){ // cases where the element is first in the list
        cell = this->first;
        cell->next->prev = nullptr;
        this->first = cell->next;
    }
    else if(i == this->size-1 || i == -1){ // cases where the element is last in the list
        cell = this->last;
        cell->prev->next = nullptr;
        this->last = cell->prev;
    }
    else{
        cell = this->get_cell(i);
        cell->prev->next = cell->next;
        cell->next->prev = cell->prev;
    }
    --this->size;
    object = cell->object;
    delete cell;
    return object;
}

template<class T>
void List::LinkedList<T>::remove(Cell<T>* cell){
    if(this->size == 0){
        return;
    }
    else if(this->size == 1){
        this->first = nullptr;
        this->last = nullptr;
    }
    else if(cell == this->first){ // case where the element is first on the list
        cell->next->prev = nullptr;
        this->first = cell->next;
    }
    else if(cell == this->last){ // case where the element is last on the list
        cell->prev->next = nullptr;
        this->last = cell->prev;
    }
    else{
        cell->prev->next = cell->next;
        cell->next->prev = cell->prev;
    }
    --this->size;
}

template<class T>
void List::LinkedList<T>::clear(){
    if(this->size > 0){
        this->first->cascade_clear(FORWARD);
        delete this->first;
        this->first = nullptr;
        this->last = nullptr;
        this->size = 0;
    }
}

template<class T>
void List::LinkedList<T>::clear(int strategy){
    if(strategy == ITERATIVE){
        while(this->size > 0){
            this->remove(0);
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

template class List::LinkedList<int>;