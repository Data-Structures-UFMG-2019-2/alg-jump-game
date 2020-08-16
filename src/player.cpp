#include<cstdlib>

#include"../include/player.hpp"
#include"../include/list/linked_list.hpp"
#include"../include/queue/queue.hpp"
#include"../include/board.hpp"
#include"../include/graph.hpp"

using namespace JumpGame;

Player::Player(int x, int y){
    this->x = x;
    this->y = y;
}

Player::~Player(){
}

int Player::get_x(){
    return this->x;
}

int Player::get_y(){
    return this->y;
}

void Player::find_path(Board* board){
    int starting_node = board->matrix_index_to_node(this->x, this->y);
    Queue::Queue<int>* queue = new Queue::Queue<int>();
    Graph::ListGraph* graph = board->get_graph();
    int* visited = (int*) calloc(graph->get_size(), sizeof(int));
    int* path = (int*) calloc(graph->get_size(), sizeof(int));

    queue->add(starting_node);
    visited[starting_node] = 1;
    for(int i = 0; i < graph->get_size(); i++){
        path[i] = -1;
    }

    while(queue->length() > 0){
        int current_node = queue->remove();
        List::LinkedList<int>* neighbours = graph->get_node(current_node);

        for(List::Cell<int>* it = neighbours->begin(); it != nullptr; it = it->get_next()){
            int next_node = it->get_object();
            if(visited[next_node] == 0){
                queue->add(next_node);
                visited[next_node] = 1;
                path[next_node] = current_node;
            }
        }
    }
    this->reconstruct_path(board, path);
    delete queue;
    delete visited;
    delete path;
}

void Player::reconstruct_path(Board* board, int* path){
    int start = board->matrix_index_to_node(this->x, this->y);
    int finish = board->matrix_index_to_node(board->get_m() - 1, board->get_n() - 1);
    List::LinkedList<int>* reconstructed_path = new List::LinkedList<int>();

    for(int current = finish; current != -1; current = path[current]){
        reconstructed_path->add(current, FRONT);
    }

    if(reconstructed_path->begin()->get_object() == start){
        this->optimal_path = reconstructed_path;
    }
}

List::LinkedList<int>* Player::get_optimal_path(){
    return this->optimal_path;
}