#include<cstdlib>
#include<iostream>

#include"../include/graph.hpp"

using namespace Graph;

ListGraph::ListGraph(){
    this->nodes = (List::LinkedList<int>**) malloc(sizeof(List::LinkedList<int>*));
    this->nodes[0] = new List::LinkedList<int>();
}

ListGraph::ListGraph(int nodes){
    this->size = nodes;
    this->nodes = (List::LinkedList<int>**) malloc(this->size * sizeof(List::LinkedList<int>*));
    for(int i =0; i < this->size; i++){
        this->nodes[i] = new List::LinkedList<int>();
    }
}

ListGraph::~ListGraph(){
    for(int i =0; i < this->size; i++){
        delete this->nodes[i];
    }
    delete this->nodes;
}

int ListGraph::get_size(){
    return this->size;
}

bool ListGraph::is_valid_node(int node){
    return (node >= 0 && node < this->size);
}

bool ListGraph::has_edge(int source, int dest){
    if(!this->is_valid_node(source) || !this->is_valid_node(dest)){
        throw("Invalid node");
    }
    List::LinkedList<int>* source_node = this->nodes[source];
    for(List::Cell<int>* it = source_node->begin(); it != nullptr; it = it->get_next()){
        if(it->get_object() == dest) return true;
    }
    return false;
}

void ListGraph::add_edge(int source, int dest){
    if(!this->is_valid_node(source) || !this->is_valid_node(dest)){
        throw("Invalid node");
    }
    List::LinkedList<int>* source_node = this->nodes[source];
    if(!this->has_edge(source, dest)){
        source_node->add(dest);
    }
}

void ListGraph::print(){
    std::cout << "Graph:" << std::endl;
    for(int i = 0; i < this->size; i++){
        List::LinkedList<int>* node = this->nodes[i];
        std::cout << i << ": [";
        for(List::Cell<int>* it = node->begin(); it != nullptr; it = it->get_next()){
            std::cout << it->get_object() << ", ";
        }
        if(node->length() > 0){
            std::cout << "\b\b";
        }
        std::cout << "]" << std::endl;
    }
}

List::LinkedList<int>** ListGraph::get_nodes(){
    return this->nodes;
}

List::LinkedList<int>* ListGraph::get_node(int node){
    return this->nodes[node];
}

