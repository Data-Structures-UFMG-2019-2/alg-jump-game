#include<iostream>
#include<string>
#include<stack>

#include"./include/game.hpp"
#include"./include/list/linked_list.hpp"

int main(int argc, char* argv[]){
    if(argc > 1){
        JumpGame::Game* game;
        try{
            game = new JumpGame::Game(argv[1]);
            game->get_board()->print_map();
            game->get_board()->get_graph()->print();

            // std::stack<int>* optimal_path = game->get_players()[0]->get_optimal_path();
            // std::cout << std::endl;
            game->get_board()->print_visited();
            int winner = game->run_round();
            while(winner == -1){
                game->get_board()->print_visited();
                winner = game->run_round();
            }
            game->get_board()->print_visited();
            std::cout << (char)('A'+winner) << std::endl << game->get_rounds() << std::endl;
            delete game;
        }
        catch(char const* e){
            if(game != nullptr){
                delete game;
            }
            std::cout << e << std::endl;
        }
    }
    return 0;
}