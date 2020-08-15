#ifndef BOARD_H
#define BOARD_H

#include<string>

#include"./graph.hpp"

class Board{
    private:
        int** map;
        int m;
        int n;
        Graph::ListGraph* graph;
        void generate_graph();
    public:
        Board(int m, int n);
        ~Board();
        int matrix_index_to_node(int i, int j);
        bool is_valid_index(int x, int y);
        void set(int x, int y, int value);
        void print_map();
        Graph::ListGraph* get_graph();

        static Board* generate_board(std::string input);
};


#endif