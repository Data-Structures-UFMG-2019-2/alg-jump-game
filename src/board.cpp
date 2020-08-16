#include<cstdlib>
#include<iostream>
#include<fstream>

#include"../include/board.hpp"

using namespace JumpGame;

Board::Board(int m, int n){
    this->m = m;
    this->n = n;
    this->map = (int**) malloc(m * sizeof(int*));
    this->visited = (int**) malloc(m * sizeof(int*));
    for(int i = 0; i < this->m; i++){
        this->map[i] = (int*) calloc(n, sizeof(int));
        this->visited[i] = (int*) calloc(n, sizeof(int));
    }
}

Board::~Board(){
    for(int i = 0; i < this->m; i++){
        free(this->map[i]);
        free(this->visited[i]);
    }
    free(this->map);
    free(this->visited);
    if(this->graph != nullptr) delete this->graph;
}

int** Board::get_map(){
    return this->map;
}

int** Board::get_visited(){
    return this->visited;
}

int Board::get_m(){
    return this->m;
}

int Board::get_n(){
    return this->n;
}

int Board::matrix_index_to_node(int i, int j){
    return (this->n * i) + j;
}

int* Board::node_to_matrix_index(int node){
    int* index = (int*) malloc(2 * sizeof(int));
    index[1] = node % this->n;
    index[0] = (node - index[1])/this->n;
    return index;
}

bool Board::is_valid_index(int x, int y){
    return ((x >= 0 && x < this->m) && (y >= 0 && y < this->n));
}

void Board::visit(int x, int y){
    this->visited[x][y] = 1;
}

void Board::set(int x, int y, int value){
    if(is_valid_index(x, y)){
        this->map[x][y] = value;
    }
    else{
        throw("Index out of bounds");
    }
}

void Board::print_map(){
    std::cout << "Map: " << std::endl;
    for(int i = 0; i < this->m; i++){
        for(int j = 0; j < this->n; j++){
            if(j == 0){
                std::cout << "| ";
            }
            std::cout << this->map[i][j] << " ";
            if(j == this->n-1){
                std::cout << "|";
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void Board::print_visited(){
    std::cout << std::endl << "Visited: " << std::endl;
    for(int i = 0; i < this->m; i++){
        for(int j = 0; j < this->n; j++){
            if(j == 0){
                std::cout << "| ";
            }
            std::cout << this->visited[i][j] << " ";
            if(j == this->n-1){
                std::cout << "|";
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void Board::generate_graph(){
    Graph::ListGraph* graph = new Graph::ListGraph(this->m * this-> n);
    for(int i = 0; i < this->m; i++){
        for(int j = 0; j < this->n; j++){
            int node = this->matrix_index_to_node(i, j);
            int jump_distance = this->map[i][j];

            if(jump_distance != 0){
                if(jump_distance <= i){ // Jump up
                    graph->add_edge(node, this->matrix_index_to_node(i - jump_distance, j));
                }
                if(i + jump_distance < m){ // Jump down
                    graph->add_edge(node, this->matrix_index_to_node(i + jump_distance, j));
                }
                if(jump_distance <= j){ // Jump left
                    graph->add_edge(node, this->matrix_index_to_node(i, j - jump_distance));
                }
                if(j + jump_distance < n){ // Jump right
                    graph->add_edge(node, this->matrix_index_to_node(i, j + jump_distance));
                }
            }
        }
    }
    this->graph = graph;
}

Graph::ListGraph* Board::get_graph(){
    return this->graph;
}