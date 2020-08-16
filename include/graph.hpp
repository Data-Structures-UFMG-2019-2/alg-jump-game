#ifndef GRAPH_H
#define GRAPH_H

#include"./list/linked_list.hpp"

namespace Graph {

    class ListGraph {
        private:
            int size = 1;
            List::LinkedList<int>** nodes;
        public:
            ListGraph();
            ListGraph(int nodes);
            ~ListGraph();
            int get_size();
            bool is_valid_node(int node);
            bool has_edge(int source, int dest);
            void add_edge(int source, int dest);
            void print();
            List::LinkedList<int>** get_nodes();
            List::LinkedList<int>* get_node(int node);
    };
    
}

#endif