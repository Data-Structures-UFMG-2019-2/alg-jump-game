#include<cstdlib>
#include<stack>
#include<queue>

#include"../include/player.hpp"
#include"../include/list/linked_list.hpp"
#include"../include/board.hpp"
#include"../include/graph.hpp"

using namespace JumpGame;

Player::Player(int id, int x, int y){
    this->id = id;
    this->x = x;
    this->y = y;
}

Player::~Player(){
    if(this->optimal_path != nullptr) delete this->optimal_path;
}

int Player::get_id(){
    return this->id;
}

int Player::get_x(){
    return this->x;
}

void Player::set_x(int x){
    this->x = x;
}

int Player::get_y(){
    return this->y;
}

void Player::set_y(int y){
    this->y = y;
}

int Player::get_last_jump(){
    return this->last_jump;
}

void Player::set_last_jump(int jump){
    this->last_jump = jump;
}

bool Player::can_win(){
    return this->winable;
}

void Player::set_winable(bool winable){
    this->winable = winable;
}

void Player::find_path(Board* board){
    int starting_node = board->matrix_index_to_node(this->x, this->y);
    std::queue<int>* queue = new std::queue<int>();
    Graph::ListGraph* graph = board->get_graph();
    int* visited = (int*) calloc(graph->get_size(), sizeof(int));
    int* path = (int*) calloc(graph->get_size(), sizeof(int));

    queue->push(starting_node);
    visited[starting_node] = 1;
    for(int i = 0; i < graph->get_size(); i++){
        path[i] = -1;
    }

    while(!queue->empty()){
        int current_node = queue->front();
        queue->pop();
        List::LinkedList<int>* neighbours = graph->get_node(current_node);

        for(List::Cell<int>* it = neighbours->begin(); it != nullptr; it = it->get_next()){
            int next_node = it->get_object();
            if(visited[next_node] == 0){
                queue->push(next_node);
                visited[next_node] = 1;
                path[next_node] = current_node;
            }
        }
    }
    this->reconstruct_path(board, path);
    delete queue;
    free(visited);
    free(path);
}

void Player::reconstruct_path(Board* board, int* path){
    int start = board->matrix_index_to_node(this->x, this->y);
    int finish = board->matrix_index_to_node(board->get_m() - 1, board->get_n() - 1);
    std::stack<int>* reconstructed_path = new std::stack<int>();

    for(int current = finish; current != -1; current = path[current]){
        reconstructed_path->push(current);
    }

    if(reconstructed_path->top() == start){
        reconstructed_path->pop();
    }
    else{
        delete reconstructed_path;
        reconstructed_path = new std::stack<int>();
    }
    this->optimal_path = reconstructed_path;
}

std::stack<int>* Player::get_optimal_path(){
    return this->optimal_path;
}