#include<iostream>
#include<string>
#include<fstream>

#include"../include/game.hpp"

using namespace JumpGame;

Game::Game(std::string input_path){
    int m, n;
    std::ifstream input;
    input.open(input_path);

    input >> m >> n;
    input >> this->players_number;

    this->board = new Board(m, n);
    this->players = (Player**) malloc(this->players_number * sizeof(Player*));

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
        this->players[i] = new Player(x, y);
        this->players[i]->find_path(this->board);
    }

    input.close();
}

Game::~Game(){
}

Board* Game::get_board(){
    return this->board;
}

Player** Game::get_players(){
    return this->players;
}