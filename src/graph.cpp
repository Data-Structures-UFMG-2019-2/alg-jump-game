#include<stdlib.h>

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

List::LinkedList<int>** ListGraph::get_nodes(){
    return this->nodes;
}

List::LinkedList<int>* ListGraph::get_node(int node){
    return this->nodes[node];
}

