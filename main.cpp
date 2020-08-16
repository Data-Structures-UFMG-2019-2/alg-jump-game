#include<iostream>
#include<string>

#include"./include/game.hpp"
#include"./include/list/linked_list.hpp"

int main(){
    try{
        JumpGame::Game* game = new JumpGame::Game("./input/03.in");
        game->get_board()->print_map();
        game->get_board()->get_graph()->print();
        List::LinkedList<int>* optimal_path = game->get_players()[0]->get_optimal_path();
        std::cout << std::endl;
        for(List::Cell<int>* it = optimal_path->begin(); it != nullptr; it = it->get_next()){
            std::cout << it->get_object() << " -> ";
        }
        std::cout << "\b\b\b\b" << std::endl;
    }
    catch(char const* e){
        std::cout << e;
    }
    return 0;
}