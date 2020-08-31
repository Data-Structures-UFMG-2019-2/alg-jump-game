#include<iostream>
#include<string>
#include<fstream>
#include<cmath>

#include"../include/game.hpp"

using namespace JumpGame;

Game::Game(std::string input_path){
    int m, n;
    std::ifstream input;
    input.open(input_path);

    input >> m >> n;
    input >> this->players_number;
    this->running_players = this->players_number;

    this->board = new Board(m, n);
    this->players = (Player**) malloc(this->players_number * sizeof(Player*));
    this->order = (int*) malloc(this->players_number * sizeof(int));

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            int jump_value;
            input >> jump_value;
            this->board->set(i, j, jump_value);
        }
    }
    this->board->generate_graph();

    for(int i = 0; i < this->players_number; i++){
        int x, y;
        input >> x >> y;
        this->players[i] = new Player(i, x, y);
        this->board->visit(x, y);
        this->players[i]->find_path(this->board);
        this->order[i] = i;
    }

    input.close();
}

Game::~Game(){
    delete this->board;
    free(this->order);
    for(int i = 0; i < this->players_number; i++){
        delete this->players[i];
    }
    free(this->players);
}

Board* Game::get_board(){
    return this->board;
}

Player** Game::get_players(){
    return this->players;
}

int Game::get_players_number(){
    return this->players_number;
}

int Game::get_rounds(){
    return this->rounds;
}

int Game::run_round(){
    this->rounds++;
    for(int i = 0; i < this->players_number; i++){
        Player* player = this->players[this->order[i]];
        int x = player->get_x();
        int y = player->get_y();
        this->board->visit(x, y);
        if(!player->can_win()){
            continue;
        }
        if(player->get_optimal_path()->empty()){
            // std::cout << "Player " << (char)('A'+player->get_id()) << " can no longer win: no available movements" << std::endl;
            player->set_winable(false);
            this->running_players--;
            continue;
        }
        int* new_position = this->board->node_to_matrix_index(player->get_optimal_path()->top());
        int new_x = new_position[0];
        int new_y = new_position[1];
        // std::cout << "Player " << (char)('A'+player->get_id()) << " goes to [" << new_position[0] << ", " << new_position[1] << "]" << std::endl;
        if(new_x == this->board->get_m() - 1 && new_y == this->board->get_n() - 1){
            free(new_position);
            return player->get_id();
        }

        int jump_size = board->get_map()[x][y];
        player->set_last_jump(jump_size);
        player->set_x(new_x);
        player->set_y(new_y);
        player->get_optimal_path()->pop();

        if(this->board->get_visited()[new_x][new_y] == 1){
            // std::cout << "Player " << (char)('A'+player->get_id()) << " can no longer win: visited jump" << std::endl;
            player->set_winable(false);
            this->running_players--;
            free(new_position);
            continue;
        }
        free(new_position);
    }
    if(this->running_players == 0){
        throw ("SEM VENCEDORES");
    }
    this->set_order();
    return -1;
}

void Game::set_order(){
    this->merge_sort(0, this->players_number - 1);
}

void Game::merge_sort(int left, int right){
    if(left < right){
        int middle = left + ceil((right - left)/2);
        this->merge_sort(left, middle);
        this->merge_sort(middle + 1, right);
        this->merge(left, middle, right);
    }
}

void Game::merge(int left, int middle, int right){
    int i, j, k; 
    int size_left = (middle - left) + 1; 
    int size_right =  (right - middle); 
    int *left_array, *right_array;

    left_array = (int*) malloc(size_left*sizeof(int));
    right_array = (int*) malloc(size_right*sizeof(int)); 
  
    for (i = 0; i < size_left; i++) {
        left_array[i] = this->order[left + i]; 
    }
    for (j = 0; j < size_right; j++){
        right_array[j] = this->order[middle + 1 + j]; 
    }

    i = 0;
    j = 0;
    k = left;
    while (i < size_left && j < size_right) { 
        if (this->players[left_array[i]]->get_last_jump() <= this->players[right_array[j]]->get_last_jump()) { 
            this->order[k] = left_array[i]; 
            i++; 
        } 
        else{
            this->order[k] = right_array[j]; 
            j++; 
        }
        k++; 
    }
    while (i < size_left) { 
        this->order[k] = left_array[i]; 
        i++; 
        k++; 
    }
    while (j < size_right) { 
        this->order[k] = right_array[j]; 
        j++; 
        k++; 
    }
    free(left_array);
    free(right_array);
}