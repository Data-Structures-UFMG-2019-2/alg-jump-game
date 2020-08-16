#include<iostream>
#include<string>

#include"./include/game.hpp"

int main(){
    try{
        JumpGame::Game* game = new JumpGame::Game("./input/03.in");
        game->get_board()->print_map();
        game->get_board()->get_graph()->print();
    }
    catch(char const* e){
        std::cout << e;
    }
    return 0;
}