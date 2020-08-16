#ifndef BOARD_H
#define BOARD_H

#include<string>

#include"./graph.hpp"

namespace JumpGame{

    class Board{
        private:
            int** map;
            int m;
            int n;
            Graph::ListGraph* graph;
        public:
            Board(int m, int n);
            ~Board();
            int get_m();
            int get_n();
            int matrix_index_to_node(int i, int j);
            bool is_valid_index(int x, int y);
            void set(int x, int y, int value);
            void generate_graph();
            void print_map();
            Graph::ListGraph* get_graph();

            static Board* generate_board(std::string input);
    };

}



#endif